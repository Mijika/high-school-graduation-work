#ifndef _SENSOR_
#define _SENSOR_

#include "arduino.h"
#include "bmp.h"
#include "gps.h"
#include "battery.h"

class Sensor {
private:
	BMP bmp;
	GPS gps;
	Battery bat;

public:
	void begin();
	void sensing();

	String values();
};

#endif