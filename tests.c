/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

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
int test_oddBits(void) {
  int result = 0;
  int i;
  for (i = 1; i < 32; i+=2)
    result |= 1<<i;
  return result;
}
int test_bitXor(int x, int y)
{
  return x^y;
}
int test_swapBytes(int x)
{
    unsigned char byte0 = (x >> 0);
    unsigned char byte1 = (x >> 8);
    unsigned char byte2 = (x >> 16);
    unsigned char byte3 = (x >> 24);
    unsigned result = (byte0<<24)|(byte1<<8)|(byte2<<16)|(byte3<<0);
    return result;
}
int test_rotateRight(int x, int n) {
  unsigned u = (unsigned) x;
  int i;
  for (i = 0; i < n; i++) {
      unsigned lsb = (u & 1) << 31;
      unsigned rest = u >> 1;
      u = lsb | rest;
  }
  return (int) u;
}
int test_evenBitsCount(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i+=2)
    result += (x >> i) & 0x1;
  return result;
}
int test_tmax(void) {
  return 0x7FFFFFFF;
}
int test_subOK(int x, int y)
{
  long long ldiff = (long long) x - y;
  return ldiff == (int) ldiff;
}
int test_rempwr2(int x, int n)
{
    int p2n = 1<<n;
    return x%p2n;
}
int test_satMul2(int x)
{
  if ((x+x)/2 != x)
    return x < 0 ? 0x80000000 : 0x7FFFFFFF;
  else
    return 2*x;
}
int test_isGreaterOrEqual(int x, int y)
{
  return x >= y;
}
int test_multSevenSixteenths(int x)
{
  return (x*7)/16;
}
int test_isNonZero(int x)
{
  return x!=0;
}
unsigned test_float_abs(unsigned uf) {
  float f = u2f(uf);
  unsigned unf = f2u(-f);
  if (isnan(f))
    return uf;
  /* An unfortunate hack to get around a limitation of the BDD Checker */
  if ((int) uf < 0)
      return unf;
  else
      return uf;
}
int test_float_f2i(unsigned uf) {
  float f = u2f(uf);
  int x = (int) f;
  return x;
}
unsigned test_float_quarter(unsigned uf) {
  float f = u2f(uf);
  float hf = 0.25*f;
  if (isnan(f))
    return uf;
  else
    return f2u(hf);
}
