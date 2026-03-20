#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial_com.h"

void timer1_init(void)
{
    // Set Timer1 to normal mode (default, but make explicit)
    TCCR1A = 0x00;
    TCCR1B = 0x00;

    // Set prescaler (e.g., 1024 for slow overflow)
    TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler = 1024

    // Enable Timer1 overflow interrupt
    TIMSK1 |= (1 << TOIE1);

    // Initialize counter (optional)
    TCNT1 = 0;
}

int main(void)
{
    uart_init();
    uint8_t input_buffer[100];

    // Configure PORTB7 (pin 13) as output
    DDRB |= (1 << DDB7);

    // Initialize timer
    timer1_init();

    // Enable global interrupts
    sei();

    while (1)
    {
        // Print message to serial
        printf("Hallo from Arduino!\n\r");
        // Read input from serial/stdin and ignore it
        scanf("%s", input_buffer);
        printf("You wrote: %s\n\r", input_buffer);
    }
}

// Timer1 overflow interrupt service routine
ISR(TIMER1_OVF_vect)
{
    // Toggle PORTB7
    PORTB ^= (1 << PORTB7);
}
