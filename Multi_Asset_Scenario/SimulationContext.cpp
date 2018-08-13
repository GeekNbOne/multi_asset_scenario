/*
 * SimulationContext.cpp
 *
 *  Created on: Aug 11, 2018
 *      Author: LucBerthiaume
 */

#include "SimulationContext.h"

SimulationContext::SimulationContext() {
	// TODO Auto-generated constructor stub

}

SimulationContext::~SimulationContext() {
	// TODO Auto-generated destructor stub
}


float SimulationContext::time_from_analysis_date(date const& toDate) const{
	int timeInDays = (toDate - this->analysisDate).days();
	float timeInYears = timeInDays / this->daysInYears;
	return timeInYears / this->timeBasis;
}
