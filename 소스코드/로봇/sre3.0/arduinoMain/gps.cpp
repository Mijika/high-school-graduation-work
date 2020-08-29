#include "GPS.h"

SoftwareSerial uart_gps(RXPIN, TXPIN);
TinyGPS gps;


void GPS::begin() {
	uart_gps.begin(GPSBAUD);

	Serial.println("");
  	Serial.println("GPS 모듈 초기화");

  	_hardness = 0.0;
  	_latitude = 0.0;
  	_altitud = 0.0;
}

void GPS::SensingGps() {
	float hardness = 0.0;
	float latitude = 0.0;
	float altitud = 0.0;

	if(uart_gps.available()) {
		int gps_data = uart_gps.read();

		if(gps.encode(gps_data)) {
			gps.f_get_position(&latitude, &hardness);

			_hardness = hardness;
			_latitude = latitude;
			_altitud = gps.f_altitude();
		}
		else {
			Serial.println("GPS 데이터를 해독하지 못했습니다.");
		}
	}
	else {
		Serial.println("GPS 데이터를 수신하지 못했습니다.");
	}
}

String GPS::getHardness() {
	return String(_hardness);
}
String GPS::getLatitude() {
	return String(_latitude);
}
String GPS::getAltitud() {
	return String(_altitud);
}
