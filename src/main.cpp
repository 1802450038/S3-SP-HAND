#include "buttons.h"
#include "display.h"
#include "emg.h"
#include "hand.h"
#include "now.h"
#include <Arduino.h>
#include <CD74HC4067.h>
#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

#define SIG_PIN 2
CD74HC4067 my_mux(6, 5, 4, 3); // (S0, S1, S2, S3)

// -------------------------------------------------------------------------------

// void updateMillis(int ms) {
//   static unsigned long previousMillis = 0;
//   unsigned long currentMillis = millis();
//   if (currentMillis - previousMillis >= ms) {
//     previousMillis = currentMillis;
//   }
// }

void setup() {
  Serial.begin(115200);
  delay(1000);
  initButtons();
  initDisplay();
  pinMode(TFT_BL_PIN, OUTPUT);
  analogWrite(TFT_BL_PIN, 255 * TFT_BRIGHTNESS_PERCENT / 100);
  initNow();
  display.fillScreen(TFT_BLACK);
  initEMG();
  menu();
}

void debugFMG();
int fmgAnaliser(int chanel);
void updateAngFMG();

void loop() {
  // menu();
  debugFMG();
  // fmgAnaliser(0);
  // // delay(100);
  // fmgAnaliser(4);
  // // delay(100);
  // fmgAnaliser(8);
  // delay(100);
  // btnTicks();
  // menu();
  // updateAngFMG();
  // sendPackMillis(200);

}

int fmgAnaliser(int chanel) {
  my_mux.channel(chanel);
  int val = analogRead(SIG_PIN);
  int ang = map(val, 0, 4096, 0, 180);
  // Serial.println("Chanel " + String(chanel) + " Ang : " + String(ang));
  return ang;
}

void updateAngFMG(){
  THUMB_POS = fmgAnaliser(10);
  INDEX_POS = fmgAnaliser(9);
  MIDDLE_POS = fmgAnaliser(8);
  RING_POS = fmgAnaliser(7);
  LITTLE_POS = fmgAnaliser(6);
}


void debugFMG() {

  Serial.print("Low ref");
  Serial.print(0);
  Serial.print(",");

  Serial.print("Chanel 10: ");
  my_mux.channel(0);
  Serial.print(analogRead(SIG_PIN));
  Serial.print(",");

  Serial.print(" Chanel 9: ");
  my_mux.channel(4);
  Serial.print(analogRead(SIG_PIN));
  Serial.print(",");

  Serial.print(" Chanel 8: ");
  my_mux.channel(8);
  Serial.print(analogRead(SIG_PIN));
  Serial.print(",");
  
  Serial.print(" Chanel 7: ");
  my_mux.channel(7);
  Serial.print(analogRead(SIG_PIN));
  Serial.print(",");

  Serial.print(" Chanel 6: ");
  my_mux.channel(6);
  Serial.print(analogRead(SIG_PIN));
  Serial.print(",");


  Serial.print("Max ref");
  Serial.print(4096);
  // Serial.print(",");

  Serial.println("");

  delay(50);
  // delay(120);
}