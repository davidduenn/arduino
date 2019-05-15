// From: https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/
// Also see: https://www.hackster.io/bportaluri/web-controlled-led-animations-with-raspberry-pi-and-arduino-112025

// FastLED library import
#include <FastLED.h>
#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>
// /FAstLED library import

#define LED_PIN     7
#define NUM_LEDS    150

CRGB leds[NUM_LEDS]; // Initialize CRGB array

enum COLOR {red, green, blue};
int rgb = red; // Holder for current color for RGB_BULLET: red(0), green(1), or blue(2).

int FULL = 255; // Max output
int BULLET_LENGTH = 150;
// Arduino: 500mA output. Each LED (rgb): 20mA. Full LED package (white): 60mA
// Don't exceed 8LEDs @ 100% power or 24LEDs @ 33% power (1 color)

// Choose one
bool RGB_BULLET = 0;
bool RANDOM_BULLET = 1;


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}


void loop() {
  for(int i=0; i<NUM_LEDS+BULLET_LENGTH; i++){
    // Update LED array values
    if(RGB_BULLET) leds[i] = CRGB((rgb==red?FULL:0),(rgb==green?FULL:0),(rgb==blue?FULL:0));
    else if(RANDOM_BULLET) leds[i] = CRGB(random(FULL),random(FULL),random(FULL));

    // Turn off LEDs in the back
    if(i>(BULLET_LENGTH-1)){
      leds[i-BULLET_LENGTH] = CRGB(0,0,0);
    }

    // Update LEDs
    FastLED.show();
    delay(50);
  }

  // Switch color for RGB_BULLET
  if(RGB_BULLET) switch_color(rgb);
}


void switch_color(int &rgb){
  if(rgb==blue) rgb=red; // Wrap
  else rgb++; // Next color
}
