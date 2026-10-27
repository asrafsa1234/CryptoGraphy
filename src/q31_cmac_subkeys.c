#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

static void dbl(unsigned char *s,int n,unsigned char rb){unsigned carry=0;for(int i=n-1;i>=0;i--){unsigned nxt=s[i]>>7;s[i]=(unsigned char)((s[i]<<1)|carry);carry=nxt;}if(carry)s[n-1]^=rb;}
int main(void){unsigned char k64[8]={0x80},k128[16]={0x80};puts("Q31 CMAC GF(2^n) subkey doubling");
 dbl(k64,8,0x1B);printf("64-bit Rb=0x1B, K1: ");for(int i=0;i<8;i++)printf("%02X",k64[i]);dbl(k64,8,0x1B);printf("\n64-bit K2: ");for(int i=0;i<8;i++)printf("%02X",k64[i]);
 dbl(k128,16,0x87);printf("\n128-bit Rb=0x87, K1: ");for(int i=0;i<16;i++)printf("%02X",k128[i]);dbl(k128,16,0x87);printf("\n128-bit K2: ");for(int i=0;i<16;i++)printf("%02X",k128[i]);puts("\nShift is multiplication by x; conditional Rb XOR reduces modulo the irreducible polynomial.");return 0;
}
