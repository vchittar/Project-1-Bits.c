/* Copyright (C) 1991-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
int oddBits();
int test_oddBits();
int bitXor(int, int);
int test_bitXor(int, int);
int swapBytes(int);
int test_swapBytes(int);
int rotateRight(int, int);
int test_rotateRight(int, int);
int evenBitsCount(int);
int test_evenBitsCount(int);
int tmax();
int test_tmax();
int subOK(int, int);
int test_subOK(int, int);
int rempwr2(int, int);
int test_rempwr2(int, int);
int satMul2(int);
int test_satMul2(int);
int isGreaterOrEqual(int, int);
int test_isGreaterOrEqual(int, int);
int multSevenSixteenths(int);
int test_multSevenSixteenths(int);
int isNonZero(int);
int test_isNonZero(int);
unsigned float_abs(unsigned);
unsigned test_float_abs(unsigned);
int float_f2i(unsigned);
int test_float_f2i(unsigned);
unsigned float_quarter(unsigned);
unsigned test_float_quarter(unsigned);
