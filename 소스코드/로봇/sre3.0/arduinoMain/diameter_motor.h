#ifndef _DIAMETER_MOTOR_
#define _DIAMETER_MOTOR_

#include "arduino.h"

#define DIAMETER_MOTOR_EN1 13 //지름 제어 모터의 방향 지시 핀 1
#define DIAMETER_MOTOR_EN2 14 //지름 제어 모터의 방향 지시 핀 2
#define DIAMETER_MOTOR_PWM 15 //지름 제어 모터의 pwm 핀
#define DIAMETER_MOTORPWM_CH 2 //모터의 pwm 채널

#define MOVE_DIAMETER_MOTOR_SPD 100 //지름 모터의 속도

class Diameter_motor {
public:
	Diameter_motor();

	void diameter_up(void); // 지름 증가
    void diameter_down(void); // 지름 감소
};
//void diamond_upgrade(void); // 다이아몬드 업글
//moter_upgrade(void); //모터 업그레이드

#endif
//made_by_ahndamgyee_cheonho;
//