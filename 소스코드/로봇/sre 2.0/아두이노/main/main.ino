#include "robot\robot.h"


void setup() {
	Serial.beging(9600);

	Robot robot;
	robot.beging();

	robot.start();
}

void loop() {
}
