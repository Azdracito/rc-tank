#include "lib/motor/motor.h"
#include "lib/communication/communication.h"

Motor motor;
Communication communication;

void setup() {
    Serial.begin(115200);
    
    motor.initialize();
    communication.initialize(motor);
}

void loop() {
    // Boucle vide, tout est géré via les interruptions ESP-NOW
}