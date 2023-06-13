#ifndef WATER_TANK_H
#define Water_TANK_H

#include "drivers/Reed_switch_driver.h"
#include "Data.h"

class Water_tank
{
private:
    int control_pin;
    int normal_pin;
    int low_pin;

    Reed_switch_driver Control{control_pin};
    Reed_switch_driver Normal_switch{normal_pin};
    Reed_switch_driver Low_switch{low_pin};

public:
    Water_tank(int _control_pin, int _low_pin, int _normal_pin)
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