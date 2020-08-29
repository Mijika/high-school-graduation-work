#ifndef _BMP_
#define _BMP_

#include "arduino.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

class BMP {
private:
	int flag = 1;

	String _altitud;       //고도값
	String _temperature;   //온도값

public:
	void begin();
	void sensingBmp(); //고도센서에서 정보 가져오기
	String getAltitude();      //  고도 센서에서 고도값 가져오기
    String getTemperature();   //    고도 센서에서 온도값 가져오기
};

#endif