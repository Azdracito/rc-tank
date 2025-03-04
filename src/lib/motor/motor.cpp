#include "motor.h"

void Motor::initialize() const {
    pinMode(MOTOR_A1, OUTPUT);
    pinMode(MOTOR_A2, OUTPUT);

    pinMode(MOTOR_B1, OUTPUT);
    pinMode(MOTOR_B2, OUTPUT);

    pinMode(MOTOR_B_ENA, OUTPUT);
    pinMode(MOTOR_A_ENA, OUTPUT);
    stop();
}

void Motor::move(int xAxis, int yAxis) const {
    int baseSpeed = constrain(map(abs(xAxis), 0, 100, 0, 255), 0, 255);
    int turnSpeed = constrain(map(abs(yAxis), 0, 100, 0, 255), 0, 255);
    float turnFactor = map(abs(yAxis), 0, 100, 10, 30) / 100.0f; 
    int adjustedSpeed = max(baseSpeed - static_cast<int>(turnSpeed * turnFactor), 0);

    if (xAxis > 0) { 
        digitalWrite(MOTOR_A1, HIGH);
        digitalWrite(MOTOR_A2, LOW);
        digitalWrite(MOTOR_B1, HIGH);
        digitalWrite(MOTOR_B2, LOW);

        analogWrite(MOTOR_A_ENA, (yAxis < 0) ? adjustedSpeed : baseSpeed);
        analogWrite(MOTOR_B_ENA, (yAxis > 0) ? adjustedSpeed : baseSpeed);
    } 
    else if (xAxis < 0) {
        digitalWrite(MOTOR_A1, LOW);
        digitalWrite(MOTOR_A2, HIGH);
        digitalWrite(MOTOR_B1, LOW);
        digitalWrite(MOTOR_B2, HIGH);

        analogWrite(MOTOR_A_ENA, (yAxis > 0) ? adjustedSpeed : baseSpeed);
        analogWrite(MOTOR_B_ENA, (yAxis < 0) ? adjustedSpeed : baseSpeed);
    } 
    else if (xAxis == 0 && yAxis != 0) {
        int pivotSpeed = map(abs(yAxis), 0, 100, 50, 150);
        pivotSpeed = constrain(pivotSpeed, 50, 150);

        if (yAxis > 0) {  
            digitalWrite(MOTOR_A1, HIGH);
            digitalWrite(MOTOR_A2, LOW);
            digitalWrite(MOTOR_B1, LOW);
            digitalWrite(MOTOR_B2, HIGH);
        } else { 
            digitalWrite(MOTOR_A1, LOW);
            digitalWrite(MOTOR_A2, HIGH);
            digitalWrite(MOTOR_B1, HIGH);
            digitalWrite(MOTOR_B2, LOW);
        }

        analogWrite(MOTOR_A_ENA, pivotSpeed);
        analogWrite(MOTOR_B_ENA, pivotSpeed);
    } 
    else {
        stop();
    }
}

void Motor::stop() const {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, LOW);
    analogWrite(MOTOR_A_ENA, 0);

    digitalWrite(MOTOR_B1, LOW);
    digitalWrite(MOTOR_B2, LOW);
    analogWrite(MOTOR_B_ENA, 0);
}