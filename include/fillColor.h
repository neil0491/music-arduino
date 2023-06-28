#ifndef __INC_MUZIO_VU_18_H
#define __INC_MUZIO_VU_18_H
#include <Arduino.h>
#include <FastLED.h>
#include "common.h"

void fillAllGreen()
{
  fill_solid(ledsLeft, N_PIXELS, CRGB::Green);
  FastLED.show(); // Update strip
}
void fillAllRed()
{
  fill_solid(ledsLeft, N_PIXELS, CRGB::Red);
  FastLED.show(); // Update strip
}
void fillAllYellowGreen()
{
  fill_solid(ledsLeft, N_PIXELS, CRGB::LightGoldenrodYellow);
  FastLED.show(); // Update strip
}


#endif  // __INC_MUZIO_VU_16_H