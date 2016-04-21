#include "pitches.h"
 


#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#define _XTAL_FREQ 47000000



void myDelay_us(unsigned int us);

void myDelay_ms(unsigned int ms);

void buzz(long freq, unsigned int duration);

void initBuzz(void);

void happyBirthday(void);

void nothingElseMatters(void);

void superMario(unsigned int index);

void starWars(unsigned int index);


unsigned int SuperMarioNotes[] = {
        NOTE_E7, NOTE_E7, 0, NOTE_E7,
        0, NOTE_C7, NOTE_E7, 0,
        NOTE_G7, 0, 0,  0,
        NOTE_G6, 0, 0, 0,

        NOTE_C7, 0, 0, NOTE_G6,
        0, 0, NOTE_E6, 0,
        0, NOTE_A6, 0, NOTE_B6,
        0, NOTE_AS6, NOTE_A6, 0,

        NOTE_G6, NOTE_E7, NOTE_G7,
        NOTE_A7, 0, NOTE_F7, NOTE_G7,
        0, NOTE_E7, 0, NOTE_C7,
        NOTE_D7, NOTE_B6, 0, 0,

        NOTE_C7, 0, 0, NOTE_G6,
        0, 0, NOTE_E6, 0,
        0, NOTE_A6, 0, NOTE_B6,
        0, NOTE_AS6, NOTE_A6, 0,

        NOTE_G6, NOTE_E7, NOTE_G7,
        NOTE_A7, 0, NOTE_F7, NOTE_G7,
        0, NOTE_E7, 0, NOTE_C7,
        NOTE_D7, NOTE_B6, 0, 0
        };


unsigned int SuperMarioDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


unsigned int ImperialMarchNotes[] = {  NOTE_A4, 0,  NOTE_A4, 0,  NOTE_A4, 0,
                                       NOTE_F4, 0, NOTE_C5, 0,  NOTE_A4, 0,
                                       NOTE_F4, 0, NOTE_C5, 0, NOTE_A4, 0,
                                       NOTE_E5, 0, NOTE_E5, 0,  NOTE_E5, 0,
                                       NOTE_F5, 0, NOTE_C5, 0,  NOTE_A4, 0,
                                       NOTE_F4, 0,  NOTE_C5, 0, NOTE_A4, 0};

unsigned int ImperialMarchDurations[]  = {50, 20, 50, 20, 50, 20,
                                          40, 5, 20, 5,  60, 10,
                                          40, 5, 20, 5, 60, 80,
                                          50, 20, 50, 20, 50, 20,
                                          40, 5, 20, 5,  60, 10,
                                          40, 5,  20, 5, 60, 80};




#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

