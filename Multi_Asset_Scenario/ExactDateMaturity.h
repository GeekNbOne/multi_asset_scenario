/*
 * ExactDateMaturity.h
 *
 *  Created on: Aug 11, 2018
 *      Author: LucBerthiaume
 */

#ifndef EXACTDATEMATURITY_H_
#define EXACTDATEMATURITY_H_

#include "Maturity.h"
#include "SimulationContext.h"

#include <boost/date_time/gregorian/gregorian.hpp>


using namespace boost::gregorian;

class ExactDateMaturity: public Maturity {
private:
	date maturityDate;
public:
	ExactDateMaturity();
	ExactDateMaturity(date);
	virtual ~ExactDateMaturity();

	float timeToExpiry(SimulationContext const &) const;

};

#endif /* EXACTDATEMATURITY_H_ */
