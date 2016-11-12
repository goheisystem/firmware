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
#include "temperaturecontroler.hpp"

typedef enum {
	HEATING,
	KEEPING,
	COOLING
}SystemStatus;

class StateManager {
public:
	void manageRoutine();
private:
	SystemStatus calcurateNextState(float_t currentTemperature);
private:
	SystemStatus currentStatus;
	static TemperatureGetter temperatureGetter;
	static TemperatureControler temperatureControler;
	static const float_t TEMPERATURE_LOWER_LIMIT = 27;
	static const float_t TEMPERATURE_UPPER_LIMIT = 28;
};



#endif /* STATEMANAGER_HPP_ */
