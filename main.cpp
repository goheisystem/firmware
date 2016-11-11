#include "temperatureGetter.hpp"

int main() {
	TemperatureGetter temperatureGetter;
    while(1) {
    	float_t temperature = temperatureGetter.getTemperature();
    	printf("%f deg \n",temperature);
    	wait(1);
    }
}
