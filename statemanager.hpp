/*
 * statemanager.hpp
 *
 *  Created on: 2016/11/07
 *      Author: user
 */

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

typedef enum {
	HEATING,
	KEEPING,
	COOLING
}SystemStatus;

class StateManager {
public:
	void startManaging();
	void stopManaging();
	void manageRoutine();
private:
	SystemStatus calcrateNextState();
private:
	SystemStatus currentStatus;
};



#endif /* STATEMANAGER_HPP_ */
