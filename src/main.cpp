#include <Arduino.h>

const int led1Pin = 2; // LED1 接在 GPIO2
const int led2Pin = 4; // LED2 接在 GPIO4

void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    switch (cmd) {
      case '1':
        digitalWrite(led1Pin, !digitalRead(led1Pin)); // 翻转 LED1 状态
        Serial.print("LED1");
        Serial.println(digitalRead(led1Pin) ? "on" : "off");
        break;
      case '2':
        digitalWrite(led2Pin, !digitalRead(led2Pin)); // 翻转 LED2 状态
        Serial.print("LED2");
        Serial.println(digitalRead(led2Pin) ? "on" : "off");
        break;
      default:
        Serial.print("invalid instruction: ");
        Serial.println(cmd);
        break;
    }
  }
}

