#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel
 
#define PIN D2         // led in과 연결하는 D1 mini 핀번호
#define STRIPSIZE 7    // led 개수
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(25);  // Lower brightness and save eyeballs!
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() {
  // for each pixel set color to red. Wait 100ms between each individual pixel.
  
  int r=0,g=0,b=0;
    for(r=0;r<256;r+= 20) {
      for(g=0;g<256;g+= 20) {
        for(b=0;b<256;b+= 20) {
          for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, strip.Color(r, g, b));
            strip.show();
            delay(10);
          }
          char s[30];
          sprintf(s,"%d  %d  %d",r,g,b);
          Serial.println(s);
        }
      }
  }
}
