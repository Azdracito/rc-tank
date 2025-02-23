#include "motor.h"

void Motor::initialize() const {
    pinMode(MOTOR_A1, OUTPUT);
    pinMode(MOTOR_A2, OUTPUT);
    stop();
}

void Motor::move(int speed) const {
    if (speed > 0) {
        digitalWrite(MOTOR_A1, HIGH);
        digitalWrite(MOTOR_A2, LOW);
    } else if (speed < 0) {
        digitalWrite(MOTOR_A1, LOW);
        digitalWrite(MOTOR_A2, HIGH);
    } else {
        stop();
    }
}

void Motor::stop() const {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, LOW);
}