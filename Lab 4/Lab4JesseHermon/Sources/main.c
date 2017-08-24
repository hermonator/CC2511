/* ###################################################################
**     Filename    : main.c
**     Project     : Lab4JesseHermon
**     Processor   : MK22FN512VDC12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-08-24, 08:30, # CodeGen: 0
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
#include "Red.h"
#include "BitIoLdd1.h"
#include "Green.h"
#include "BitIoLdd2.h"
#include "Blue.h"
#include "BitIoLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
void send_string(char *str)
{

	int i;
	byte err,c;
	unsigned int len; // a size_t is an unsigned integer

	len =  strlen(str  ); // returns the number of chars in str
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
	//PORTA_PCR1 = 0X100;
	//PORTA_PCR2 = 0X100;
	//PORTD_PCR5 = 0X100;
char *start = "Program Starting:";
char *nextLine = "\n";
char *startLine = "\r";
char *red = "Toggled Red";
char *green = "Toggled Green";
char *blue = "Toggled Blue";
send_string(start);
send_string(nextLine);
send_string(startLine);


	// PTA1/UART0 RX/FTM0 CH6 RED_LED
	// PTA2/UART0 TX/FTM0 CH7 GREEN_LED
  /* For example: for(;;) { } */
  byte c, err;

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){
	  do {
		  err = AS1_RecvChar(&c);
	  } while (err != ERR_OK);

	  if(c == 'r'){
		  send_string(red);
		  Red_NegVal();
		  send_string(nextLine);
		  send_string(startLine);
	  } else if(c == 'b'){
		  send_string(blue);
		  Blue_NegVal();
		  send_string(nextLine);
		  send_string(startLine);
	  } else if(c == 'g'){
		  send_string(green);
		  Green_NegVal();
		  send_string(nextLine);
		  send_string(startLine);}



  }
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
