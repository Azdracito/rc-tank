#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <esp_now.h>
#include <WiFi.h>
#include "../motor/motor.h"

struct JoystickMessage {
    int xAxis;
    int yAxis;
};

class Communication {
public:
    void initialize(Motor& motor);
    
private:
    static void onDataReceived(const uint8_t* mac, const uint8_t* incomingData, int len);
    static Motor* motorInstance;
};

#endif