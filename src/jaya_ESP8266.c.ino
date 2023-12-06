#define BLYNK_TEMPLATE_ID "TMPL6vi2-cdY"
#define BLYNK_DEVICE_NAME "Sumit HomeGarden"

#include <Wire.h>
#define BLYNK_PRINT Serial
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#include "BlynkEdgent.h"

#define APP_DEBUG
#include <ESP8266WiFi.h>

BlynkTimer timer;

void moisture() {
  int value = analogRead(A0);
  value = map(value, 0, 1023, 0, 100);
  Blynk.virtualWrite(V0, value);
  Serial.println(value);
}

void setup() {
  Serial.begin(9600);
  BlynkEdgent.begin();
  Wire.begin(D2, D1);   
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);
  timer.setInterval(100L, moisture);

}
void loop() {
  BlynkEdgent.run();
  timer.run();
}
