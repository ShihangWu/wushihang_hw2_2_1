#include <Arduino.h>

const int led1Pin = 2; // LED1 接在 GPIO2
const int led2Pin = 4; // LED2 接在 GPIO4

void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.println("输入 '1' 控制 LED1(GPIO2),'2' 控制 LED2(GPIO4)");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    switch (cmd) {
      case '1':
        digitalWrite(led1Pin, !digitalRead(led1Pin)); // 翻转 LED1 状态
        Serial.print("LED1");
        Serial.println(digitalRead(led1Pin) ? "亮" : "灭");
        break;
      case '2':
        digitalWrite(led2Pin, !digitalRead(led2Pin)); // 翻转 LED2 状态
        Serial.print("LED2");
        Serial.println(digitalRead(led2Pin) ? "亮" : "灭");
        break;
      default:
        Serial.print("无效指令: ");
        Serial.println(cmd);
        break;
    }
  }
}

