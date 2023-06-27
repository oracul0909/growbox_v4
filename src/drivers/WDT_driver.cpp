#include "WDT_driver.h"
#include "avr/wdt.h"

void WDT_INI()
{
    pinMode(_CFG_WDT_DRIVER_PORT, OUTPUT);
}

void WDT_RESET()
{
  digitalWrite(_CFG_WDT_DRIVER_PORT, !digitalRead(_CFG_WDT_DRIVER_PORT));
}

void WDT_AUTORESET()
{ 
  wdt_enable(WDTO_500MS);
  while(1)
  {
    /// ждем перезапуска
  }
}
