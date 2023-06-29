#ifndef __INC_MUZIO_VU_19_H
#define __INC_MUZIO_VU_19_H
#include <Arduino.h>
#include <FastLED.h>
#include "common.h"

uint8_t gHue = 0; // rotating "base color" used by many of the patterns

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

void rainbow()
{
    FOR_i(0, N_PIXELS)
    {
        ledsLeft[i] = ColorFromPalette(RainbowColors_p, i * 2 + gHue, 255, LINEARBLEND);
    }
    EVERY_N_MILLISECONDS(100)
    {
        gHue++;
    }
    FastLED.show(); // Update strip
}

void cloud()
{
    FOR_i(0, N_PIXELS)
    {

        ledsLeft[i] = ColorFromPalette(CloudColors_p, i + gHue, 255, LINEARBLEND);
    }
    EVERY_N_MILLISECONDS(100)
    {
        gHue++;
    }
    FastLED.show(); // Update strip
}

void ocean()
{
    FOR_i(0, N_PIXELS)
    {
        ledsLeft[i] = ColorFromPalette(OceanColors_p, i + gHue, 255, LINEARBLEND);
        EVERY_N_MILLISECONDS(100)
        {
            gHue++;
        }
    }
    FastLED.show(); // Update strip
}

void rainbowStripe()
{
    FOR_i(0, N_PIXELS)
    {
        ledsLeft[i] = ColorFromPalette(RainbowStripeColors_p, i + gHue, 255, LINEARBLEND);
    }
    EVERY_N_MILLISECONDS(100) { gHue++; } // slowly cycle the "base color" through the rainbow

    FastLED.show(); // Update strip
}

fract8 chanceOfGlitter = 15;
void addGlitter()
{
    if (random8() < chanceOfGlitter)
    {
        ledsLeft[random16(N_PIXELS)] += CRGB::White;
    }
    EVERY_N_MILLISECONDS(100)
    { // FastLED based non-blocking delay to update/display the sequence.
        fill_solid(ledsLeft, N_PIXELS, CRGB::Black);
    }
    FastLED.show(); // Update strip
}

void confetti()
{
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy(ledsLeft, N_PIXELS, 60);
    int pos = random16(N_PIXELS);
    ledsLeft[pos] += CHSV(gHue + random8(64), 200, 255);
    EVERY_N_MILLISECONDS(100) { gHue++; } // slowly cycle the "base color" through the rainbow
    FastLED.show();                       // Update strip
}

#endif // __INC_MUZIO_VU_16_H