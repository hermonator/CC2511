/* ###################################################################
**     Filename    : main.c
**     Project     : LAb7
**     Processor   : MK22FN512VDC12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-09-14, 09:33, # CodeGen: 0
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
#include "RED.h"
#include "PwmLdd1.h"
#include "Green.h"
#include "PwmLdd2.h"
#include "TU1.h"
#include "Blue.h"
#include "PwmLdd3.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include <stdbool.h>
#include "string.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
void MenuDisplay(){


	Term1_SetColor(clWhite,clBlack);
	Term1_Cls();
	Term1_MoveTo(0,0);
	Term1_SetColor(clWhite,clBlack);
	Term1_SendStr("CC2511 Lab 7 Jesse Hermon");
	Term1_SendStr("\n");
	Term1_SendStr("\n");
	Term1_SendStr("\r");
	Term1_SetColor(clBlack,clYellow);
	Term1_SendStr("+--[ PWM Status ]--+ +-----------------[ How to use ]-----------------+");
	Term1_SetColor(clWhite,clBlack);
	Term1_SendStr("\n");
	Term1_SendStr("\r");;
	Term1_SetColor(clBlack,clYellow);
	Term1_SendStr(" ");
	Term1_SetColor(clWhite,clBlack);
	Term1_SendStr("                                                                     ");
	Term1_SetColor(clBlack,clYellow);
	Term1_SendStr(" ");

}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  	  MenuDisplay();
  /* Write your code here */
    byte err,c;
    /* For example: for(;;) { } */
    bool is_on = false;
    char *newLine = "\n";
    char *startLine ="\r";
    __asm ("wfi");

    int brightness = 0;

      for(;;){

      	//err = AS1_RecvChar(&c);

      	if(err != ERR_OK){



  			if(c == 'b'){
  				brightness += 20;
  				Blue_SetRatio8(brightness);
  			}else if(c == 'B'){
  				brightness -= 20;
  				Blue_SetRatio8(brightness);
  			} else if(c == 'R'){
  				brightness -= 20;
  				RED_SetRatio8(brightness);
  			} else if(c == 'r'){
  				brightness += 20;
  				RED_SetRatio8(brightness);
  			} else if(c == 'g'){
  				brightness += 20;
  				Green_SetRatio8(brightness);
  			} else if(c == 'G'){
  				brightness -= 20;
  				Green_SetRatio8(brightness);
  			}
  			c = ' ';
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
