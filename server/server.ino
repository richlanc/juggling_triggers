/**
 * Server software for midi triggering juggling balls
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "juggling.h"
#include "printf.h"

unsigned char payload;
uint8_t reading_pipe = 1;
RF24 radio(9, 10);

/**
 * Setup radio for listening
 */
void _server_radio_setup(RF24 &radio){
    radio.openReadingPipe(reading_pipe, j_radio_address);
    radio.startListening();
}

/**
 * Setup, called by the arduino on power on
 */
void setup(void) {
    Serial.begin(115200);
    printf_begin();
    radio_setup(radio);
    _server_radio_setup(radio);
    radio.printDetails();
}

/**
 * Loop, called repeatedly after setup
 */
void loop(void) {
    if(radio.available()) {
        bool done = false;
        while(!radio.read(&payload, sizeof(unsigned char))) {};

        /*
         * After a seemingly random amount of payloards, RF24 library starts
         * spewing zeros every other payload
         */
        if (payload == 0) {return;}

        /* Unformat payload */
        payload = payload - 1;
        printf("Payload: %hhu\n\r", payload);
    }
}
