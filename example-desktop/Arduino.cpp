
// saved values for pins
static int _pin_modes[64];
static int _pin_values[64];

// from Arduino.h

/**
 * micros stub
 */
unsigned long micros() {
    return 0;
}

/**
 * Set GPIO pin mode
 */
void pinMode(int pin, int mode) {
    _pin_modes[pin] = mode;
}

/**
 * Write GPIO pin value
 */
void digitalWrite(int pin, int val) {
    _pin_values[pin] = val;
}

/**
 * Read GPIO pin value
 */
int digitalRead(int pin) {
    return _pin_values[pin];
}

// From _Arduino.h
// Calls to get extended info from Arduino mocks

/** Get pin mode */
int _get_pin_mode(int pin) {
    return _pin_modes[pin];
}

/** Get pin value */
int _get_pin_value(int pin) {
    return _pin_values[pin];
}

