#include "communication.h"

Motor* Communication::motorInstance = nullptr;

void Communication::initialize(Motor& motor) {
    motorInstance = &motor;

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    esp_now_register_recv_cb(onDataReceived);
}

void Communication::onDataReceived(const uint8_t* mac, const uint8_t* incomingData, int len) {
    JoystickMessage message;
    memcpy(&message, incomingData, sizeof(message));

    if (motorInstance) {
        motorInstance->move(message.xAxis, message.yAxis);
    }
}