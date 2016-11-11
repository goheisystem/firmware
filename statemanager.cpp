/*
 * statemanager.cpp
 *
 *  Created on: 2016/11/07
 *      Author: user
 */
#include "statemanager.hpp"

#include "timingManager.hpp"

TimingManager StateManager::timingManager;
TemperatureGetter StateManager::temperatureGetter;

void StateManager::startManaging()
{
	timingManager.clearPeriodElaspedFlag();
	timingManager.startManaging();
}
void StateManager::stopManaging()
{
	timingManager.stopManaging();
	timingManager.clearPeriodElaspedFlag();
}
void StateManager::manageRoutine()
{
	float_t currentTemperature = temperatureGetter.getTemperature();

	calcurateNextState(currentTemperature);
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
			if(currentTemperature < TEMPERATURE_LOWER_LIMIT){
				currentStatus = KEEPING;
			}
			break;
		default:
			break;
	}

	return currentStatus;
}
