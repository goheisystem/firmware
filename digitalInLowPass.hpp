/*
 * digitalInLowPass.hpp
 *
 *  Created on: 2016/11/23
 *      Author: MM07860
 */

#ifndef DIGITALINLOWPASS_HPP_
#define DIGITALINLOWPASS_HPP_

#include "mbed.h"
#include "userdefinition.hpp"

class DigitalInLowPass : public DigitalIn {
public:
	DigitalInLowPass(PinName pinName);
	~DigitalInLowPass();
private:
	Ticker ticker;
	int gpioStatus;
	uint8_t counter;
	int prevStatus;
	static const uint8_t FILTER_COUNT_LIMIT = LOW_PASS_COUNT_LIMIT;
	static const float_t TICKER_PERIOD = LOW_PASS_TICKER_PERIOD;
private:
	void callBack();
public:
	int read();
	operator int();

};



#endif /* DIGITALINLOWPASS_HPP_ */
