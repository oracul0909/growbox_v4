#include "Water_tank.h"

extern uint16_t data_array[last_val_1];

//#define Extern_data(x) data_array[x]


//переделать потом на побитовую матрицу состояний
int Water_tank::get_state()
{
    if(Control.get_state() == true)
    {
        if(Low_switch.get_state() == true)
        {
            if(Normal_switch.get_state() == true)
            {
                data_array[data_2];
                return 3;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}