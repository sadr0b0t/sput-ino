
#include "Arduino.h"

/**
 * @return a plus b
 */
int a_plus_b(int a, int b) {
    return a + b;
}

/**
 * @return a minus b
 */
int a_minus_b(int a, int b) {
    return a - b;
}

/** 
 * Switch led on if number is even
 * @param pin led pin id
 * @param num number
 * @return true, if num is even
 */
bool led_on_even(int pin, int num) {
    if(num % 2 == 0) {
        digitalWrite(pin, HIGH);
    } else {
        digitalWrite(pin, LOW);
    }
    return (num % 2 == 0);
}

