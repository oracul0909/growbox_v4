#ifndef WORKER_DRIVER_H
#define WORKER_DRIVER_H

#include <Arduino.h>

class Worker_driver
{
private:
uint8_t pin;
uint8_t work_mode;
public:
Worker_driver(uint8_t _pin)
{
    pin = _pin;
}

//Устанавливает режим работы устройства
void set_work_mode(uint8_t _work_mode);

//цикл работы устройства
void run();
};

#endif