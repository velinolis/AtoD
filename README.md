# AtoD
*Library to convert analog pins to digital pins Arduino/ATMEGA328P-PU*

Convert analog input pins of PORTC in digital outputs
* PORTC -> bit 7 -> NONE
* PORTC -> bit 6 -> NONE
* PORTC -> bit 5 -> PC5/A5/19 [I2C (SCL)]
* PORTC -> bit 4 -> PC4/A4/18 [I2C (SDA)] 
* PORTC -> bit 3 -> PC3/A3/17
* PORTC -> bit 2 -> PC2/A2/16
* PORTC -> bit 1 -> PC1/A1/15
* PORTC -> bit 0 -> PC0/A0/14

## Functions

**1. Convert_All()** 

Convert all pins (14-17/A0-A3), excluded pin A4 (SDA) and pin A5 (SCL) of I2C protocol.


**2. Select_Pin()**

Convert selected pin **AD.Select_Pin(0, 0, 0, 0);** 

A/D|pin A0/14 | pin A1/15 | pin A2/16 | pin A3/17
------------ | ------------- | ------------ |------------ |------------
digital |14 or 1 | 15 or 1 |16 or 1 | 17 or 1
analog | 0 | 0  | 0 | 0

```C++
//Convert to digital pin 14 and 16
AD.Select_Pin(14, 0, 16, 0);
AD.Select_Pin(1, 0, 1, 0);
AD.Select_Pin(1, 0, 16, 0);
AD.Select_Pin(14, 0, 1, 0);
```


**3. N_Pins()**

Convert number of pins (1-4), **AD.N_Pins(n);**

n = 1 to 4 

n = 0 -> don't convert

n > 4 -> n = 4

```C++
//Convert to digital 1 pin (A0), 2 pins (A0, A1), 3 pins(A0, A1, A2), 4 pins (A0, A1, A2, A3)
AD.N_Pins(1)
AD.N_Pins(2)
AD.N_Pins(3)
AD.N_Pins(4)
```

**4. ADC_PortC()**

 Convert pins A0 - A3 input analog to output digital
 using less flash memory.
 
 bit | bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 
 ------------ | ------------- | ------------ |------------   |------------  |------------  |------------  |------------  |------------ 
pin  | NONE |NONE|A5/19 I2C (SCL) |A4/18 I2C (SDA) |A3/17|A2/16 |A1/15 |A0/14 
DDRC |0|0|0|0|1|1|1|1
PORTC |0|0|0|0|0|0|0|0
 
 DDRC (Data Direction Register) -> 0 logic = INPUT / 1 logic = OUTPUT
 
 PORTC (Pin Output Register) -> 0 = LOW = 0v / 1 = HIGH = 5v
 
## Usage

**1. Convert_All()** 

```C++
#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
  AD.Convert_All();
}
void loop() {
}
```
**2. Select_Pin()**
```C++
#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
 AD.Select_Pin(14, 0, 1, 1);
}
void loop() {
}
```

**3. N_Pins()**
```C++
#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
 AD.N_Pins(2);
}
void loop() {
}
```

**4. ADC_PortC()**
```C++
#include "AnalogtoDigital.h"
AnalogtoDigital AD;

void setup() {
  AD.ADC_PortC();
}
void loop() {
}
```
