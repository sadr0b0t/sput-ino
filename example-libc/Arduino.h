#ifndef WPROGRAM_H
#define WPROGRAM_H

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

unsigned long micros();

void pinMode(int pin, int mode);

void digitalWrite(int pin, int val);

int digitalRead(int pin);

#endif // WPROGRAM_H

