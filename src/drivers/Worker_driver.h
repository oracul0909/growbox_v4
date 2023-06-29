#ifndef WORKER_DRIVER_H
#define WORKER_DRIVER_H

#include <Arduino.h>

class Worker_driver
{
private:
    uint8_t pin;
    uint16_t time_new;
    bool timer_flag;
    bool worker_flag;

public:
    Worker_driver(uint8_t _pin)
    {
       pin = _pin;
       pinMode(pin, OUTPUT);
    }

    /// @brief цикл работы устройства
    /// @param work время работы(мин)
    /// @param pause время паузы(мин)
    /// @param time время системы(мин)
    void work_on_time(uint16_t work, uint16_t pause, uint16_t time);

    void run(bool flag);

    bool get_state(void);
};

#endif