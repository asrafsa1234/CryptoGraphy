#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){unsigned char p[3]={0x12,0x34,0x56},c[3],r[3],iv=0xAA;for(int i=0;i<3;i++)c[i]=(unsigned char)((p[i]^(i?c[i-1]:iv))+7);
 printf("Q20 CBC error propagation using toy E(x)=x+7 modulo 256\nOriginal ciphertext: %02X %02X %02X\n",c[0],c[1],c[2]);c[0]^=1;
 for(int i=0;i<3;i++)r[i]=(unsigned char)(((unsigned char)(c[i]-7))^(i?c[i-1]:iv));
 printf("Corrupt C1 -> decrypted blocks: %02X %02X %02X\n",r[0],r[1],r[2]);puts("Only P1 and P2 affected by transmission error in C1; later blocks unaffected.");puts("A source bit error in P1 changes every later CBC ciphertext block; receiver recovers modified P1 but unchanged P2 onward.");return 0;
}
