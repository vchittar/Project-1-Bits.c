/*
 * CS:APP Data Lab
 *
 * Vishnu Chittari URID: 28238454
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
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
   header in order to pre-include it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/*
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
 int main (void)
 {


int oddBits(int x) {

    int num = (0xAA << 8) + 0xAA;
    num = (num << 16) + num;

  return !((x & num) ^ num);
}
/*
 * bitXor - x^y using only ~ and |
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ |
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
// xor function written
return ~((~(~(x|x)|~(y|y)))|(~(x|y)));
}
/*
 * swapBytes - swaps the first and last bytes of x
 *   Example: swapBytes(0x01020304) = 0x04020301
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int swapBytes(int x) {

    int bit = ((0xFF) << 16) | (0xFF << 8);
    int cut = x & bit;
    int LBit = x << 24;
    int RBit = (x >> 24) & (0xFF);
    return (cut | LBit | RBit);

   // unsigned int b2 = (0x01020304); //ask for help

  //return 0;
}
/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {

 int newByte = x << (32 + (~n +1)); // shifts x by 32-n positions to the front of the number
  int mask_byte = ~(1 << 31); // shifts t-max by n-1
  mask_byte = mask_byte >> (n+((~1)+1));// Thus removing where the new bits will go

  // shift x by n to move the number over, thus leaving space for the rotated bits
  x = x >> n;
  x = x & mask_byte;
  return x | newByte;


    //return x >> n;

}
/*
 * evenBitsCount - returns count of number of 1's in even numbered spaces in the word
 *   Examples: evenBitsCount(5) = 2, evenBitsCount(7) = 2, evenBitsCount(10)= 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int evenBitsCount(int x,int n) { //need to double check

    x = 0x55;
    n = (x + (x<<8) + (x<<16) + (x<<24));
    return n;

}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(int x) {
    // smallest number shifted completely to the left and then later negated to provide the max number

   return ~(1 << 31);



}
/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {


  int diff = x + (~y + 1);
  int same = x ^ y;
  int diffSign = diff ^ x;

  return !((same & diffSign) >> 31);
}
/*
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remaindersS
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {

    int rex = (x >> 31) &((1 << 31) >> 31);
    return (x + rex) >> n;
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {

  return 2;
}
/*
 * isGreaterOrEqual - if x >= y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreaterOrEqual(int x, int y) {

  return 2;
}
/*
 * multSevenSixteenths - multiplies by 7/16 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*7/16),
 *   including overflow behavior.
 *   Examples: multSevenSixteenths(77) = 33
 *             multSevenSixteenths(-22) = -9
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multSevenSixteenths(int x) { //Still need help

    int multSeven = (x<<2) + x;
    int addNum = 7 & (multSeven >> 129);
    int divSixteenth = (multSeven + addNum) >> 3;

  return 2;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {

//for negative numbers if the sign bit is set
// for the positive integers ~x+1 will be positive
// thus using the or will enable is to check whether we have the positive or negative x
  return ((x | (~x +1)) >> 31) & 1;

}
/*
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
//unsigned float_abs(unsigned uf) {
/*
    unsigned num1 = 0x7FFFFFFF;
    unsigned min = 0x7F800001;
    unsigned diff = uf & num1;

    if (diff >= min)
    {

        return uf;
    }
    else{
        return diff;
    }
*/

unsigned float_abs(unsigned uf) {

  unsigned frac = uf&0x7FFFFF;

  unsigned exp = (uf>>23)&0xFF;

  if(exp == 0xFF && frac != 0)

    return uf;

  return uf&0x7FFFFFFF;


}
/*
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
            // FIX THE VARIABLES OF THE CODE LATER
int float_f2i(unsigned uf) {
  int float_f2i(unsigned uf) {
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac =(uf & 0x7FFFFF);
  unsigned bias = 0x7F;
  unsigned ans = frac;


  if (exp == 0xFF)
  {
    return 0x80000000u;
  }


  if (exp < bias)
  {
    return 0x0;
  }

  // normalized cases
  exp -= bias;

  // overflow case
  if (exp >= 31)
  {
    return 0x80000000u;
  }

  // integer result will shift after the corresponding bits
  if (exp > 22)
  {
    ans = frac << (exp - 23);
  }
  else
  {
    ans = frac >> (23 - exp);
  }

  // add 1 if less than the normalized cases
  ans += 1 << exp;

  // if the sign given is 1, then change the sign
  if (sign) {
    ans = -ans;
  }

  return ans;
}

/*
 * float_quarter - Return bit-level equivalent of expression 0.25*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_quarter(unsigned uf) {

  int exponent = (uf >> 23) & 0x0ff;
  int exp = exponent - 127;
  int frac = uf & 0x7fffff;

  if(exponent == 0x7F800000)
    return 0x80000000u;
  if(!exponent)
    return 0;
  if(exp < 0)
    return 0;
  if(exp > 30)
    return 0x80000000u;

  frac = frac | 0x800000;
  if (exp >= 23)
    frac = frac << (exp - 23);
  else
    frac = frac >> (23 - exp);

  if((uf >> 31) & 1)
    return ~frac + 1;

  return frac;


  return 2;
}
 }
 }
