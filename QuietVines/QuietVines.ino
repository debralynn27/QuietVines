//Quick sketch to have lights for cut.shred event
// Debra Lemak 04/28/18
#include "FastLED.h"

#define NUM_LEDS 5      
#define ledpin 4               

CRGB strand1[NUM_LEDS];

TBlendType blendingType; 
//tBlendType is a data type like int/char/uint8_t etc., used to choose LINERBLEND and NOBLEND/
//////////////////////////////////////////////
void setup(){
  delay(2000);                                      // saftey first  
  FastLED.addLeds<WS2811,ledpin,RGB>(strand1,NUM_LEDS);   
  fill_solid(strand1, NUM_LEDS, CRGB(0,0,0));         // fill all black
  FastLED.show();                                   // show 
  blendingType = LINEARBLEND;                       // options are LINEARBLEND or NOBLEND - linear is 'cleaner'
}
/////////////////////////////////////////////
void loop(){
  aquapaint ();
  addYellowGlitter(8);
  FastLED.show();
  delay(50);
  }
 
////////////////////////////////////////////

void addYellowGlitter( fract8 chanceOfGlitter) {
  if( random8() < chanceOfGlitter) {
    strand1[ random16(NUM_LEDS) ] += CRGB::Yellow;
  }
}

void aquapaint (){
    for( int i = 0; i < NUM_LEDS; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Green, amountOfBlending);
    strand1[i] = pixelColor;
  }}

