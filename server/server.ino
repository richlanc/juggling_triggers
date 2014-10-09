/**
 * Server software for midi triggering juggling balls
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"


//nRF24L01 api
RF24 radio(9, 10);

void setup(void) {
    // Setup the radio
    radio.begin();
    radio.setChannel(100);
    radio.setDataRate(RF24_2MBPS);
}

void loop(void) {

}
