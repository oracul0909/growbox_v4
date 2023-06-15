#ifndef WORKER_DRIVER_H
#define WORKER_DRIVER_H

#include <Arduino.h>

class Worker_driver
{
private:
    uint8_t pin;
    int time_new;
    bool timer_flag;
    bool worker_flag;

public:
    Worker_driver(uint8_t _pin)
    {
        pin = _pin;
    }

    /// @brief цикл работы устройства
    /// @param work время работы(мин)
    /// @param pause время паузы(мин)
    /// @param time время системы(мин)
    void run(int work, int pause, int time);
};

#endif