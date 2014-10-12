#include "RF24.h"
#include "juggling.h"

/* RF24 configuration */
uint8_t j_radio_address = 0xF0F0F0F0F0LL;
uint8_t j_radio_channel = 0; 
rf24_datarate_e j_datareate = RF24_2MBPS;
rf24_pa_dbm_e j_amplification = RF24_PA_MAX;

void radio_setup(RF24 &radio) {
        /* setup the radio */
    radio.begin();
    radio.setChannel(j_radio_channel);  // 0 - 127
    radio.setDataRate(j_datareate);  // bits, the capital b is a lie
    radio.setPALevel(j_amplification);
    /*
     * Payload:
     * Bits
     * 	0 - command bit, HIGH or LOW
     *  1-7 - device ID
     *  8-15 - device pin (pin that went high or low) 
     */
    radio.setPayloadSize(2);

}