/*
 * temperatureGetter.cpp
 *
 *  Created on: 2016/11/11
 *      Author: user
 */

#include "temperatureGetter.hpp"
#include "math.h"

TemperatureGetter::TemperatureGetter()
{
	analogIn = AnalogIn(THERMISTOR_PORT);
}

float_t TemperatureGetter::calcurateThermistorTemperature(float_t thermistorVoltage)
{
	float_t temp=0;
	temp = 1 / ((log(thermistorVoltage/(VDA - thermistorVoltage))
			+ log(RP / R0)) / B_CONSTANT + 1 / (ROOM_TEMPERATURE - ZERO_KELVIN)) + ZERO_KELVIN;
	return temp;
}
float_t TemperatureGetter::getTemperature()
{
	return calcurateThermistorTemperature(analogIn.read());
}

