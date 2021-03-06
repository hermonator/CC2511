/* ###################################################################
**     Filename    : main.c
**     Project     : Lab5JesseHermon
**     Processor   : MK22FN512VDC12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-08-24, 08:26, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "sensor.h"
#include "BitIoLdd1.h"
#include "Blue.h"
#include "PwmLdd2.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "REDdim.h"
#include "PwmLdd1.h"
#include "TU1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include <stdbool.h>
/* User includes (#include below this line is not maintained by Processor Expert) */
void send_string(char *str)
{

	int i;
	byte err,c;
	unsigned int len; // a size_t is an unsigned integer

	len =  strlen(str); // returns the number of chars in str
	for(i =  0;  i <  len  ;  i++) {
//   send this character
		do   {
			c = str[i];
			err =  AS1_SendChar(c);
		} while (err != ERR_OK);
	}
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  byte err,c;
  /* For example: for(;;) { } */
  bool is_on = false;
  //char *on = "pull-up on";
  //char *off = "pull-up off";
  char *newLine = "\n";
  char *startLine ="\r";
  int brightness = 0;

  Green_SetVal();
    for(;;){

    	err = AS1_RecvChar(&c);

    	if(err != ERR_OK){

			//Blue_PutVal(sensor_GetVal());

			if(c == 'b'){
				/*if(!is_on){
					send_string(on);
					send_string(newLine);
					send_string(startLine);
					is_on = true;
					PORTB_PCR19 ^= 0b11;
				}else{
					send_string(off);
					send_string(newLine);
					send_string(startLine);
					is_on = false;
					PORTB_PCR19 ^= 0b00;
				}*/
				brightness -= 20;
				BLUE_SetRatio8(brightness);
			} else if(c == 'r'){
				brightness -= 20;
				REDdim_SetRatio8(brightness);
			} else if(c == 'R'){
				brightness += 20;
				REDdim_SetRatio8(brightness);
			} else if(c == 'g'){

			} else if(c == 'G'){

			}
			c = 'a';
    	}


    }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
