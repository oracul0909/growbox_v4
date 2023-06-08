#include "Section.h"
#include "Data.h"

extern Data_struct Data;
extern Settings_struct Settings;

void Section::white_control()
{
    if(LED_white.get_work_mode() > 0)
    {
        LED_white.set_bright(Settings.white_reqired);
    }//code
}
void Section::fito_control()
{
    //code
}