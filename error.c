#include <stdlib.h>
#include <time.h>
#include "error.h"
#include "logger.h"

void inject_random_error(ECU ecus[], int total_ecus) {
    srand(time(NULL));  // Seed for randomness

    for (int i = 0; i < total_ecus; i++) {
        int chance = rand() % 10;  // 0 to 9
        if (chance < 2) {  // 20% chance of error
            ecus[i].has_error = 1;
            log_error(ecus[i].id, "Injected bit error (simulated).");
        } else {
            ecus[i].has_error = 0;
        }
    }
}
