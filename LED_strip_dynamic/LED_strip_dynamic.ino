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

bool on; // toggle lights on/off


// todo:set up a doubly-linked list
// to make handling of LEDs easier


class my_class {
  public:
    void reset_my_int(int);
    int get_my_int();
    void ramp_my_int();
  private:
    int my_int;
};

void my_class::reset_my_int(int foo) {
  my_class::my_int = foo;
}


CRGB leds[NUM_LEDS]; // Initialize CRGB array
int8_t FULL = 255; // Max output


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

int8_t blah = 0;
void loop() {
  my_class foo;

  on = on ? 0 : 1;
  blah++;
  
  CRGB asdf = CRGB(random(255), random(255), random(255));

  CRGB fdsa = CRGB(0,0,0);
  do {fdsa = CRGB(random(255), random(255), random(255));}
  while ((asdf[1]-fdsa[1]) > 200 && (asdf[2]-fdsa[2]) > 200 && (asdf[3]-fdsa[3]) > 200);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    //foo.ramp_my_int();
    if (i % 2 == 0)
      leds[i] = asdf;
    else
      leds[i] = fdsa;

  }
  FastLED.show(); // Update LEDs
  delay(3000);
}
