/*
 * digitalInLowPass.hpp
 *
 *  Created on: 2016/11/23
 *      Author: MM07860
 */

#ifndef DIGITALINLOWPASS_HPP_
#define DIGITALINLOWPASS_HPP_

#include "mbed.h"

class DigitalInLowPass : public DigitalIn {
public:
	DigitalInLowPass(PinName pinName);
	~DigitalInLowPass();
private:
	Ticker ticker;
	int gpioStatus;
	uint8_t counter;
	int prevStatus;
	static const uint8_t FILTER_COUNT_LIMIT = 3;
	static const float_t TICKER_PERIOD = 0.01;
private:
	void callBack();
public:
	int read();
	operator int();

};



#endif /* DIGITALINLOWPASS_HPP_ */
