// platform.c
#include "platform.h"

#ifdef _WIN32
#include <windows.h>
void sleep_ms(int milliseconds) {
    Sleep(milliseconds);
}
#else
#include <unistd.h>
void sleep_ms(int milliseconds) {
    usleep(milliseconds * 1000);  // Convert to microseconds
}
#endif
