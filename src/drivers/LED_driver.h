#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <Arduino.h>

class LED_driver
{
private:
    uint8_t pin;
    uint8_t intencity_index = 0;
    uint8_t intencity_index_new = 0;
    uint8_t intencity_steps[11] {0, 30, 50, 80, 100, 120, 150, 180, 200, 230, 255};

public:
    LED_driver(uint8_t _pin)
    {
        pin = _pin;
        pinMode(pin, OUTPUT);
    }
    
    /// @brief Устанавливает уровень яркости лампы
    /// @param _bright_new Значение яркости (%)
    void set_bright(uint8_t _bright_new);

    //Изменяет яркость лампы по заданному шагу
    void change_bright(void);

    bool get_state(void);
};

#endif