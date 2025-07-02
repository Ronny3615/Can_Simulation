#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "logger.h"

static FILE* log_file = NULL;

// Timestamp function
static const char* get_timestamp() {
    time_t now = time(NULL);
    return ctime(&now);  // Includes newline
}

// Initialize logger
void init_logger() {
    log_file = fopen("logger.txt", "a");
}

// Close logger
void close_logger() {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

// Dual print to terminal + file
void my_printf(const char *format, ...) {
    va_list args;

    va_start(args, format);
    vprintf(format, args);  // Terminal
    va_end(args);

    if (log_file) {
        va_start(args, format);
        vfprintf(log_file, format, args);  // File
        va_end(args);
    }
}

void log_tx(int ecu_id, CAN_Frame frame) {
    my_printf("[TX][%s] ECU %d Sent Frame - ID: %d, Data: 0x%X, CRC: 0x%X\n",
              get_timestamp(), ecu_id, frame.id, frame.data[0], frame.crc);
}

void log_rx(int ecu_id, CAN_Frame frame) {
    my_printf("[RX][%s] Frame Received by ECU %d - ID: %d, Data: 0x%X, CRC: 0x%X\n",
              get_timestamp(), ecu_id, frame.id, frame.data[0], frame.crc);
}

void log_arbitration_result(int ecu_id, int success) {
    if (success)
        my_printf("[ARBITRATION][%s] ECU %d won arbitration.\n", get_timestamp(), ecu_id);
    else
        my_printf("[ARBITRATION][%s] ECU %d lost arbitration.\n", get_timestamp(), ecu_id);
}

void log_error(int ecu_id, const char *message) {
    my_printf("[ERROR][%s] ECU %d: %s\n", get_timestamp(), ecu_id, message);
}
