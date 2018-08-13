/*
 * ExactDateMaturity.cpp
 *
 *  Created on: Aug 11, 2018
 *      Author: LucBerthiaume
 */

#include "ExactDateMaturity.h"



ExactDateMaturity::ExactDateMaturity(): maturityDate(day_clock::local_day()) {
	// TODO Auto-generated constructor stub

}


ExactDateMaturity::ExactDateMaturity(date maturityDate): maturityDate(maturityDate) {
	// TODO Auto-generated constructor stub

}

ExactDateMaturity::~ExactDateMaturity() {
	// TODO Auto-generated destructor stub
}

float ExactDateMaturity::timeToExpiry(SimulationContext const & simContext) const{
	return simContext.time_from_analysis_date(this->maturityDate);
}

