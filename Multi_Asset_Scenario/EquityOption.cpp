/*
 * EquityOption.cpp
 *
 *  Created on: Aug 11, 2018
 *      Author: LucBerthiaume
 */

#include "EquityOption.h"

EquityOption::EquityOption(
		float strike,
		Maturity* maturity,
		SingleFactor* equityPrice,
		DiscountFactor* discountFactor,
		VolatilityFactor* volatilityFactor)
: strike(strike),
  maturity(maturity),
  equityPrice(equityPrice),
  discountFactor(discountFactor),
  volatilityFactor(volatilityFactor)
{
	// TODO Auto-generated constructor stub

}

EquityOption::~EquityOption() {
	// TODO Auto-generated destructor stub
}

