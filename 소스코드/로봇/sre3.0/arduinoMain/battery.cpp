#include "battery.h"

void Battery::begin() {
    _batteryData = analogRead(BATPIN);
}
void Battery::sensingBattery() {
    _batteryData = analogRead(BATPIN);
}
String Battery::getBattery() {
    return String(_batteryData);
}
