#ifndef CLIMATE_SYSTEM_H
#define CLIMATE_SYSTEM_H

#include "drivers/Worker_driver.h"

class Climate_system
{
private:
    uint8_t heater_pin;
    uint8_t cooler_pin;
    uint8_t humidifier_pin;
    uint8_t fan_inside_pin;
    uint8_t fan_outside_pin;

public:
    //объекты обогревателя, охладителя, увлажнятора и вентиляторов
    Worker_driver Heater{heater_pin};
    Worker_driver Cooler{cooler_pin};
    Worker_driver Humidifier{humidifier_pin};
    Worker_driver Fan_inside{fan_inside_pin};
    Worker_driver Fan_outside{fan_outside_pin};

    //конструкторы и методы
    Climate_system(uint8_t _heater_pin,
                   uint8_t _cooler_pin,
                   uint8_t _humidifier_pin,
                   uint8_t _fan_inside_pin,
                   uint8_t _fan_outside_pin)
    {
        heater_pin = _heater_pin;
        cooler_pin = _cooler_pin;
        humidifier_pin = _humidifier_pin;
        fan_inside_pin = _fan_inside_pin;
        fan_outside_pin = _fan_outside_pin;
    }

    void cool_down();

    void warm_up();

    void humidify();

    void drain();

    void stop();
};

#endif