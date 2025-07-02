#pragma once
#include "can.h"

void init_logger();
void close_logger();
void my_printf(const char *format, ...);

void log_tx(int ecu_id, CAN_Frame frame);
void log_rx(int ecu_id, CAN_Frame frame);
void log_arbitration_result(int ecu_id, int success);
void log_error(int ecu_id, const char *message);
