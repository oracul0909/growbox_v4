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
    uint16_t time_new;
    bool timer_flag;
    bool worker_flag;

    // | нагрев | охлад | увлажн | вент.внутр | вент.наруж |
    byte mask = B00000;

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

    /// @brief Система охлаждения
    /// @param work_time Время работы охладителя (мин)
    /// @param pause_time Время паузы охладителя (мин)
    void cool_down(uint16_t work_time, uint16_t pause_time);

    /// @brief Система подогрева
    /// @param work_time Время работы нагревателя (мин)
    /// @param pause_time Время паузы нагревателя (мин)
    void warm_up(uint16_t work_time, uint16_t pause_time);

    //Система увлажнения
    void humidify();
    
    /// @brief Система охлаждения
    /// @param work_time Время работы охладителя (мин)
    /// @param pause_time Время работы нагревателя (мин)
    void drain(uint16_t freeze_time, uint16_t defrost_time);

    //Запускает устройства системы по заданным условиям
    void system_run();

    void devices_status();
};

#endif