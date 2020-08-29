/*
	수정일자 2020-04-23
	개발자 안담기
	Move_motor : 모터 2개를 제어하는 클래스
 */

#ifndef _MOVE_MOTOR_
#define _MOVE_MOTOR_

#include "arduino.h"

#define MOTOR_RIGHT_EN1 10 //오른쪽 모터의 방향 지시 핀 1
#define MOTOR_RIGHT_EN2 11 //오른쪽 모터의 방향 지시 핀 2
#define MOTOR_RIGHT_PWM 12 //오른쪽 모터의 pwm 핀

#define MOTOR_LEFT_EN1 13 //왼쪽 모터의 방향 지시 핀 1
#define MOTOR_LEFT_EN2 14 //왼쪽 모터의 방향 지시 핀 2
#define MOTOR_LEFT_PWM 15 //왼쪽 모터의 pwm 핀

#define MOTOR_SPD 100 //모터의 스피드

class Move_motor {
public:
	Move_motor();

	//이동 모터 4가지 모드 코딩(void전진, 후진, 왼쪽 턴, 오른쪽 턴)
    void forward(); //모터 전진
    void reverse(); //모터 후진
    void left_turn(); //모터 좌회전
    void right_turn(); //모터 우회전
    void stop(); //모터 정지
};

#endif