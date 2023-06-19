#include "Worker_driver.h"

void Worker_driver::work_on_time(uint16_t work, uint16_t pause, uint16_t time)
{
    if(time_new <= time)
        {
            timer_flag = !timer_flag;
        }
    if(timer_flag == true && worker_flag == false)
    {
        time_new = time + work;
        worker_flag = true;
        digitalWrite(pin, worker_flag);
    }
    else if (timer_flag == false && worker_flag == true)
    {
        time_new = time + pause;
        worker_flag = false;
        digitalWrite(pin, worker_flag);
    }
}

void Worker_driver::run(bool flag)
{
    digitalWrite(pin, flag);
}

void Worker_driver::stop()
{
    worker_flag = false;
    digitalWrite(pin, worker_flag);
}

bool Worker_driver::get_state()
{
    return worker_flag;
}