#include <xc.h>

#pragma config DEBUG = 1
#pragma config FOSC = 1000
#pragma config PBADEN = 0
#pragma config WDT = OFF

#define _XTAL_FREQ 8000000

void main(void) {
    ADCON1 = 0x0F; // Set all analog channels as digital pins
    INTCON2 = 0x75; // Enable PORTB pull ups
    OSCCON = 0x79;
    
    PORTA = 0x00;
    TRISA = 0x00;
    PORTE = 0x00;
    TRISE = 0x00;
    TRISB = 0xFF;
    
    while (1) {
        PORTA = !PORTB;
        PORTEbits.RE1 = !PORTBbits.RB7;
    }
}
