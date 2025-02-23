#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

constexpr int MOTOR_A1 = 16;
constexpr int MOTOR_A2 = 17;

class Motor {
    public: 
    void initialize() const;
    void move(int speed) const;
    void stop() const;
};

#endif