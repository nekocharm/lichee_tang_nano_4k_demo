/*
 ******************************************************************************************
 * @file        main.c
 * @author      GowinSemiconductor
 * @device      Gowin_EMPU(GW1NS-4C)
 * @brief       Main program body.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"
#include "delay.h"
void GPIOInit(void);
/** @addtogroup GW1NS4C_StdPeriph_Template
  * @{
  */

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
     this is done through SystemInit() function which is called from startup
     file (startup_gw1ns4c.s) before to branch to application main.
     To reconfigure the default setting of SystemInit() function, refer to
     system_gw1ns4.c file
   */
  //SystemInit();
	delay_init();
	GPIOInit();

  /* Add your application code here */

  /* Infinite loop */
  while(1)
  {
		GPIO_ResetBit(GPIO0,GPIO_Pin_0);
    delay(500);

    GPIO_SetBit(GPIO0,GPIO_Pin_0);
    delay(500);
  }
}

void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_SetBit(GPIO0,GPIO_Pin_0);
}



#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */
/*************************GowinSemiconductor*****END OF FILE*********************/
