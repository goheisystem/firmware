/*
 * statemanager.hpp
 *
 *  Created on: 2016/11/07
 *      Author: user
 */

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include "timingManager.hpp"
#include "temperatureGetter.hpp"

typedef enum {
	HEATING,
	KEEPING,
	COOLING
}SystemStatus;

class StateManager {
public:
	void startManaging();
	void stopManaging();
	void manageRoutine();
private:
	SystemStatus calcurateNextState(float_t );
private:
	SystemStatus currentStatus;
	static TimingManager timingManager;
	static TemperatureGetter temperatureGetter;
	static const float_t TEMPERATURE_LOWER_LIMIT = 27;
	static const float_t TEMPERATURE_UPPER_LIMIT = 28;
};



#endif /* STATEMANAGER_HPP_ */
