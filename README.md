# AtoD
Library to convert analog pins to digital pins Arduino/ATMEGA328P-PU

Convert analog input pins of PORTC in digital outputs
* PORTC -> bit 7 -> NONE
* PORTC -> bit 6 -> NONE
* PORTC -> bit 5 -> PC5/A5/19 [I2C (SCL)]
* PORTC -> bit 4 -> PC4/A4/18 [I2C (SDA)] 
* PORTC -> bit 3 -> PC3/A3/17
* PORTC -> bit 2 -> PC2/A2/16
* PORTC -> bit 1 -> PC1/A1/15
* PORTC -> bit 0 -> PC0/A0/14

Functions
1. Convert_All()
2. Select_Pin()
3. N_Pins()
4. ADC_PortC()

Usage

1. Convert_All() 

```C++
#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
  AD.Convert_All();
}
void loop() {
}
```
2. Select_Pin()
```C++
#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
 AD.Select_Pin(14, 0, 1, 1);
}
void loop() {
}
```
