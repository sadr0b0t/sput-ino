
// http://www.use-strict.de/sput-unit-testing/tutorial.html
#include "sput.h"

#include "Arduino.h"
#include "mylib.h"

/** Test a_plus_b call */
void test_a_plus_b() {
    sput_fail_unless(a_plus_b(2, 2) == 4, "2 + 2 == 4");
    sput_fail_unless(a_plus_b(-2, 2) == 0, "-2 + 2 == 0");
    
    // this one would pass on 32-bit controllers and desktop (libc) and would fail on 16-bit Arduino
    sput_fail_unless(a_plus_b(34000, 34000) == 68000, "34000 + 34000 == 68000");
}

/** Test a_minus_b call */
void test_a_minus_b() {
    sput_fail_unless(a_minus_b(115, 6) == 109, "115 - 6 == 109");
    sput_fail_unless(a_minus_b(13, 17) == -4, "13 - 17 == -4");
}

/** Test test_led_on_even call */
bool test_led_on_even() {
  
    // 1) this test shows that we can also test code, that uses Arduino API
    // 2) please, consider this test also as kind of antipattern:
    // - we make here device-specific calls which may pass or fail
    //     on different devices
    // - what we should test here is NOT that digitalWrite did MAKE changes
    //     to GPIO register (so we check this with device-specific
    //     pinMode+digitalRead), but that we did CALL digitallWrite
    //     with specific params in tested code (this can hardly be
    //     checked when we run test on device, but can easily be checked
    //     when we run test on desktop with Arduino API mockups).
    //     See desktop+mockup version of this test:
    //       example-desktop/mylib-test-desktoponly.cpp
    // - when we run this specific test on desktop, digitalRead
    //     would be implemented as mockup anyway, so, probably, whatever
    
    pinMode(13, OUTPUT);
    
    sput_fail_unless(led_on_even(13, 2), "num=2 => led#13 on");
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

