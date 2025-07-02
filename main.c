#include <stdio.h>
#include "ecu.h"
#include "can.h"
#include "scheduler.h"
#include "logger.h"
#include "error.h"

#define TOTAL_ECUs 3
#define SIMULATION_CYCLES 5

int main() {
    init_logger();  // Initialize file logger

    my_printf("\n==============================\n");
    my_printf("CAN Multi-ECU Simulation Started\n");
    my_printf("==============================\n");

    ECU ecus[TOTAL_ECUs];

    for (int i = 0; i < TOTAL_ECUs; i++) {
        ecus[i] = ecu_init(i + 1);
    }

    for (int cycle = 0; cycle < SIMULATION_CYCLES; cycle++) {
        my_printf("\n--- Simulation Cycle %d ---\n", cycle + 1);
        inject_random_error(ecus, TOTAL_ECUs);
        run_scheduler(ecus, TOTAL_ECUs);
    }

    my_printf("\nSimulation Completed.\n");
    close_logger();  // Close file logger
    return 0;
}
