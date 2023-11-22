#include "WDT_driver.h"
#include "avr/wdt.h"

void WDT_INI()
{
    pinMode(_CFG_WDT_DRIVER_PORT, OUTPUT);
    pinMode(_CFG_WDT_DRIVER_PORT+1, OUTPUT);
    digitalWrite(_CFG_WDT_DRIVER_PORT, HIGH);
    digitalWrite(_CFG_WDT_DRIVER_PORT+1, HIGH);
}

void WDT_AUTORESET()
{ 
    wdt_enable(WDTO_500MS);
    digitalWrite(_CFG_WDT_DRIVER_PORT, LOW);
    digitalWrite(_CFG_WDT_DRIVER_PORT+1, LOW);
  while(1)
  {
    /// ждем перезапуска
  }
}
