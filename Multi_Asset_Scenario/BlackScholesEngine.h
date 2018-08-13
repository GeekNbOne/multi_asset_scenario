/*
 * BlackScholesEngine.h
 *
 *  Created on: Aug 12, 2018
 *      Author: LucBerthiaume
 */

#ifndef BLACKSCHOLESENGINE_H_
#define BLACKSCHOLESENGINE_H_

#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/tools/roots.hpp>
#include <boost/math/tools/tuple.hpp>


using namespace std;
using boost::math::normal;


class BlackScholesEngine {
private:
	float d1(float,float,float,float,float) const;
	float d2(float,float,float,float,float) const;

	normal s;
	float tolerance = float(0.0001);
	float initVolatility;

public:
	BlackScholesEngine(float initVolatility = 0.2);
	virtual ~BlackScholesEngine();

	float price(float,float,float,float,float,bool) const;
	float delta(float,float,float,float,float,bool) const;
	float vega(float,float,float,float,float) const;
	float implied_volatility(float,float,float,float,float,bool) const;

};

#endif /* BLACKSCHOLESENGINE_H_ */
