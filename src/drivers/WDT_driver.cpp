#include "WDT_driver.h"
#include "avr/wdt.h"

void WDT_INI()
{
  wdt_enable(WDTO_4S);
}

void WDT_RESET()
{
  wdt_reset();
}

void WDT_AUTORESET()
{ 
  wdt_enable(WDTO_500MS);
  while(1)
  {
    /// ждем перезапуска
  }
}
