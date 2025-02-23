#include <esp_now.h>
#include <WiFi.h>

const int motorA1 = 16;
const int motorA2 = 17;

typedef struct struct_message {
  int VRx;
} struct_message;

struct_message myData;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("VRx: ");
  Serial.println(myData.VRx);

  if (myData.VRx > 0) {
    // Avancer
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
  } else if (myData.VRx < 0) {
    // Reculer
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
  } else {
    // Arrêter
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    ledcWrite(0, 0);  // Arrêter moteur A
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
}

void loop() {
}
