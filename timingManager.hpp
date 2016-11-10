/*
 * timingManager.hpp
 *
 *  Created on: 2016/11/11
 *      Author: user
 */

#ifndef TIMINGMANAGER_HPP_
#define TIMINGMANAGER_HPP_

/**
 * @addtogroup gohei_system
 * @{
 */
/**
 * @addtogroup TimingManager
 * @{
 */
#include "mbed.h"

class TimingManager {
public:
	/**
	 * @fn void startManaging()
	 * @brief タイミング管理を開始する
	 */
	void startManaging();

	/**
	 * @fn void stopManaging()
	 * @brief タイミング管理を停止する
	 */
	void stopManaging();

	/**
	 * @fn bool isPeriodElasped()
	 * @brief 周期がすぎたかどうか問い合わせ
	 */
	bool isPeriodElasped();

	/**
	 * @fn void clearPeriodElaspedFlag()
	 * @brief 周期経過フラグをクリアする
	 */
	void clearPeriodElaspedFlag();

	TimingManager();
private:
	//! 周期経過フラグ
	static bool periodElaspedFlag;
	//! 周期 10sec
	static const uint32_t PERIOD_SEC = 10;
	//! 割り込みタイマクラス
	static Ticker ticker;
private:
	/**
	 * @fn void startTimer()
	 * @brief タイマスタート
	 */
	void startTimer();

	/**
	 * @fn void stopTimer()
	 * @brief タイマ停止
	 */
	void stopTimer();

	/**
	 * @fn void callBack()
	 * @brief コールバック関数
	 */
	static void callBack();
};

/**
 * @}
 */
/**
 * @}
 */
#endif /* TIMINGMANAGER_HPP_ */
