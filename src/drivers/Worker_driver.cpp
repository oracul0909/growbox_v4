#include "Worker_driver.h"

void Worker_driver::run(int work, int pause, int time)
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