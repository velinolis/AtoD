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

Convert all pins (14-17/A0-A3), excluded pin A4 (SDA) and pin A5 (SCL) of I2C protocol.


2. Select_Pin()

Convert selected pin **AD.Select_Pin(0, 0, 0, 0);** 

A/D|pin A0/14 | pin A1/15 | pin A2/16 | pin A3/17
------------ | ------------- | ------------ |------------ |------------
digital |14 or 1 | 15 or 1 |16 or 1 | 17 or 1
analog | 0 | 0  | 0 | 0

```C++
//Convert todigital pin 14 and 16
AD.Select_Pin(14, 0, 16, 0);
AD.Select_Pin(1, 0, 1, 0);
AD.Select_Pin(1, 0, 16, 0);
AD.Select_Pin(14, 0, 1, 0);
```


3. N_Pins()


4. ADC_PortC()

 Convert pins A0 - A3 input analog to output digital
 using less flash memory.
 
 bit | pin  | DDRC | PORTC
 ------------ | ------------- | ------------ |------------  
 bit 7 | NONE | 0| 0
 bit 6 | NONE | 0| 0
 bit 5 |A5/19 I2C (SCL)| 0| 0
 bit 4 |A4/18 I2C (SDA)| 0| 0
 bit 3 |A3/17 | 1 | 0
 bit 2 |A2/16 | 1 | 0
 bit 1 |A1/15 | 1 | 0
 bit 0 |A0/14 | 1 | 0
 
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
4. ADC_PortC()
```C++
#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
  AD.ADC_PortC();
}
void loop() {
}
```
