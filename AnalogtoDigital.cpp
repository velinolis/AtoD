/*
  ---------------------------
  # AnalogtoDigital library #
  ---------------------------
  Library to convert analog pins to digital pins Arduino/ATMEGA328P-PU
   
  pin A0 = 14
  pin A1 = 15
  pin A2 = 16
  pin A3 = 17
  pin A4 = 18 (excluded) --> I2C SDA
  pin A5 = 19 (excluded) --> I2C SCL

*/

#include "AnalogtoDigital.h"
#include "Arduino.h"

AnalogtoDigital::AnalogtoDigital() {}

void AnalogtoDigital::Convert_All() {
  int limit = (sizeof(NPin) / sizeof(NPin[0]));
  for (int NPins = 0; NPins < limit; NPins++) {
    pinMode(NPin[NPins], OUTPUT);
    digitalWrite(NPin[NPins], LOW);
  }
}

void AnalogtoDigital::Select_Pin(int pin1, int pin2, int pin3, int pin4) {
  
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
  
  if (_pin1 == 14 || _pin1 == 1) {
    pinMode(NPin[0], OUTPUT);
    digitalWrite(NPin[0], LOW);
  }
  if (_pin2 == 15 || _pin2 == 1) {
    pinMode(NPin[1], OUTPUT);
    digitalWrite(NPin[1], LOW);
  }
  if (_pin3 == 16 || _pin3 == 1) {
    pinMode(NPin[2], OUTPUT);
    digitalWrite(NPin[2], LOW);
  }
  if (_pin4 == 17 || _pin4 == 1) {
    pinMode(NPin[3], OUTPUT);
    digitalWrite(NPin[3], LOW);
  }
}

void AnalogtoDigital::N_Pins(int numpin) {
  _numpin = numpin;
  if (_numpin > 4) _numpin = 4;
  for (int Npins = 0; Npins < _numpin; Npins++) {
    pinMode(NPin[Npins], OUTPUT);
    digitalWrite(NPin[Npins], LOW);
  }
}

void AnalogtoDigital::ADC_PortC() {
  /*
    Convert pins A0 - A3 input analog to output digital
    using less flash memory

                                  DDRC   PORTC
    bit 7-> None                   0       0
    bit 6-> None                   0       0
    bit 5-> A5 I2C (SCL) / 19      0       0
    bit 4-> A4 I2C (SDA) / 18      0       0
    bit 3-> A3 / 17                1       0
    bit 2-> A2 / 16                1       0
    bit 1-> A1 / 15                1       0
    bit 0-> A0 / 14                1       0

    DDRC(I/0) , PORTC (H/L) -> 0 = input/LOW , 1 = output/HIGH
  */

  DDRC = DDRC | B00001111;
  PORTC = PORTC | B00000000;

}
