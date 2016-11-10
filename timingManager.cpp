/*
 * timingManager.cpp
 *
 *  Created on: 2016/11/11
 *      Author: user
 */

#include "timingManager.hpp"

#include "mbed.h"


TimingManager::TimingManager()
{
	periodElaspedFlag = false;
}
void TimingManager::callBack()
{
	periodElaspedFlag = true;
}
void TimingManager::startManaging()
{
	startTimer();
}
void TimingManager::stopManaging()
{
	stopTimer();
}
bool TimingManager::isPeriodElasped()
{
	return periodElaspedFlag;
}
void TimingManager::clearPeriodElaspedFlag()
{
	__disable_irq();

	periodElaspedFlag = false;

	__enable_irq();
}
void TimingManager::startTimer()
{
	ticker.attach(&callBack,(float_t)PERIOD_SEC);
}
void TimingManager::stopTimer()
{
	ticker.detach();
	periodElaspedFlag = false;
}

