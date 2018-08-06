
#ifdef ARDUINO_ARCH_SAM
// implement missing _gettimeofday on SAM/Arduino Due platform (required for tests with sput.h)
// https://stackoverflow.com/questions/7004743/unable-to-link-to-gettimeofday-on-embedded-system-elapsed-time-suggestions

#include <stdint.h>
#include <sys/time.h>

int _gettimeofday( struct timeval *tv, void *tzvp )
{
    uint64_t t = micros();  // get uptime in microseconds
    tv->tv_sec = t / 1000000;  // convert to seconds
    tv->tv_usec = ( t % 1000000 ) / 1000;  // get remaining microseconds
    return 0;  // return non-zero for error
} // end _gettimeofday()

#endif // ARDUINO_ARCH_SAM

