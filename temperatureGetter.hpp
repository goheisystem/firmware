/*
 * temperatureGetter.hpp
 *
 *  Created on: 2016/11/11
 *      Author: user
 */

#ifndef TEMPERATUREGETTER_HPP_
#define TEMPERATUREGETTER_HPP_

/**
 * @addtogroup gohei_system
 * @{
 */
/**
 * @addtogroup TemperatureGetter
 * @{
 */

#include "mbed.h"

class TemperatureGetter {
public:
	/**
	 * @fn float_t getTemperature()
	 * @brief 温度
	 * @return 摂氏温度
	 */
	float_t getTemperature();

	TemperatureGetter();
private:
	/**
	 * @fn float_t calcurateThermistorTemperature(float_t thermistorVoltage)
	 * @brief サーミスタの電圧から温度を計算する
	 * @param[in] thermistorVoltage : サーミスタの電圧
	 * @return 摂氏温度
	 */
	float_t calcurateThermistorTemperature(float_t thermistorVoltage);
private:
	//! サーミスタB定数
	static const float_t B_CONSTANT = 3380;

	//! サーミスタに直列に入る抵抗値
	static const float_t RP = 100000;

	//! サーミスタのROOM_TEMPERATUREでの抵抗値
	static const float_t R0 = 100000;

	//! 絶対零度の摂氏温度
	static const float_t ZERO_KELVIN = -273.15;

	//! ADCのフルスケール
	static const float_t VDA = 3.3;

	//! R0測定時の温度
	static const float_t ROOM_TEMPERATURE = 25.0;

	//! ADCクラス
	static AnalogIn analogIn;

	//! サーミスタを接続するポート
	static const PinName THERMISTOR_PORT = p15;
};

/**
 * @}
 */
/**
 * @}
 */

#endif /* TEMPERATUREGETTER_HPP_ */
