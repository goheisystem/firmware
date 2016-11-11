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

}
