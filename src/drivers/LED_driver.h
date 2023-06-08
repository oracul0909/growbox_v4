#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <Arduino.h>

class LED_driver
{
private:
    int pin;
    uint8_t intencity_index = 0;
    uint8_t intencity_index_new = 0;
    uint8_t work_mode;
    uint8_t intencity_steps[11] {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

public:
    LED_driver(int _pin)
    {
        pin = _pin;
    }

    //Устанавливает уровень яркость в процентах
    void set_bright(uint8_t _bright_new);

    void change_bright();

    //Устанавливает режим работы лампы
    void set_work_mode(uint8_t _work_mode);

    uint8_t get_work_mode();
};

#endif