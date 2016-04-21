#include "pitches.h"
 


#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#define _XTAL_FREQ 47000000



void myDelay_us(unsigned int us);

void myDelay_ms(unsigned int ms);

void buzz(long freq, unsigned int duration);

void initBuzz(void);

void happyBirthday(void);

void nothingElseMatters(unsigned int index);

void superMario(unsigned int index);

void starWars(unsigned int index);


unsigned int superMarioNotes[] = {
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


unsigned int superMarioDurations[] = {
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


unsigned int imperialMarchNotes[] = {  NOTE_A4, 0,  NOTE_A4, 0,  NOTE_A4, 0,
                                       NOTE_F4, 0, NOTE_C5, 0,  NOTE_A4, 0,
                                       NOTE_F4, 0, NOTE_C5, 0, NOTE_A4, 0,
                                       NOTE_E5, 0, NOTE_E5, 0,  NOTE_E5, 0,
                                       NOTE_F5, 0, NOTE_C5, 0,  NOTE_A4, 0,
                                       NOTE_F4, 0,  NOTE_C5, 0, NOTE_A4, 0};

unsigned int imperialMarchDurations[]  = {50, 20, 50, 20, 50, 20,
                                          40, 5, 20, 5,  60, 10,
                                          40, 5, 20, 5, 60, 80,
                                          50, 20, 50, 20, 50, 20,
                                          40, 5, 20, 5,  60, 10,
                                          40, 5,  20, 5, 60, 80};

unsigned int nothingElseMattersNotes[] = {165, 196, 245, 330, 245, 196};
unsigned int nothingElseMattersDurations[] = {2, 2, 2, 2, 2, 2};

unsigned int nothingElseMattersFullNotes[] = {165, 196, 245, 330, 245, 196,
                            165, 196, 245, 330, 245, 196,
                            165, 196, 245, 330, 245, 196,
                            165, 196, 245, 330, 245, 494,
                            330, 494, 330, 165, 494, 262, 494, 440,
                            494, 440, 330
    
};
unsigned int nothingElseMattersFullDurations[] = {4, 4, 4, 4, 4, 4,
                               4, 4, 4, 4, 4, 4,
                               4, 4, 4, 4, 4, 4,
                               4, 4, 4, 4, 4, 4,
                               16, 2, 8, 8, 2, 4, 4, 4,
                               4, 4, 4
};


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

