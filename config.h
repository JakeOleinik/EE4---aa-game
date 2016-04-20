/*********************************************************************
 *
 *                  EE 4 Project - Code Template
 *
 *********************************************************************
 * Processor:       PIC18F2550
 * Compiler:        XC8 1.35+
 * Author:          Jeroen Van Aken
 * Updated:         17/02/2016
 ********************************************************************/

#ifndef _CONFIG_H
#define _CONFIG_H

/** I N C L U D E S *************************************************/
#include <xc.h>
//#include "func_pwm.h"

/** D E F I N E S ***************************************************/
#define TRUE 1
#define FALSE 0

/** P U B L I C   V A R I A B L E S *********************************/
// when a variable is declared 'extern' it also has to be declared in
// the corresponding .c file without the 'extern' keyword


/** P U B L I C   P R O T O T Y P E S *******************************/
void hardware_init(void);
unsigned char timed_to_1ms(void);
void interrupt interrupt_handler(void);

#endif
//EOF----------------------------------------------------------------
