/*
 * temperaturecontroler.cpp
 *
 *  Created on: 2016/11/11
 *      Author: user
 */

#include "temperaturecontroler.hpp"
#include "userdefinition.hpp"

DigitalOut TemperatureControler::fan(FAN_CONTROL_PIN);
DigitalOut TemperatureControler::heater(HEATER_CONTROL_PORT);

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

