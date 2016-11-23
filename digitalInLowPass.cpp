/*
 * digitalInLowPass.cpp
 *
 *  Created on: 2016/11/23
 *      Author: MM07860
 */


#include "digitalInLowPass.hpp"

typedef DigitalIn BaseClass;

DigitalInLowPass::DigitalInLowPass(PinName pinName) : DigitalIn(pinName)
{
	gpioStatus = 0;
	counter = 0;
	prevStatus = 0;
	ticker.attach(this,&DigitalInLowPass::callBack,TICKER_PERIOD);
}
void DigitalInLowPass::callBack()
{
	int status = 0;
	status = BaseClass::read();

	if (status != prevStatus) {
		counter = 0;

		prevStatus = status;
	}
	else {
		if (counter < FILTER_COUNT_LIMIT) {
			counter++;
		}
		else {
			gpioStatus = status;
		}
	}
}
int DigitalInLowPass::read()
{
	return gpioStatus;
}
DigitalInLowPass::operator int()
{
	return read();
}
