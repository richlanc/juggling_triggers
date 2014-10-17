#include "RF24.h"
#include "juggling.h"

/* RF24 configuration */
uint8_t j_payload_size = 2;
uint64_t j_radio_address = 0xF0F0F0F0F0LL;
uint8_t j_radio_channel = 0; 
rf24_datarate_e j_datareate = RF24_2MBPS;
rf24_pa_dbm_e j_amplification = RF24_PA_MAX;

void radio_setup(RF24 &radio) {
    /* setup the radio */
    radio.begin();
    radio.setChannel(0);//j_radio_channel);  // 0 - 127
    radio.setDataRate(j_datareate);  // bits, the capital b is a lie
    radio.setPALevel(j_amplification);
    // radio.setRetries(15,15);
    //radio.setAutoAck(false);
    radio.setPayloadSize(8);
}
