/*********************************************************************
 * Processor:       PIC18F2550
 * Compiler:        XC8 1.35+
 ********************************************************************/

/** I N C L U D E S *************************************************/
#include <pic18f2550.h>
#include "config.h"
#include "songs.h"
#include <stdlib.h>
#include <stdio.h>

/** D E F I N E S ***************************************************/
#define PUSHED 0
#define TRUE 1
#define FALSE 0

/** P R I V A T E   V A R I A B L E S *******************************/
static unsigned int note_new = 0, note_win = 0;
static unsigned char was_released;
static unsigned int hard_speed_timer;
static float hard_speed;
static int stepper_direction;
static unsigned char prev_hall;
static unsigned char LEDs[16];
static unsigned char target;
static int position;
static float steps_per_led;
static const unsigned int total_steps = 800;
static const unsigned int last_new_note = sizeof(nothingElseMattersNotes)/sizeof(nothingElseMattersNotes[0]);
static const unsigned int last_win_note = sizeof(superMarioNotes)/sizeof(superMarioNotes[0]);
static enum {CALIBRATION,
            NEW_GAME, 
            MOVE_EASY, 
            MOVE_HARD, 
            RELEASE, 
            FIRE,
            CHANGE_SPEED,
            LIGHT_UP,
            GAME_WON,
            GAME_LOST } current_state, state_to_recover;

/** P R I V A T E   P R O T O T Y P E S *****************************/
static void init(void);
static void fsm(void);
static void multiplex(void);
static void stepper_pulse(float);
static void setAllLeds(unsigned char);


/********************************************************************/
/** P U B L I C   D E C L A R A T I O N S ***************************/
/********************************************************************
 * Function:        void main(void)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Overview:        Main program entry point
 ********************************************************************/
void main(void) {
	init();	//initialize the system
    while(1) {  
        fsm();
        multiplex();
        }
}

/********************************************************************/
/** P R I V A T E   D E C L A R A T I O N S *************************/
/********************************************************************/

static void init(void) {
	TRISCbits.TRISC6 = 0; //PULSE
    TRISCbits.TRISC7 = 0; //DIRECTION
    TRISBbits.TRISB0 = 1; //DIFFICULTY TOGGLE
    TRISBbits.TRISB1 = 0; //ROW1
    TRISBbits.TRISB2 = 0; //ROW2
    TRISBbits.TRISB3 = 0; //ROW3
    TRISBbits.TRISB4 = 0; //ROW4
    TRISBbits.TRISB5 = 0; //COL1
    TRISBbits.TRISB6 = 0; //COL2
    TRISBbits.TRISB7 = 0; //COL3
    TRISAbits.TRISA0 = 0; //COL4
    TRISAbits.TRISA1 = 0; //GREEN LED
    TRISAbits.TRISA3 = 0; //BUZZER
    TRISAbits.TRISA4 = 1; //FIRE BUTTON
    TRISAbits.TRISA5 = 1; //HALL

	LATCbits.LATC6 = 0;
    LATCbits.LATC7 = 0;
    LATBbits.LATB1 = 0;
    LATBbits.LATB2 = 0;
    LATBbits.LATB3 = 0;
    LATBbits.LATB4 = 0;
    LATBbits.LATB5 = 0;
    LATBbits.LATB6 = 0;
    LATBbits.LATB7 = 0;
    LATAbits.LATA0 = 0;
    LATAbits.LATA1 = 1;
    LATAbits.LATA3 = 0;
    
	current_state = CALIBRATION;
    state_to_recover = CALIBRATION;
	
    note_new = 0;
    note_win = 0;
    hard_speed = 1.0;
    hard_speed_timer = 500;
    stepper_direction = 1;  // CW
    steps_per_led = total_steps/16;
    hardware_init();   
    prev_hall = PORTAbits.RA5;
}

static void fsm(void) {
    
    switch (current_state) {  
        case CALIBRATION :
            //output
            stepper_pulse(1);
            
            //transition
            if (PORTAbits.RA5 != prev_hall) {
                //prev_hall = PORTAbits.RA5;
                position = 0; //might require offset 
                current_state = NEW_GAME;                
            }
            
            break;
            
        case NEW_GAME :
        // *** outputs ***
            setAllLeds(0);
            
            note_new%=last_new_note;
            was_released = 0;
            note_win = 0;
            LATAbits.LATA1 = 1;
            nothingElseMatters(note_new);
            note_new++;
          
        // *** transitions ***
            if (PORTAbits.RA4 == PUSHED && PORTBbits.RB0 == 0) {
                current_state = MOVE_HARD;
                setAllLeds(0);
            }
            else
                if (PORTAbits.RA4 == PUSHED && PORTBbits.RB0 == 1) {
                    current_state = MOVE_EASY;
                    setAllLeds(0);
                }

            break;
        
        case MOVE_EASY :
            
            stepper_pulse(1);
            
            if (PORTAbits.RA4 == 0) {
                if (was_released == TRUE) 
                    current_state = FIRE;
            }
            else {
                if (was_released == FALSE) 
                    current_state = RELEASE;
            }
            
            break;
        
        case MOVE_HARD :
            
            stepper_pulse(hard_speed);
            hard_speed_timer--;
            
            if (was_released == TRUE) {
                if (PORTAbits.RA4 == 0) {
                    current_state = FIRE;
                }
                else if (hard_speed_timer <= 5) {
                    current_state = CHANGE_SPEED;
                }
            }
            else if (PORTAbits.RA4 == 0) {
                if (hard_speed_timer <= 5) {
                    current_state = CHANGE_SPEED;
                }
            }
            else {
                current_state = RELEASE;
            }                 
            
            break;
       
      
        case RELEASE :
            
            was_released = TRUE;
            
            if (PORTBbits.RB0 == 1) 
                current_state = MOVE_EASY;
            else
                current_state = MOVE_HARD;
            break;
            
        case LIGHT_UP:
        // *** outputs ***
            LEDs[target] = 1;
            char i = 0;
            for (i = 0; i <= 15; i++) {
                if (LEDs[i] == 0) {
                    if (PORTBbits.RB0 == 1) 
                        current_state = MOVE_EASY;
                    else 
                        current_state = MOVE_HARD;
                    break;
                }
            }
            if (i == 16)
                current_state = GAME_WON;
            break;

        case CHANGE_SPEED :
            
            if (rand()*2 >= 1) 
                stepper_direction = 1;
            else 
                stepper_direction = -1;
            
            
            hard_speed_timer = rand()%2000+100;
            hard_speed = rand()%2;
            
            current_state = MOVE_HARD;
            break;
            
        case FIRE :
            was_released = FALSE;
            buzz(300,100);
            
            for (char i = 0;i<=16;i++) {
                if ((float)position >= ((i-1)*steps_per_led+steps_per_led/2) && (float)position <= (i*steps_per_led+steps_per_led/2+1)) {
                    target = i%16;
                    break;
                }
            }
            if (LEDs[target] == 0) {
                current_state = LIGHT_UP;
            }
            else current_state = GAME_LOST;
            
            break;
            //target = ... Do all 25 steps around the led hit it, or are there no hit zones?

        case GAME_LOST :
            setAllLeds(0);
            buzz(300,100);
            note_new = 0;
            
            current_state = NEW_GAME;
            break;
            
        case GAME_WON :
            note_new = 0;
            superMario(note_win);
            note_win++;
            LATAbits.LATA1 = 0;
            
            if(note_win == last_win_note) {
                current_state = NEW_GAME;
            }
            break;
            
        default:
            current_state = CALIBRATION;
            break;
       
    };
    
}

static void stepper_pulse(float speed) {
    if (stepper_direction > 0)
        LATCbits.LATC7 = 0;
    else
        LATCbits.LATC7 = 1;
    
    LATCbits.LATC6 = 1;
    myDelay_us((int)(250/speed));
    LATCbits.LATC6 = 0;
    myDelay_us((int)(250/speed));

    position+= stepper_direction;
    while (position < 0)
        position+=total_steps;
        //position = total_steps-1;
    
    position%=total_steps;
}

static void go_through_cols(char offset) {
    if (LEDs[offset]==1)   LATBbits.LATB5 =1;
    if (LEDs[offset+1]==1) LATBbits.LATB6 =1;
    if (LEDs[offset+2]==1) LATBbits.LATB7 =1;
    if (LEDs[offset+3]==1) LATAbits.LATA0 =1;

    myDelay_us(100);
    
    LATBbits.LATB5 = 0;
    LATBbits.LATB6 = 0;
    LATBbits.LATB7 = 0;
    LATAbits.LATA0 = 0;
}

static void multiplex() {
    LATBbits.LATB1 = 0;
    go_through_cols(0);
    LATBbits.LATB1 = 1;
    
    LATBbits.LATB2 = 0;
    go_through_cols(4);
    LATBbits.LATB2 = 1;
    
    LATBbits.LATB3 = 0;
    go_through_cols(8);
    LATBbits.LATB3 = 1;
    
    LATBbits.LATB4 = 0;
    go_through_cols(12);
    LATBbits.LATB4 = 1;
}

static void setAllLeds(unsigned char value) {
    for(char i = 0; i <= 15; i++) 
        LEDs[i] = value;
}

//EOF-------------------------------------------------------------------------

