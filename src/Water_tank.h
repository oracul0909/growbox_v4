#ifndef WATER_TANK_H
#define Water_TANK_H

#include "drivers/Reed_switch_driver.h"

class Water_tank
{
private:
    uint8_t control_pin;
    uint8_t normal_pin;
    uint8_t low_pin;

    Reed_switch_driver Control{control_pin};
    Reed_switch_driver Normal_switch{normal_pin};
    Reed_switch_driver Low_switch{low_pin};

public:
    Water_tank(uint8_t _control_pin, uint8_t _low_pin, uint8_t _normal_pin)
    {
       control_pin = _control_pin;
       normal_pin = _normal_pin;
       low_pin = _low_pin;
    }

    /// @brief Показывает состояние датчиков уровня воды в баке
    /// @return 0 - датчики не найдены,
    ///         1 - воды нет,
    ///         2 - воды мало,
    ///         3 - вода в норме
    int get_state();
};

#endif