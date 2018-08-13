/*
 * BlackScholesEngine.cpp
 *
 *  Created on: Aug 12, 2018
 *      Author: LucBerthiaume
 */

#include "BlackScholesEngine.h"

BlackScholesEngine::BlackScholesEngine(float initVolatility): initVolatility(initVolatility) {
	// TODO Auto-generated constructor stub

}

BlackScholesEngine::~BlackScholesEngine() {
	// TODO Auto-generated destructor stub
}

float BlackScholesEngine::d1(float S, float K, float r, float t, float sigma) const{
	return (log(S/K) + (sigma * sigma *0.5 +  r  ) * t) / (sigma * sqrt(t));
}

float BlackScholesEngine::d2(float S, float K, float r, float t, float sigma) const{
	return (log(S/K) + (r - sigma * sigma *0.5 ) * t) / (sigma * sqrt(t));
}

float BlackScholesEngine::price(float S, float K, float r, float t, float sigma, bool isCall) const{
	int w = isCall ? 1 : -1;
	float d1_ = d1(S,K,r,t,sigma);
	float d2_ = d2(S,K,r,t,sigma);

	return w * (S * cdf(s,d1_ * w) - K * exp(-r * t) * cdf(s,d2_ * w));
}

float BlackScholesEngine::delta(float S, float K, float r, float t, float sigma, bool isCall) const{
	int w = isCall ? 1 : -1;
	return w * cdf(s,d1(S,K,r,t,sigma) * w);
}

float BlackScholesEngine::vega(float S, float K, float r, float t, float sigma) const {
	return S * pdf(s,d1(S,K,r,t,sigma) * sqrt(t));
}

float BlackScholesEngine::implied_volatility(float price,float S,float K, float r, float t, bool isCall) const{

	struct impvol_functor{
		impvol_functor(float const& price, float S, float K, float r, float t, bool isCall): price(price),S(S),K(K),r(r),t(t), isCall(isCall){}
		boost::math::tuple<float,float> operator()(float const& sigma){
			return boost::math::make_tuple(bls.price(S,K,r,t,sigma,isCall) - price,bls.vega(S,K,r,t,sigma));
		}
	private:
			float price;
			float S;
			float K;
			float r;
			float t;
			bool isCall;
			BlackScholesEngine bls;
	};

	float min = float(0.00000000001);
	float max = 400.0;
	float guess = this->initVolatility;
	int digits = std::numeric_limits<float>::digits;

	return boost::math::tools::newton_raphson_iterate(impvol_functor(price,S,K,r,t,isCall),guess,min,max,digits);
}




