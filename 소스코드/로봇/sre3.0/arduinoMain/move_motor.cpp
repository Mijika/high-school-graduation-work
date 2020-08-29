#include "move_motor.h"

Move_motor::Move_motor() {
  //앞 바퀴 방향 설정
    pinMode(MOTOR_RIGHT_EN1, OUTPUT);       // Motor RIGHT 방향설정1
    pinMode(MOTOR_RIGHT_EN2, OUTPUT);       // Motor RIGHT 방향설정2
    pinMode(MOTOR_LEFT_EN1, OUTPUT);       // Motor LEFR 방향설정1
    pinMode(MOTOR_LEFT_EN2, OUTPUT);       // Motor LEFR 방향설정2
}

void Move_motor::forward() {
  digitalWrite(MOTOR_RIGHT_EN1, HIGH);
    digitalWrite(MOTOR_RIGHT_EN2, LOW);
    digitalWrite(MOTOR_LEFT_EN1, LOW);
    digitalWrite(MOTOR_LEFT_EN2, HIGH);

    analogWrite(MOTOR_RIGHT_PWM, MOTOR_SPD);
    analogWrite(MOTOR_LEFT_PWM, MOTOR_SPD);
}

void Move_motor::reverse() {
  digitalWrite(MOTOR_RIGHT_EN1, LOW);
    digitalWrite(MOTOR_RIGHT_EN2, HIGH);
    digitalWrite(MOTOR_LEFT_EN1, HIGH);
    digitalWrite(MOTOR_LEFT_EN2, LOW);

    analogWrite(MOTOR_RIGHT_PWM, MOTOR_SPD);
    analogWrite(MOTOR_LEFT_PWM, MOTOR_SPD);
}

void Move_motor::left_turn() {
  digitalWrite(MOTOR_RIGHT_EN1, HIGH);
    digitalWrite(MOTOR_RIGHT_EN2, LOW);
    digitalWrite(MOTOR_LEFT_EN1, HIGH);
    digitalWrite(MOTOR_LEFT_EN2, LOW);

    analogWrite(MOTOR_RIGHT_PWM, MOTOR_SPD);
    analogWrite(MOTOR_LEFT_PWM, MOTOR_SPD);
}

void Move_motor::right_turn() {
  digitalWrite(MOTOR_RIGHT_EN1, LOW);
    digitalWrite(MOTOR_RIGHT_EN2, HIGH);
    digitalWrite(MOTOR_LEFT_EN1, LOW);
    digitalWrite(MOTOR_LEFT_EN2, HIGH);

    analogWrite(MOTOR_RIGHT_PWM, MOTOR_SPD);
    analogWrite(MOTOR_LEFT_PWM, MOTOR_SPD);
}

void Move_motor::stop() {
  digitalWrite(MOTOR_RIGHT_EN1, LOW);
    digitalWrite(MOTOR_RIGHT_EN2, LOW);
    digitalWrite(MOTOR_LEFT_EN1, LOW);
    digitalWrite(MOTOR_LEFT_EN2, LOW);

    analogWrite(MOTOR_RIGHT_PWM, 0);
    analogWrite(MOTOR_LEFT_PWM, 0);
}
