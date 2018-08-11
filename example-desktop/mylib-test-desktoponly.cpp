
// http://www.use-strict.de/sput-unit-testing/tutorial.html
#include "sput.h"

#include "_Arduino.h"
#include "Arduino.h"
#include "mylib.h"

/** Test test_led_on_even call */
bool test_led_on_even_desktoponly() {
    // we do not use Arduino API calls here to get info about
    // moked chip state, use calls from _Arduino.h instead
    
    sput_fail_unless(led_on_even(13, 2), "num=2 => led#13 on");
    sput_fail_unless(_get_pin_value(13) == HIGH, "num=2 => led#13 on");
    
    sput_fail_unless(!led_on_even(13, 5), "num=5 => led#13 off");
    sput_fail_unless(_get_pin_value(13) == LOW, "num=5 => led#13 off");
    
    sput_fail_unless(led_on_even(13, 18), "num=18 => led#13 on");
    sput_fail_unless(_get_pin_value(13) == HIGH, "num=18 => led#13 on");
}

/*******************************************/
// test suites

/** Test suite for led_on_even call */
int mylib_test_suite_led_on_even_desktoponly() {
    sput_start_testing();
    
    sput_enter_suite("led on even (only desktop)");
    sput_run_test(test_led_on_even_desktoponly);
    
    sput_finish_testing();
    return sput_get_return_value();
}

/** All tests in one bundle */
int mylib_test_suite_desktoponly() {
    sput_start_testing();
    
    sput_enter_suite("led on even (only desktop)");
    sput_run_test(test_led_on_even_desktoponly);
    
    sput_finish_testing();
    return sput_get_return_value();
}

