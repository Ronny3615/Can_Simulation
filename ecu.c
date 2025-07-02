#include <stdio.h>
#include "ecu.h"
#include "can.h"
#include "logger.h"

ECU ecu_init(int id) {
    ECU e;
    e.id = id;
    e.message_data = 0xA0 + id;  // Just some sample data
    e.has_error = 0;
    return e;
}

void ecu_send_message(ECU *e) {
    CAN_Frame frame;
    frame.id = e->id;
    frame.dlc = 1;
    frame.data[0] = e->message_data;
    
    if (e->has_error) {
        log_error(e->id, "Error state: frame not sent.");
        return;
    }

    log_tx(e->id, frame);
    can_transmit(frame);
}
