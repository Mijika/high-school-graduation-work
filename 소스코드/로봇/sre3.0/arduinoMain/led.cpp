#include "led.h"

void Led::led_on() { //LED 전등 온
    analogWrite(LED_RED, 100);
    analogWrite(LED_Green, 100);
	analogWrite(LED_BLUE, 100);
}
void Led::led_off() { //LED 전등 오프
    analogWrite(LED_RED, 0);
    analogWrite(LED_Green, 0);
	analogWrite(LED_BLUE, 0);
}