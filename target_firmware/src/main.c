#include <stdio.h> 
#include <util/delay.h> 
#include <avr/io.h> 
#include "serial_com.h" 
int main() 
{ 
    // Initialize the UART for serial communication 
    uart_init(); 

    // Set prescaler to /1024 
    TCCR1B |= (1<<CS12) | (1<<CS10); 

    while(1) 
    { 
        printf("TCNT1 %u\n\r", TCNT1); 
        _delay_ms(500); 
    } 
    // tager cirka 4 sekunder at nå 65000
}