#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

constexpr int MOTOR_A1 = 16;
constexpr int MOTOR_A2 = 17;
constexpr int MOTOR_A_ENA = 22;

constexpr int MOTOR_B1 = 19;
constexpr int MOTOR_B2 = 21;
constexpr int MOTOR_B_ENA = 23;

class Motor {
    public: 
    void initialize() const;
    void move(int xAxis, int yAxis) const;
    void stop() const;

    private:
    void controlMotor(int pin1, int pin2, int pwmPin, int speed) const;
};

#endif