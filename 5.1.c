/*
 ============================================================================
 Name        : 5.1.c
 Author      : Kristina Fischer
 Description : Solution 5.1 from Cracking the Coding Interview (v6)
 
 Problem :     Given two 32-bit numbers, N and M, and two bit positions, i
               and j, write a method to insert M into N such that M starts at
               j and ends at i (assume that M fits inside of i->j).
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
  clear_substring clears the bits from i to j in a given number
  @params:  ints i and j = bit positions for substring to be cleared
            int num = number to be modified
  @returns: modified version of input num, with cleared i->j bits
*/
int clear_substring(int i, int j, int num) {

  int substring = 0;

  for (int k = i; k <= j; k++) {
    substring = substring + (1 << k); 
  }

  // at this point, substring looks like: 000...01111110...000
  //                                             j    i
  // take the inverse of that to get:     111...10000001...111
  // which you can & with N to clear that substring
  substring = ~substring;

  return (num & substring);
}

/*
  My solution: 
    1. clear bits i->j in N 
       => N'
    2. shift M left by i bits to match up with the cleared substring in N'
       => M'
    3. N' | M'
  
  @returns: int N' = modified N with bits i->j replaced with M  
*/
int main(int argc, char *argv[]) {

  // params:
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);
  int i = atoi(argv[3]);
  int j = atoi(argv[4]);
  printf("N: %d, M: %d, i: %d, j: %d\n", N, M, i, j);

  // 1. clear bits i through j in N:
  int N_prime = clear_substring(i, j, N);
  printf("N' (cleared substring): %d\n", N_prime);
  
  // 2. shift M left by i:
  int M_prime = (M << i);
  printf("M' (shifted left by i): %d\n", M_prime);

  // OR N' and M' to insert M into N:
  // answer should be 63 (0...00111111)
  printf("Answer: %d\n", (N_prime | M_prime));

  return 0;
}
