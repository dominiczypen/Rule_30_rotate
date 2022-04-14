/* Author: Dominic van der Zypen
 * Rule 30 is an elementary cellular automaton introduced by Steven Wolfram
 * that produces chaotic  behaviour with a few elementary rules. 
 * See https://en.wikipedia.org/wiki/Rule_30 .
 * For every bit (call it 'center'), calculate
 * (left) XOR ((center) OR (right)), where (left) denotes the bit left of 
 * (center).
 * The 'left' bit of the left-most bit is the right-most bit and vice versa
 * --> can treat this with rotation.
 * Additionally, some spice is added in the rule_30 procedure by 
 * toggling bit 0 (rightmost bit)
 */

#include <stdio.h>
#include <stdint.h>

void rotate_right(uint64_t* up);
void rotate_left(uint64_t* up);
void rule_30(uint64_t* up);
void print_uint64_bin(uint64_t x);
void print_uint64_hex(uint64_t x);
//--------------------------------
void rotate_right(uint64_t* up)
{
  *up = ((*up) >> 1) | (((*up) & 1) << 63);
    // shift, and append old right-most bit to left end
}
//--------------------------------
void rotate_left(uint64_t* up)
{
  *up = ((*up) << 1) | (((*up) >> 63) & 1);
    // shift, and append old left-most bit to right end
}
//--------------------------------
void rule_30(uint64_t* up)
     // apply rule 30 and do rotation for the left/right-most bits.
{
  uint64_t u_left = *up;
  uint64_t u_right = *up;
  rotate_right(&u_left); 
     // --> for every bit position in *up, u_left contains left neighbor!
  rotate_left(&u_right); 
  *up = u_left ^ ((*up) | u_right); // this is rule 30!
  
  // add spice: toggle bit 0 (rightmost bit) with XOR
  *up = (*up) ^ 1;
}
//--------------------------------
void print_uint64_bin(uint64_t x)
{
  char i = 0;
  char mybit;
  while (i < 64)
  {
    mybit = (x >> 63) & 1;
    printf("%d", mybit);
    x = x << 1;
    i++;
    if (!(i & 3)) {printf(" ");} // formatting
  }
}
//-------------------------------
void print_uint64_hex(uint64_t x)
{
  char i = 0;
  char myhex;
  printf("0x");
  while (i < 16)
  {
    myhex = (x >> 60) & 0xf;
    printf("%x", myhex);
    x = x << 4;
    i++;
  }
}
//-------------------------------
int main()
{
  uint64_t x = 0; // initial value
  int i = 0;
  while (i < 80)
  {
    print_uint64_hex(x);
    printf(" ==\n");
    print_uint64_bin(x); 
    printf("\n");
    rule_30(&x);
    i++;
  }
  return 0;
}
