#include <Arduino.h>
#include <Wire.h>
#include "RotaryEncoder.hpp"
#include "LoopElement.hpp"
#include "Adafruit_LEDBackpack.h"
#include "CubeSpecific.hpp"

RotaryEncoder re{ROT_PIN1,ROT_PIN2,SWITCH_PIN};

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
re.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  rotaryCache = re.pull_cache();
  if (rotaryCache != 0) 
  {
    yPos = (yPos + rotaryCache + 8) % 8; 


    bm.clear();
    bm.drawPixel(yPos,static_cast<uint16_t>(yPos),colorArr[yPos%3]); 
    bm.writeDisplay();

  }
  
  re.loop_check();
  
}