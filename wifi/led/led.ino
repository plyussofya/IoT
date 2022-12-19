#include <FastLED.h>
#define NUM_LEDS 15 
#define DATA_PIN 2
#define CLOCK_PIN 15

CRGB leds[NUM_LEDS];

void setup() { 
	Serial.begin(9600);
	FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
	FastLED.setBrightness(84);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() {
  static uint8_t hue = 0;
  if (Serial.available() > 0){
    char message = Serial.read();
    if(message == 'u'){
	    for(int i = 0; i < NUM_LEDS; i++) {
		    leds[i] = CHSV(hue++, 255, 255);
		    FastLED.show(); 
		    fadeall();
		    delay(10);
	  } 
  }
    else if (message == 'd'){
      for (int i = 0; i < 15; i++){
        leds[i] = CRGB::Black;  
      }
      FastLED.show();
      delay(500); 
    }
  }  
}
