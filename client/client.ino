/**
 * Client software for midi triggering juggling balls
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "juggling.h"

RF24 radio(9, 10);

void _setup_write_setup(RF24& radio){
    radio.openWritingPipe(j_radio_address);
    radio.startListening();
    radio.stopListening();
}

/**
 * Setup, called by the arduino on power on
 */
void setup(void) {
    radio_setup(radio);
    _setup_write_setup(radio);
    radio.printDetails();
}

/**
 * Loop, called repeatedly after setup
 */
void loop(void) {
    unsigned long time = millis();
    while(!radio.write(&time, sizeof(unsigned long))) {};
}