#include "imagedata.h"
#include "epd7in3f.h"

Epd epd;

void setup(){
  ESP.wdtEnable(65535);

  Serial.begin(115200); 
  
  if (epd.Init() != 0) {
    Serial.println("e-Paper init failed");
    return;
  }

  Serial.println("e-Paper Clear");
  epd.Clear(EPD_7IN3F_WHITE);  

  Serial.println("Show pic");
  epd.EPD_7IN3F_Display_part(gImage_7in3f, 250, 150, 300, 180);
  delay(10000);

  Serial.println("draw 7 color block");
  epd.EPD_7IN3F_Show7Block();

  Serial.println("epd sleep");
  epd.Sleep();
}

void loop(){
}


