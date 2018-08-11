#!/bin/sh
# simple build script, feel free to modify or convert it
# to your favourite build system config

#gcc -c c_file_stub.c
#g++ -std=c++11 -c cpp_file_stub.cpp

g++ -std=c++11 -c \
    -I. -I../examples/sput-ino-modules -I$HOME/Arduino/libraries/sput-ino/src \
    Arduino.cpp \
    ../examples/sput-ino-modules/mylib.cpp \
    ../examples/sput-ino-modules/mylib-test.cpp \
    mylib-test-desktoponly.cpp \
    mylib-test-main.cpp
g++ *.o -o test_mylib

