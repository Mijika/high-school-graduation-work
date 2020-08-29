#include "BMP.h"

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

void BMP::begin() {
    Serial.println("");
    Serial.println(" 고도 센서초기화");

    if(!bmp.begin()) {
        Serial.println("고도 센서가 연결이 되어있지 않습니다.");
        flag = 0;
    }

    _altitud = "0";
    _temperature = "0";
}

void BMP::sensingBmp() {
    if(flag == 0) {
        Serial.println("고도 센서를 연결후 사용하세요.");

        return ;
    }

    sensors_event_t event;
    bmp.getEvent(&event);

    float temperature;
    float seaLevelPressure = 1014.3;

    if(event.pressure) {
        bmp.getTemperature(&temperature);
        _temperature = String(temperature);

        _altitud = String(
        bmp.pressureToAltitude(seaLevelPressure, event.pressure));
    }
    else {
        Serial.println("Sensor error");
    }
}


String BMP::getAltitude() {
    return _altitud;
}
String BMP::getTemperature() {
    return _temperature;
}
