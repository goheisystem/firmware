/*
 * statemanager.cpp
 *
 *  Created on: 2016/11/07
 *      Author: user
 */
#include "statemanager.hpp"
#include "userdefinition.hpp"

TemperatureGetter StateManager::temperatureGetter;
TemperatureControler StateManager::temperatureControler;

#if DEBUG_SWITCH == 1
BusOut debugLED(LED1,LED2,LED3);
#endif

StateManager::StateManager()
{
	currentStatus = KEEPING;
}
void StateManager::manageRoutine()
{
	float_t currentTemperature = temperatureGetter.getTemperature();

	calcurateNextState(currentTemperature);

#if DEBUG_SWITCH == 1
	printf("temperature : %2.2f, statusID : %d \r\n", currentTemperature, currentStatus);
	debugLED = 0x01<<(currentStatus);
#endif

	switch (currentStatus) {
		case KEEPING:
			temperatureControler.keep();
			break;
		case COOLING:
			temperatureControler.coolDown();
			break;
		case HEATING:
			temperatureControler.heatUp();
			break;
		default:
			break;
	}
}

SystemStatus StateManager::calcurateNextState(float_t currentTemperature)
{
	switch (currentStatus) {
		case KEEPING:
			if(currentTemperature >= TEMPERATURE_UPPER_LIMIT){
				currentStatus = COOLING;
			}
			else if(currentTemperature < TEMPERATURE_LOWER_LIMIT){
				currentStatus = HEATING;
			}
			break;
		case HEATING:
			if(currentTemperature >= TEMPERATURE_UPPER_LIMIT){
				currentStatus = KEEPING;
			}
			break;
		case COOLING:
			if(currentTemperature < TEMPERATURE_UPPER_LIMIT){
				currentStatus = KEEPING;
			}
			break;
		default:
			break;
	}

	return currentStatus;
}
