/*
 * SimulationContext.h
 *
 *  Created on: Aug 11, 2018
 *      Author: LucBerthiaume
 */

#ifndef SIMULATIONCONTEXT_H_
#define SIMULATIONCONTEXT_H_

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

class SimulationContext {

private:
	float timeBasis;
	date analysisDate;
	float daysInYears = float(365.0);

public:
	SimulationContext();
	virtual ~SimulationContext();

	float time_from_analysis_date(date const&) const;

};

#endif /* SIMULATIONCONTEXT_H_ */
