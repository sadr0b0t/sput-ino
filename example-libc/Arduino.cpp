
// saved values for pins
static int _pin_values[64];

/**
 * micros stub
 */
unsigned long micros() {
    return 0;
}

/**
 * pinMode stub, does nothing
 */
void pinMode(int pin, int mode) {
}

/**
 * Save pin value
 */
void digitalWrite(int pin, int val) {
    _pin_values[pin] = val;
}

/**
 * Get pin value
 */
int digitalRead(int pin) {
    return _pin_values[pin];
}

