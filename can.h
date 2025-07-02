#pragma once

#define MAX_DATA_LENGTH 8

typedef struct {
    int id;
    int dlc;
    unsigned char data[MAX_DATA_LENGTH];
    unsigned int crc;
} CAN_Frame;

// Simulate CRC calculation
unsigned int calculate_crc(CAN_Frame frame);

// Simulate CAN arbitration and transmission
void can_transmit(CAN_Frame frame);
