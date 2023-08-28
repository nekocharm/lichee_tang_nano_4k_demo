#include "delay.h"

uint32_t fac_ms=0; 

void delay_init(void)
{
  SystemInit();
  SystemCoreClockUpdate();        //可以省略
}

void SysTick_Handler(void)
{
  if(fac_ms) fac_ms--;
}

void delay(uint32_t nms)
{
  SysTick_Config(SystemCoreClock / 1000);     //定时1ms
  fac_ms = nms;
  while(fac_ms != 0);
}
