#include "Water_tank.h"

int Water_tank::get_state()
{
    //переделать потом на побитовую матрицу состояний
    if(Control.get_state() == true)
    {
        if(Low_switch.get_state() == true)
        {
            if(Normal_switch.get_state() == true)
            {
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