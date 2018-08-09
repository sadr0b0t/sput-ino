// Self-contained project example with tests
// see https://github.com/sadr0b0t/sput-ino-demo
// for extended project layout

/*******************************************/
// some code to test

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
    return num % 2 == 0;
}

/*******************************************/
// tests
// http://www.use-strict.de/sput-unit-testing/tutorial.html
#include "sput.h"

/** Test a_plus_b call */
void test_a_plus_b() {
    sput_fail_unless(a_plus_b(2, 2) == 4, "2 + 2 == 4");
    sput_fail_unless(a_plus_b(-2, 2) == 0, "-2 + 2 == 0");
    
    // this one would pass on 32-bit controllers and would fail on 16-bit Arduino
    sput_fail_unless(a_plus_b(34000, 34000) == 68000, "34000 + 34000 == 68000");
}

/** Test a_minus_b call */
void test_a_minus_b() {
    sput_fail_unless(a_minus_b(115, 6) == 109, "115 - 6 == 109");
    sput_fail_unless(a_minus_b(13, 17) == -4, "13 - 17 == -4");
}

/** Test test_led_on_even call */
bool test_led_on_even() {
    sput_fail_unless(led_on_even(13, 2), "num=2 => led#13 on");
    // would pass on desktop, might fail or pass on difference devices
    // (e.g.: Arduino Due - fail, ChipKIT Uno32 - pass)
    sput_fail_unless(digitalRead(13) == HIGH, "num=2 => led#13 on");
    
    sput_fail_unless(!led_on_even(13, 5), "num=5 => led#13 off");
    sput_fail_unless(digitalRead(13) == LOW, "num=5 => led#13 off");
    
    sput_fail_unless(led_on_even(13, 18), "num=18 => led#13 on");
    sput_fail_unless(digitalRead(13) == HIGH, "num=18 => led#13 on");
}

/*******************************************/
// test suites

/** Test suite for a_plus_b call */
int mylib_test_suite_a_plus_b() {
    sput_start_testing();

    sput_enter_suite("a plus b");
    sput_run_test(test_a_plus_b);
    
    sput_finish_testing();
    return sput_get_return_value();
}

/** Test suite for a_minus_b call */
int mylib_test_suite_a_minus_b() {
    sput_start_testing();
    
    sput_enter_suite("a minus b");
    sput_run_test(test_a_minus_b);
    
    sput_finish_testing();
    return sput_get_return_value();
}

/** Test suite for led_on_even call */
int mylib_test_suite_led_on_even() {
    sput_start_testing();
    
    sput_enter_suite("led on even");
    sput_run_test(test_led_on_even);
    
    sput_finish_testing();
    return sput_get_return_value();
}

/** All tests in one bundle */
int mylib_test_suite() {
    sput_start_testing();

    sput_enter_suite("a plus b");
    sput_run_test(test_a_plus_b);
    
    sput_enter_suite("a minus b");
    sput_run_test(test_a_minus_b);
    
    sput_enter_suite("led on even");
    sput_run_test(test_led_on_even);
    
    sput_finish_testing();
    return sput_get_return_value();
}

/** run tests on device */
void run_tests() {
    Serial.println("#################### Start testing...");

    // comment out specific test suites if firmware does not
    // fit to device memory
    
    // Test suite for a_plus_b call
    mylib_test_suite_a_plus_b();

    // Test suite for a_minus_b call
    mylib_test_suite_a_minus_b();
    
    // Test suite for led_on_even call
    mylib_test_suite_led_on_even();

    // All tests in one bundle
    //mylib_test_suite();
    
    Serial.println("#################### Finished testing");
}

/*******************************************/

void setup() {
    Serial.begin(9600);
    while (!Serial);

    // run tests
    run_tests();

    // other code - kinda application business logic
    Serial.println("Just show that we call functions from tested lib, nothing useful here");
    
    pinMode(13, OUTPUT);
    
    Serial.print("14+23=");
    Serial.println(a_plus_b(14, 23));
    Serial.print("14-23=");
    Serial.println(a_minus_b(14, 23));
    Serial.print("34000+34000=");
    Serial.println(a_plus_b(34000, 34000));
}

void loop() {
    static int i = 0;
    led_on_even(13, i++);
    delay(2000);
}

