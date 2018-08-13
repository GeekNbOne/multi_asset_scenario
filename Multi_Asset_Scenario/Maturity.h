/*
 * Maturity.h
 *
 *  Created on: Aug 11, 2018
 *      Author: LucBerthiaume
 */

#ifndef MATURITY_H_
#define MATURITY_H_

#include "SimulationContext.h"


class Maturity {
public:
	Maturity();
	virtual ~Maturity();

	float virtual timeToExpiry(SimulationContext const &) const = 0;
};

#endif /* MATURITY_H_ */
