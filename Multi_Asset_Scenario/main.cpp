/*
 * main.cpp
 *
 *  Created on: Aug 10, 2018
 *      Author: LucBerthiaume
 */


#include <iostream>
#include "BlackScholesEngine.h"
using namespace std;

int main(void){


	BlackScholesEngine bls;

	cout << bls.price(100,100,0.02,1,0.2,true) << endl;
	cout << bls.price(100,100,0.02,1,0.2,false) << endl;

	cout << bls.delta(100,100,0.02,1,0.2,true) << endl;
	cout << bls.delta(100,100,0.02,1,0.2,false) << endl;

	cout << bls.implied_volatility(8.91604,100.0,100.0,0.02,1,true) <<endl;
	return 0;
}

