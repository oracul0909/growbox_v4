#ifndef CLIMATE_SYSTEM_H
#define CLIMATE_SYSTEM_H

#include "drivers/Worker_driver.h"

class Climate_system
{
private:
    int heater_pin;
    int cooler_pin;
    int humidifier_pin;
    int fan_inside_pin;
    int fan_outside_pin;

public:
    //объекты обогревателя, охладителя, увлажнятора и вентиляторов
    Worker_driver Heater{heater_pin};
    Worker_driver Cooler{cooler_pin};
    Worker_driver Humidifier{humidifier_pin};
    Worker_driver Fan_inside{fan_inside_pin};
    Worker_driver Fan_outside{fan_outside_pin};

    //конструкторы и методы
    Climate_system(int _heater_pin,
                   int _cooler_pin,
                   int _humidifier_pin,
                   int _fan_inside_pin,
                   int _fan_outside_pin)
    {
        heater_pin = _heater_pin;
        cooler_pin = _cooler_pin;
        humidifier_pin = _humidifier_pin;
        fan_inside_pin = _fan_inside_pin;
        fan_outside_pin = _fan_outside_pin;
    }
};

#endif