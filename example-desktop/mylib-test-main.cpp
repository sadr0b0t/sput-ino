#include "mylib-test.h"
#include "mylib-test-desktoponly.h"

int main() {
    return mylib_test_suite() | mylib_test_suite_desktoponly();
}

