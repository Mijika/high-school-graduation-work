#ifndef _BATTERY_
#define _BATTERY_


#include "arduino.h"

#define BATPIN A2

class Battery {
private:
	float _batteryData;

public:
	void begin();
	void sensingBattery(); //배터리에서 잔량 센싱

	String getBattery();      //  배터리에서 잔량 가져오기
};

#endif
