#!/bin/bash
${CROSS_COMPILE}g++ -o sm2_test sm2.c sm2.hpp -L . -lsm2
