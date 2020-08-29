#ifndef _ACTION_
#define _ACTION_

#include "arduino.h"
#include "move_motor.h"
#include "diameter_motor.h"
#include "led.h"




class Action {
private:
	Led led;
	Diameter_motor diameter_motor;
	Move_motor move_motor;
public:
	void begin();

	void ledOn();
	void ledOff();

	void forward(); //모터 전진
    void reverse(); //모터 후진
    void left_turn(); //모터 좌회전
    void right_turn(); //모터 우회전
    void stop(); //모터 정지

	void diameter_up(void); // 지름 증가
    void diameter_down(void); // 지름 감소
};

#endif
