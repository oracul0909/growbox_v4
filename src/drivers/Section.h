#ifndef SECTION_H
#define SECTION_H

#include "LED_driver.h"

class Section
{
private:
int white_pin;
int fito_pin;
int pump_pin;
LED_driver LED_white{white_pin};
LED_driver LED_fito{fito_pin};

public:
Section(int _white_pin, int _fito_pin, int _pump_pin)
{
    white_pin = _white_pin;
    fito_pin = _fito_pin;
    pump_pin = _pump_pin;
}

void white_control();

void fito_control();
};

#endif