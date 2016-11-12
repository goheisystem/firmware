/*
 * temperaturecontroler.cpp
 *
 *  Created on: 2016/11/11
 *      Author: user
 */

#include "temperaturecontroler.hpp"

DigitalOut TemperatureControler::fan(p5);
DigitalOut TemperatureControler::heater(p6);

void TemperatureControler::coolDown()
{
	fan = 1;
	heater = 0;
}
void TemperatureControler::heatUp()
{
	fan = 0;
	heater = 1;
}
void TemperatureControler::keep()
{
	fan = 0;
	heater = 0;
}

