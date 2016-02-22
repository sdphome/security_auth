#!/bin/bash

CC=arm-linux-gcc
#CC=arm-linux-g++
AR=arm-linux-ar
LD=arm-linux-ld
RANLIB=arm-linux-ranlib

#LIB=libsm2_x86.a
#rm $LIB
cp mirdef_x86.lnx mirdef.h
$CC -fPIC -c -O2 mrcore.c
$CC -fPIC -c -O2 mrarth0.c
$CC -fPIC -c -O2 mrarth1.c
$CC -fPIC -c -O2 mrarth2.c
$CC -fPIC -c -O2 mralloc.c
$CC -fPIC -c -O2 mrsmall.c
$CC -fPIC -c -O2 mrbits.c
$CC -fPIC -c -O2 mrio1.c
$CC -fPIC -c -O2 mrio2.c
$CC -fPIC -c -O2 mrgcd.c
$CC -fPIC -c -O2 mrjack.c
$CC -fPIC -c -O2 mrxgcd.c
$CC -fPIC -c -O2 mrarth3.c
$CC -fPIC -c -O2 mrrand.c
$CC -fPIC -c -O2 mrprime.c
$CC -fPIC -c -O2 mrcrt.c
$CC -fPIC -c -O2 mrscrt.c
$CC -fPIC -c -O2 mrmonty.c
$CC -fPIC -c -O2 mrpower.c
$CC -fPIC -c -O2 mrcurve.c
$CC -fPIC -c -O2 mrfast.c
$CC -fPIC -c -O2 mrzzn2.c
$CC -fPIC -c -O2 mrzzn2b.c
$CC -fPIC -c -O2 mrzzn3.c
$CC -fPIC -c -O2 mrecn2.c
$CC -fPIC -c -O2 mrshs.c
$CC -fPIC -c -O2 mrshs256.c
$CC -fPIC -c -O2 mrshs512.c
$CC -fPIC -c -O2 mraes.c
$CC -fPIC -c -O2 mrgcm.c
$CC -fPIC -c -O2 mrlucas.c
$CC -fPIC -c -O2 mrstrong.c
$CC -fPIC -c -O2 mrbrick.c
$CC -fPIC -c -O2 mrebrick.c
$CC -fPIC -c -O2 mrgf2m.c
$CC -fPIC -c -O2 mrec2m.c
$CC -fPIC -c -O2 mrsroot.c
$CC -fPIC -c -O2 sm3.c
$CC -fPIC -c -O2 sm2.c
#$AR r $LIB mrio1.o mrio2.o mrjack.o mrgcd.o mrxgcd.o mrarth3.o mrbits.o mrzzn3.o
#$AR r $LIB mrrand.o mrprime.o mrcrt.o mrscrt.o mrmonty.o mrcurve.o mrzzn2.o mrzzn2b.o mrsroot.o
#$AR r $LIB mrpower.o mrfast.o mrshs.o mrshs256.o mraes.o mrlucas.o mrstrong.o
#$AR r $LIB mrbrick.o mrebrick.o mrec2m.o mrgf2m.o mrshs512.o mrecn2.o
#$AR r $LIB sm3.o sm2.o  
#$CC -I. -O2  brent.c $LIB -o brent
#$CC -I. -O2  sm2_test.c $LIB -o test
$AR -rcv libsm2.a *.o
#rm mr*.o sm*.o
