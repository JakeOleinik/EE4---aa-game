/*
 * File:   songs.c
 * Author: Jake
 *
 * Created on March 9, 2016, 11:19 PM
 */


#include <xc.h>
#include "songs.h"
#include "pitches.h"

void myDelay_us(unsigned int us) {
    // delay in us
    for (unsigned int i=0; i<us; i++)
        __delay_us(1);
}

void myDelay_ms(unsigned int ms) {
    // delay in ms
    for (unsigned int i=0; i<ms; i++)
        __delay_ms(1);
}


void buzz(long freq, unsigned int duration) {
    // duration in ms
    if (freq==0) {
        myDelay_ms(duration);
        return;
    }
    unsigned int halfPeriod = 1e6 / 2 / freq;   // in us
    long repeats = (long)duration *1000 / (2 * halfPeriod);
    for (long i=0; i<repeats; i++) {
        LATAbits.LATA3 = 1;
        myDelay_us(halfPeriod);
        
        LATAbits.LATA3 = 0;
        myDelay_us(halfPeriod);
    }
}

void initBuzz(void) {
    TRISAbits.TRISA3 = 0;
    hardware_init();
}



/*
void happyBirthday(void) {
    // Happy birthday notes
    //                        Hap py  Birth Day  to  you,  Hap py  birth day  to
                             C4   C4   D4   C4   F4   E4   C4   C4   D4   C4   G4 //
    unsigned int notes[] = {262, 262, 294, 262, 349, 330, 262, 262, 294, 262, 392,

    //                       you, Hap py  Birth Day  dear  xxxx      Hap  py   birth
                             F4   C4   C4   C5   A4   F4   E4   D4   B4b  B4b  A4 //
                            349, 262, 262, 523, 440, 349, 330, 294, 466, 466, 440,

    //                       day  to  you
                             F4   G4   F4   //
                            349, 392, 349
                            };

    unsigned short interval[] = {4, 4, 8, 8, 8, 10, 4, 4, 8, 8, 8, 10, 4, 4, 8, 8, 8,
                                 8, 8, 4, 4, 8, 8, 8, 12};
    
    for (unsigned int k=0; k<25; k++) {
        buzz(notes[k], 70*interval[k]);
        buzz(0, 6);
    }
    buzz(0, 500);
}
*/

void nothingElseMatters(unsigned int index) {
    buzz(nothingElseMattersNotes[index], 70*nothingElseMattersDurations[index]);
    buzz(0, 20);
    
    /*
    for (unsigned int k=0; k<sizeof(notes)/sizeof(notes[0]); k++) {
        buzz(notes[k], 70*interval[k]);
        buzz(0, 20);
    }
    */
}


void superMario(unsigned int index) {
    buzz(superMarioNotes[index], 1000/superMarioDurations[index]);
    buzz(0, 20);
        
    /*
    for (unsigned int k=0; k<sizeof(notes)/sizeof(notes[0]); k++) {
        buzz(notes[k], 1000/interval[k]);
        buzz(0, 20);
    }
    */ 
    
}

void starWars(unsigned int index) {
    buzz(imperialMarchNotes[index], 4*imperialMarchDurations[index]);
    
    /*
    for (unsigned int k=0; k<sizeof(notes)/sizeof(notes[0]); k++) {
        buzz(notes[k], 4*interval[k]);
        //buzz(0, 20);
    }*/
    

}
