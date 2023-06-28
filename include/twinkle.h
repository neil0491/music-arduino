#ifndef __INC_MUZIO_VU_24_H
#define __INC_MUZIO_VU_24_H
#include <Arduino.h>
#include <FastLED.h>
#include "common.h"

const uint8_t FADE_RATE = 2; // How long should the trails be. Very low value = longer trails.

void twinkle() {
  if (random(25) == 1) {
    uint16_t i = random(N_PIXELS);
    ledsLeft[i] = CRGB(random(256), random(256), random(256));
  }



  fadeToBlackBy(ledsLeft, N_PIXELS, FADE_RATE);
  
  FastLED.show();
  delay(10);
}



#endif  // __INC_MUZIO_VU_16_H