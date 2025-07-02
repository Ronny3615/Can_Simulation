#pragma once

typedef struct {
    int id;
    int message_data;
    int has_error;
} ECU;

// Initializes ECU with given ID
ECU ecu_init(int id);

void ecu_send_message(ECU* ecu);
