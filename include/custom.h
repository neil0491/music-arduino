#ifndef __INC_MUZIO_CUSTOM_H
#define __INC_MUZIO_CUSTOM_H

///////////////////////////////////////////////////////////////////
// This file contain all custom only things related to platform
///////////////////////////////////////////////////////////////////

#define N_PIXELS 30         // Number of pixels in strand
#define BRIGHTNESS 255      // 0 - 255 value (255 == Max)
#define LED_TYPE WS2811 // Only use the LED_PIN for WS2812's
#define COLOR_ORDER RGB

#define MIC_PIN A2          // Microphone is attached to this analog pin
#define LED_PIN 4           // NeoPixel LED strand is connected to this pin

#define MUZIO_DEBUG 0       // 1 to DEBUG, 0 to disable


#endif //__INC_MUZIO_CUSTOM_H