#/bin/bash
#
CC=gcc
AR=ar
LD=ld
RANLIB=ranlib

LIB=libsm2_x86.a
rm $LIB
cp mirdef_x86.lnx mirdef.h
$CC -m32 -c -O2 mrcore.c
$CC -m32 -c -O2 mrarth0.c
$CC -m32 -c -O2 mrarth1.c
$CC -m32 -c -O2 mrarth2.c
$CC -m32 -c -O2 mralloc.c
$CC -m32 -c -O2 mrsmall.c
$CC -m32 -c -O2 mrbits.c
$CC -m32 -c -O2 mrio1.c
$CC -m32 -c -O2 mrio2.c
$CC -m32 -c -O2 mrgcd.c
$CC -m32 -c -O2 mrjack.c
$CC -m32 -c -O2 mrxgcd.c
$CC -m32 -c -O2 mrarth3.c
$CC -m32 -c -O2 mrrand.c
$CC -m32 -c -O2 mrprime.c
$CC -m32 -c -O2 mrcrt.c
$CC -m32 -c -O2 mrscrt.c
$CC -m32 -c -O2 mrmonty.c
$CC -m32 -c -O2 mrpower.c
$CC -m32 -c -O2 mrcurve.c
$CC -m32 -c -O2 mrfast.c
$CC -m32 -c -O2 mrzzn2.c
$CC -m32 -c -O2 mrzzn2b.c
$CC -m32 -c -O2 mrzzn3.c
$CC -m32 -c -O2 mrecn2.c
$CC -m32 -c -O2 mrshs.c
$CC -m32 -c -O2 mrshs256.c
$CC -m32 -c -O2 mrshs512.c
$CC -m32 -c -O2 mraes.c
$CC -m32 -c -O2 mrgcm.c
$CC -m32 -c -O2 mrlucas.c
$CC -m32 -c -O2 mrstrong.c
$CC -m32 -c -O2 mrbrick.c
$CC -m32 -c -O2 mrebrick.c
$CC -m32 -c -O2 mrgf2m.c
$CC -m32 -c -O2 mrec2m.c
$CC -m32 -c -O2 mrsroot.c
$CC -m32 -c -O2 sm3.c
$CC -m32 -c -O2 sm2.c
$AR rc $LIB mrcore.o mrarth0.o mrarth1.o mrarth2.o mralloc.o mrsmall.o mrgcm.o
$AR r $LIB mrio1.o mrio2.o mrjack.o mrgcd.o mrxgcd.o mrarth3.o mrbits.o mrzzn3.o
$AR r $LIB mrrand.o mrprime.o mrcrt.o mrscrt.o mrmonty.o mrcurve.o mrzzn2.o mrzzn2b.o mrsroot.o
$AR r $LIB mrpower.o mrfast.o mrshs.o mrshs256.o mraes.o mrlucas.o mrstrong.o
$AR r $LIB mrbrick.o mrebrick.o mrec2m.o mrgf2m.o mrshs512.o mrecn2.o
$AR r $LIB sm3.o sm2.o  
$CC -I. -O2 -m32 brent.c $LIB -o brent
$CC -I. -O2 -m32 sm2_test.c $LIB -o test
rm mr*.o sm*.o
