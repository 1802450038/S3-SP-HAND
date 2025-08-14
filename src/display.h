#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

#include "SPI.h"
#include "TFT_eSPI.h"
#define TFT_BL_PIN 8 // backlight brightness control, needs to be a PWM pin
#define TFT_BRIGHTNESS_PERCENT 70 // avoids overheating of the device
#define TFT_TEXT_SIZE_SMALL 1
#define TFT_TEXT_SIZE 2
#define TFT_TEXT_SIZE_LARGE 3
#define TFT_LINE_HEIGHT_SMALL 10
#define TFT_LINE_HEIGHT 20
#define TFT_LINE_HEIGHT_LARGE 30
#define TFT_WIDTH 240
#define TFT_HEIGHT 240
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240
/*
TFT 240 x 320 pixels 2.0 inch ST7789 display wiring to an ESP32-S3 Supermini
Terminals on display's pcb from left to right

TFT   ESP32-S3
GND   GND
VDD   3.3V
SCL   13
SDA   12 (= "MOSI")
RST   11
DC    10
CS    9
BLK   8 *1)

Note *1) If you don't need a dimming you can connect BLK with 3.3V
Note *2) The display does not have a MISO ("output") terminal, so it is not
wired
*/
// const char* DIVIDER = "--------------------";

extern int maxGraphValue; // Maximum value for the graph
extern unsigned long lastUpdate;
extern bool PRINTED_INFO;


extern TFT_eSPI display;

void initDisplay();
void printDisplayLineSelected(int line, String text, bool rounded = false);
void printDisplayLine(int line, String text, bool selected = false,
                      bool rounded = false);
void clearDisplayLine(int line);
void clearHalfDisplayLine(int line, int half);
void drawLineGraph(int value);
void clearDisplay();
void menuPage();
void menu();



#endif // DISPLAY_H