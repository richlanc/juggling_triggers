/**
 * Server software for midi triggering juggling balls
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "juggling.h"
#include "printf.h"

uint8_t reading_pipe = 1;
RF24 radio(9, 10);

/**
 * Setup, called by the arduino on power on
 */
void setup(void) {
    /* setup radio pipes */
    radio_setup(radio);
}

void server_radio_setup(RF24 &radio){
    radio.openReadingPipe(reading_pipe, j_radio_address);
}

/**
 * Loop, called repeatedly after setup
 */
void loop(void) {

}
