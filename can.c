#include <stdio.h>
#include "can.h"
#include "logger.h"

unsigned int calculate_crc(CAN_Frame frame) {
    unsigned int crc = 0;
    crc ^= frame.id;
    crc ^= frame.dlc;
    for (int i = 0; i < frame.dlc; i++) {
        crc ^= frame.data[i];
    }
    return crc;
}

void can_transmit(CAN_Frame frame) {
    frame.crc = calculate_crc(frame);  // Sender side CRC

    log_arbitration_result(frame.id, 1);  // Arbitration assumed won

    // Simulated receiver-side CRC validation
    unsigned int expected_crc = calculate_crc(frame);  // re-calculate
    if (expected_crc != frame.crc) {
        log_error(frame.id, "CRC Mismatch: Frame dropped by receiver");
        return;
    }

    log_rx(frame.id, frame);  // Frame accepted
}
