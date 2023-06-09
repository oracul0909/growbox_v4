#ifndef SECTION_H
#define SECTION_H

#include "LED_driver.h"
#include "Worker_driver.h"

class Section
{
private:
    int white_pin;
    int fito_pin;
    int pump_pin;
    LED_driver LED_white{white_pin};
    LED_driver LED_fito{fito_pin};
    Worker_driver Pump{pump_pin};
    Section *General;

public:
    Section(int _white_pin, int _fito_pin, int _pump_pin)
    {
        white_pin = _white_pin;
        fito_pin = _fito_pin;
        pump_pin = _pump_pin;
    }

    Section(Section *_General, int _white_pin, int _fito_pin, int _pump_pin)
    {
        General = _General;
        white_pin = _white_pin;
        fito_pin = _fito_pin;
        pump_pin = _pump_pin;
    }

    void white_control(int intencity);

    void fito_control(int intencity);

    void pump_control(int work, int pause, int time);
};

#endif