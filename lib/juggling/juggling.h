/**
 * Shared code between juggling server and clients 
 */
extern uint8_t j_payload_size;
extern uint64_t j_radio_address;
extern uint8_t j_radio_channel;
extern rf24_datarate_e j_datareate;
extern rf24_pa_dbm_e j_amplification;

/**
 * Set up an RF24 object
 */
void radio_setup(RF24 &radio);
