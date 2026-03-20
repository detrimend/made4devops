#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include "serial_com.h"

int rand_range(int min_number, int max_number);

int main()
{
    // Initialize the UART for serial communication 
    uart_init(); 
    // Buffer for reading input from serial/stdin 
    char input_buffer[100];

    do
    {
        // Print message to serial 
        printf("Hello Martin\n\r"); 
        // Read input from serial/stdin and ignore it 
        scanf("%99s", input_buffer);
        const char *suffix = "";
        switch (rand_range(1, 5))
        {
            case 1: 
                suffix = ", you are lovely";
                break;
            case 2:
                suffix = ", keep going";
                break;
            case 3:
                suffix = ", nice work";
                break;
            case 4:
                suffix = ", you got this";
                break;
            case 5:
                suffix = ", have a great day";
                break;
            default:
                break;
        }
        strncat(input_buffer, suffix, sizeof(input_buffer) - strlen(input_buffer) - 1);
        printf("%s\n\r", input_buffer);
    } while (1);
}

int rand_range(int min_number, int max_number) 
{
    return rand() % (max_number + 1 - min_number) + min_number;
}