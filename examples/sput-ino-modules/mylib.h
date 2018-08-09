#ifndef MYLIB_H
#define MYLIB_H

/**
 * @return a plus b
 */
int a_plus_b(int a, int b);

/**
 * @return a minus b
 */
int a_minus_b(int a, int b);

/** 
 * Switch led on if number is even
 * @param pin led pin id
 * @param num number
 * @return true, if num is even
 */
bool led_on_even(int pin, int num);

#endif // MYLIB_TEST_H

