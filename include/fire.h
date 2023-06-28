#ifndef __INC_MUZIO_VU_21_H
#define __INC_MUZIO_VU_21_H
#include <Arduino.h>
#include <FastLED.h>
#include <math.h>
#include "vu15.h"

/*
 * Looks like fire! Both channels are seperate and random
 */

void fireblu()
{
  const uint8_t COOLING = 55;
  const uint8_t SPARKING = 50;

  // Array of temperature readings at each simulation cell
  static byte heatLeft[N_PIXELS];
  static byte heatRight[N_PIXELS];

  // Step 1.  Cool down every cell a little
  for (int i = 0; i < N_PIXELS; i++)
  {
    heatLeft[i] = qsub8(heatLeft[i], random8(0, ((COOLING * 10) / N_PIXELS) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for (int k = N_PIXELS - 1; k >= 2; k--)
  {
    heatLeft[k] = (heatLeft[k - 1] + heatLeft[k - 2] + heatLeft[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if (random8() < SPARKING)
  {
    int y = random8(7);
    heatLeft[y] = qadd8(heatLeft[y], random8(160, 255));
  }

  // Step 4.  Map from heat cells to LED colors
  for (int j = 0; j < N_PIXELS; j++)
  {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heatLeft[j], 240);
    CRGB color = ColorFromPalette(CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White), colorindex);
    int pixelnumber = j;
    ledsLeft[pixelnumber] = color;
  }

  // Now do it all again for the right channel
  // Step 1.  Cool down every cell a little
  for (int i = 0; i < N_PIXELS; i++)
  {
    heatRight[i] = qsub8(heatRight[i], random8(0, ((COOLING * 10) / N_PIXELS) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for (int k = N_PIXELS - 1; k >= 2; k--)
  {
    heatRight[k] = (heatRight[k - 1] + heatRight[k - 2] + heatRight[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if (random8() < SPARKING)
  {
    int y = random8(7);
    heatRight[y] = qadd8(heatRight[y], random8(160, 255));
  }

  // Step 4.  Map from heat cells to LED colors
  for (int j = 0; j < N_PIXELS; j++)
  {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heatRight[j], 240);
    CRGB color = ColorFromPalette(CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White), colorindex);
    int pixelnumber = j;
    ledsLeft[pixelnumber] = color;
  }
  FastLED.show();
}

#define COOLING 55
#define SPARKING 120
CRGBPalette16 gPal = HeatColors_p;
bool gReverseDirection = false;

void Fire2012()
{
// Array of temperature readings at each simulation cell
  static uint8_t heat[N_PIXELS];

  // Step 1.  Cool down every cell a little
    for( int i = 0; i < N_PIXELS; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / N_PIXELS) + 2));
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= N_PIXELS - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < SPARKING ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < N_PIXELS; j++) {
      CRGB color = HeatColor( heat[j]);
      int pixelnumber;
      if( gReverseDirection ) {
        pixelnumber = (N_PIXELS-1) - j;
      } else {
        pixelnumber = j;
      }
      ledsLeft[pixelnumber] = color;
    }
}

void fire()
{
  Fire2012(); // run simulation frame, using palette colors

  FastLED.show(); // display this frame
  FastLED.delay(1000 / 60);
}

#endif // __INC_MUZIO_VU_16_H