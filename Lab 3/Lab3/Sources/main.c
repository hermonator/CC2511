/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MK22F51212.h"
#include <stdbool.h>

void waitabit();
void BlankLED();

static int i = 0;

void BlankLED(){
	waitabit();
	GPIOA_PSOR = 0b110;
	GPIOD_PSOR = 0b100000;
}


void waitabit(){
	int counter;
	for (counter = 0; counter < 100000; counter++) {}
}

int main(void)
{

    /* Write your code here */

	// Enable the clock for the port control module
	SIM_SCGC5 |= 0x3e00;

	PORTA_PCR1 = 0X100;
	PORTA_PCR2 = 0X100;
	PORTD_PCR5 = 0X100;

	GPIOA_PDDR = 0b110;
	GPIOD_PDDR = 0b100000;

	BlankLED();


    /* This for loop should be replaced. By default this loop allows a single stepping. */
    for (;;) {

    	// Red
    		GPIOA_PCOR = 0b010;
    		BlankLED();
    	// Green
    		GPIOA_PCOR = 0b100;
    		BlankLED();
    	// Blue
    		GPIOD_PCOR = 0b100000;
    		BlankLED();
    	// Yellow
    		GPIOA_PCOR = 0b110;
    		BlankLED();
    	// Purple
    		GPIOA_PCOR = 0b010;
    		GPIOD_PCOR = 0b100000;
    		BlankLED();
    	// Cyan
    		GPIOA_PCOR = 0b110;
    		GPIOD_PCOR = 0b100000;
    		BlankLED();
    	// White
    		GPIOA_PCOR = 0b110;
    		GPIOD_PCOR = 0b100000;
    		BlankLED();



        i++;
        //GPIOD_PCOR = 0b100;
    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
