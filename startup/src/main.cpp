#include <Arduino.h>
#include <Wire.h>
#include "RotaryEncoder.hpp"
#include "LoopElement.hpp"
#include "Adafruit_LEDBackpack.h"

RotaryEncoder re{10,11,9};

Adafruit_BicolorMatrix bm;

uint16_t  colorArr[3] = {LED_GREEN, LED_RED, LED_YELLOW};

int yPos = 1;
int rotaryCache = 0;

void setup() {
  // put your setup code here, to run once:
bm.begin(0x70, &Wire1);
bm.setBrightness(10);
bm.drawPixel(1, 1, LED_GREEN);
bm.writeDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  rotaryCache = re.pull_cache();
  if (rotaryCache != 0) {
  yPos = (yPos + rotaryCache) % 8;
  

  bm.clear();
  bm.drawPixel(1, yPos, colorArr[yPos % 3]);
  bm.writeDisplay();
  }
  
  re.loop_check();
  
}