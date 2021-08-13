#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
  //AD.Convert_All();
  //AD.Select_Pin(14, 0, 1, 1);
  //AD.N_Pins(2);
  AD.ADC_PortC();
}

void loop() {
  //PINC = bit (0);
  //PINC = bit (1);
}
