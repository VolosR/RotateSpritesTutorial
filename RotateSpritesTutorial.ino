#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite back = TFT_eSprite(&tft);
TFT_eSprite needle = TFT_eSprite(&tft);

void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setPivot(85,85);
  needle.createSprite(20,80);
  back.createSprite(170,170);
 
}

int angle=0;

void loop() {
  back.fillSprite(TFT_BLACK);
  back.fillCircle(85,85,85,TFT_SILVER);
  needle.fillSprite(TFT_BLACK);
  needle.drawWedgeLine(10,0,10,40,1,10,TFT_RED);
  needle.drawWedgeLine(10,40,10,80,10,1,TFT_BLUE);
  needle.fillCircle(10,40,10,TFT_WHITE);
  needle.pushRotated(&back,angle,TFT_BLACK);
  back.pushSprite(0,0);
  angle++;
  if(angle==360)
  angle=0;

}
