#include "diameter_motor.h"

Diameter_motor::Diameter_motor() {
    pinMode(DIAMETER_MOTOR_EN1, OUTPUT);       // 지름 모터 방향설정1
    pinMode(DIAMETER_MOTOR_EN2, OUTPUT);       // 지름 모터 방향설정2
}

//지름 모터
void Diameter_motor::diameter_up() { // 지름 증가
    digitalWrite(DIAMETER_MOTOR_EN1, HIGH);
    digitalWrite(DIAMETER_MOTOR_EN2, LOW);
    analogWrite(DIAMETER_MOTORPWM_CH, MOVE_DIAMETER_MOTOR_SPD);
}
void Diameter_motor::diameter_down() { // 지름 감소
    digitalWrite(DIAMETER_MOTOR_EN1, LOW);
    digitalWrite(DIAMETER_MOTOR_EN2, HIGH);
    analogWrite(DIAMETER_MOTORPWM_CH, MOVE_DIAMETER_MOTOR_SPD);
}