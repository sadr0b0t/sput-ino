
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

