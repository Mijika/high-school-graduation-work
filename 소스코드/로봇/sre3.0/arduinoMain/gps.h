#ifndef _GPS_
#define _GPS_

#include "arduino.h"
#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define GPSBAUD 9600
#define RXPIN 6
#define TXPIN 5

class GPS {
private:
	float _hardness;      //경도값
    float _latitude;      //위도값
    float _altitud;   //gps고도값

public:
	void begin();
	void SensingGps(); //gps모듈에서 정보 가져오기
	String getHardness();  //   gps 경도값 가져오기
    String getLatitude();  //   gps 위도값 가져오기
    String getAltitud();    //gps고도값 가져오기
};


#endif
