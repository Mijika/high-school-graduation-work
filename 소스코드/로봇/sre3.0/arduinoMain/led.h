#ifndef _LED_
#define _LED_

#include "arduino.h"

#define LED_RED 5
#define LED_Green 6
#define LED_BLUE 7

class Led {
public:
	led();

	void led_on();
	void led_off();
};

#endif