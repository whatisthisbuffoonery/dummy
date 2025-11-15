#include <time.h>


struct timespec timeout;

timespec_get(&timeout, TIME_UTC);	// Get current time
timeout.tv_sec += 1;				// Timeout 1 second after now
timeout.tv_nsec += 500000000;		// += 0.5 secs (unit is billionth of a second)

int result = mtx_timedlock(&serial_mtx, &timeout);//checks if lock can be obtained before timeout

if (result == thrd_timedout) {
    printf("Mutex lock timed out!\n");
}
