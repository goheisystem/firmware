/*
 * statemanager.hpp
 *
 *  Created on: 2016/11/07
 *      Author: user
 */

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include "temperatureGetter.hpp"
#include "temperaturecontroler.hpp"
#include "userdefinition.hpp"

typedef enum {
	HEATING,
	KEEPING,
	COOLING
}SystemStatus;

class StateManager {
public:
	void manageRoutine();
	StateManager();
private:
	SystemStatus calcurateNextState(float_t currentTemperature);
private:
	SystemStatus currentStatus;
	static TemperatureGetter temperatureGetter;
	static TemperatureControler temperatureControler;
	static const float_t TEMPERATURE_LOWER_LIMIT = MANAGE_TEMPERATURE_LOWER_LIMIT;
	static const float_t TEMPERATURE_UPPER_LIMIT = MANAGE_TEMPERATURE_UPPRE_LIMIT;
};



#endif /* STATEMANAGER_HPP_ */
