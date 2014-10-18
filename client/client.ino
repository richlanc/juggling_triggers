/**
 * Client software for midi triggering juggling balls
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "juggling.h"
 #include "printf.h"

RF24 radio(9, 10);
unsigned char previous_pins;

void _setup_write_setup(RF24& radio){
    radio.openWritingPipe(j_radio_address);
    radio.startListening();
    radio.stopListening();
}

/**
 * Setup, called by the arduino on power on
 */
void setup(void) {
    Serial.begin(115200);
    printf_begin();
    radio_setup(radio);
    _setup_write_setup(radio);
    radio.printDetails();

    /* set pins 2-7 as read, without changing 0-1*/
    DDRD = B00000000 | (DDRD & B00000011);
    previous_pins = PIND & B11111100;
}

/**
 * Loop, called repeatedly after setup
 */
void loop(void) {
    /* get values of pins 2-7 */
    unsigned char pins = PIND & B11111100;

    if (pins != previous_pins) {
        previous_pins = pins;
        /* format payload */
        unsigned char payload = (pins >> 2) + 1;

        printf("Payload: %hhu\n\r", payload);

        while(!radio.write(&payload, sizeof(unsigned char))) {};
    }
}