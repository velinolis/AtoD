#ifndef ANALOGTODIGITAL_H
#define ANALOGTODIGITAL_H

class AnalogtoDigital
{
  private:
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _numpin;
    int NPin[4] = {14, 15, 16, 17};
  public:
    AnalogtoDigital();
    void Convert_All();
    void Select_Pin(int pin1, int pin2, int pin3, int pin4);
    void N_Pins(int numpin);
};
#endif
