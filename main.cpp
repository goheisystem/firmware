#include "statemanager.hpp"
#include "timingManager.hpp"
int main() {
	StateManager stateManager;
	TimingManager timingManager;

	timingManager.startManaging();

    while(1) {
    	if(timingManager.isPeriodElasped()){
    		stateManager.manageRoutine();
    		timingManager.clearPeriodElaspedFlag();
    	}
    }
}
