#include "TM1638.h"

const int strobe = 7;
const int clock = 9;
const int data = 8;
TM1638Class TM1638;
uint8_t count = 0;
uint8_t button = 0;
uint32_t timeCounting = 0;


void setup()
{
  TM1638.init(clock, data, strobe);
  TM1638.setBrightness(TM1638_BRIGHTNESS_4_16);
  TM1638.displayNumberOnLed7Seg(TM1638_LED7SEG_POS0, 0);
  TM1638.displayNumberOnLed7Seg(TM1638_LED7SEG_POS1, 1);
  TM1638.displayNumberOnLed7Seg(TM1638_LED7SEG_POS2, 2);
  TM1638.displayNumberOnLed7Seg(TM1638_LED7SEG_POS3, 3);
  TM1638.displayNumberOnLed7Seg(TM1638_LED7SEG_POS4, 4);
}

void loop()
{
  button = TM1638.readButton();
  if (button == 0x01)
  {
    TM1638.displayOnLed(TM1638_LED_POS0, 1);
  }
  else if (button == 0x02)
  {
    TM1638.displayOnLed(TM1638_LED_POS1, 1);
  }
  else if (button == 0x04)
  {
    TM1638.displayOnLed(TM1638_LED_POS2, 1);
  }
  else if (button == 0x08)
  {
    TM1638.displayOnLed(TM1638_LED_POS3, 1);
  }
  else if (button == 0x10)
  {
    TM1638.displayOnLed(TM1638_LED_POS4, 1);
  }
  else if (button == 0x20)
  {
    TM1638.displayOnLed(TM1638_LED_POS5, 1);
  }
  else if (button == 0x40)
  {
    TM1638.displayOnLed(TM1638_LED_POS6, 1);
  }
  else if (button == 0x80)
  {
    TM1638.displayOnLed(TM1638_LED_POS7, 1);
  }
  else
  {
    TM1638.displayOnLed(TM1638_LED_POS0, 0);
    TM1638.displayOnLed(TM1638_LED_POS1, 0);
    TM1638.displayOnLed(TM1638_LED_POS2, 0);
    TM1638.displayOnLed(TM1638_LED_POS3, 0);
    TM1638.displayOnLed(TM1638_LED_POS4, 0);
    TM1638.displayOnLed(TM1638_LED_POS5, 0);
    TM1638.displayOnLed(TM1638_LED_POS6, 0);
    TM1638.displayOnLed(TM1638_LED_POS7, 0);
  }
  if (millis() - timeCounting >= 200)
  {
    timeCounting = millis();
    count++;
    if (count > 99) count = 0;
    TM1638.displayNumberOnLed7Seg(TM1638_LED7SEG_POS6, count / 10);
    TM1638.displayNumberOnLed7Seg(TM1638_LED7SEG_POS7, count % 10);
  }
}
