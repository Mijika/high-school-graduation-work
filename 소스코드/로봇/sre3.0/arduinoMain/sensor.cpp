#include "sensor.h"

void Sensor::begin() {
	bmp.begin();
	gps.begin();
	bat.begin();
}

void Sensor::sensing() {
	bmp.sensingBmp();
	gps.SensingGps();
	bat.sensingBattery();
}

String Sensor::values() {
	String data = gps.getHardness() + "/" + gps.getLatitude() + "/" +
				gps.getAltitud(); + "/" + bmp.getAltitude() + "/" +
				bmp.getTemperature(); + "/" + bat.getBattery();

	return data;
}