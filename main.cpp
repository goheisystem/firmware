#include "statemanager.hpp"
#include "timingManager.hpp"
#include "digitalInLowPass.hpp"


int main() {
	//温度管理用オブジェクト
	StateManager stateManager;
	TimingManager timingManager;
	timingManager.startManaging();

	//UVライト管理用オブジェクト
	DigitalInLowPass switchManager(p8);
	DigitalOut uvLight(p7);


    while(1) {
    	//UVライト制御
    	if(switchManager == 1){
    		uvLight = 1;
    	}
    	else{
    		uvLight = 0;
    	}

    	//温度管理
    	if(timingManager.isPeriodElasped()){
    		stateManager.manageRoutine();
    		timingManager.clearPeriodElaspedFlag();
    	}
    }
}
