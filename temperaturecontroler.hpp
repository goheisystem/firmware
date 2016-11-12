/*
 * temperaturecontroler.hpp
 *
 *  Created on: 2016/11/11
 *      Author: user
 */

#ifndef TEMPERATURECONTROLER_HPP_
#define TEMPERATURECONTROLER_HPP_

#include "mbed.h"

class TemperatureControler {
public:
	void coolDown();
	void heatUp();
	void keep();

private:
	static DigitalOut fan;
	static DigitalOut heater;
};


#endif /* TEMPERATURECONTROLER_HPP_ */
