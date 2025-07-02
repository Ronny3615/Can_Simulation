#include <stdio.h>
#include "scheduler.h"
#include "ecu.h"
#include "delay.h"   // ✅ ADD THIS LINE

// Simulate round-robin scheduling across ECUs
void run_scheduler(ECU ecus[], int total_ecus) {
    for (int i = 0; i < total_ecus; i++) {
        printf("[Scheduler] ECU %d scheduled to run...\n", ecus[i].id);
        ecu_send_message(&ecus[i]);
        sleep_ms(500);  // Simulated delay of 500 ms
    }
}
