
#include "mylib.h"
#include "mylib-test.h"


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

void setup() {
    Serial.begin(9600);
    while (!Serial);

    // run tests
    run_tests();

    // other code - kinda application business logic
    Serial.println("Just show that we call functions from tested lib, nothing useful here");
    Serial.print("14+23=");
    Serial.println(a_plus_b(14, 23));
    Serial.print("14-23=");
    Serial.println(a_minus_b(14, 23));
}

void loop() {
    delay(2000);
}

