#ifndef __INC_MUZIO_VU_19_H
#define __INC_MUZIO_VU_19_H
#include <Arduino.h>
#include <FastLED.h>
#include "common.h"

void strobe()
{
    EVERY_N_MILLISECONDS(101)
    { // FastLED based non-blocking delay to update/display the sequence.
        fill_solid(ledsLeft, N_PIXELS, CRGB::White);
    }
    EVERY_N_MILLISECONDS(50)
    { // FastLED based non-blocking delay to update/display the sequence.
        fill_solid(ledsLeft, N_PIXELS, CRGB::Black);
    }
    FastLED.show(); // Update strip
}

#endif // __INC_MUZIO_VU_16_H