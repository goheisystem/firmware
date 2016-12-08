/*
 * userdefinition.hpp
 *
 *  Created on: 2016/12/08
 *      Author: MM07860
 */

#ifndef USERDEFINITION_HPP_
#define USERDEFINITION_HPP_


// constants
//! スイッチ入力のローパスカウント数
#define LOW_PASS_COUNT_LIMIT 3

//! スイッチ入力の監視周期[sec]
#define LOW_PASS_TICKER_PERIOD 0.1

//! 温度管理の下限温度[deg]
#define MANAGE_TEMPERATURE_LOWER_LIMIT 27

//! 温度管理の上限温度[deg]
#define MANAGE_TEMPERATURE_UPPRE_LIMIT 28



// pin selection
//! UVライトの制御スイッチ入力ポート
#define UVRIGHT_CONTROL_SWITCH_PIN p29

//! UVライトの制御ポート
#define UVRIGHT_CONTROL_PIN p7

//! ファンの制御ポート
#define FAN_CONTROL_PIN p5

//! ヒータの制御ポート
#define HEATER_CONTROL_PORT p6

//! サーミスタの入力ポート
#define THERMISTOR_INPUT_PORT p15

//! 温度管理周期[sec]
#define TEMPERATURE_MANAGE_PERIOD 10

#endif /* USERDEFINITION_HPP_ */
