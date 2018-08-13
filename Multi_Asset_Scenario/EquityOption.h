/*
 * EquityOption.h
 *
 *  Created on: Aug 11, 2018
 *      Author: LucBerthiaume
 */

#ifndef EQUITYOPTION_H_
#define EQUITYOPTION_H_

#include "Instrument.h"
#include "Maturity.h"
#include "factor/SingleFactor.h"
#include "factor/DiscountFactor.h"
#include "factor/VolatilityFactor.h"

class EquityOption: public Instrument {
	float strike;
	Maturity* maturity;
	SingleFactor* equityPrice;
	DiscountFactor* discountFactor;
	VolatilityFactor* volatilityFactor;

public:
	EquityOption(float, Maturity*, SingleFactor*, DiscountFactor*, VolatilityFactor*);
	virtual ~EquityOption();
};

#endif /* EQUITYOPTION_H_ */
