#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){int pt[2][2]={{1,0},{0,1}},ct[2][2]={{9,4},{5,7}};puts("Q38 Hill known/chosen plaintext 2x2 key recovery");
 puts("Known plaintext column matrix P=identity (BA and AB). Then K=C*P^{-1}=C.");printf("Recovered K=[[ %d, %d ],[ %d, %d ]]\n",ct[0][0],ct[0][1],ct[1][0],ct[1][1]);printf("Check BA -> %c%c\n",'A'+modn(ct[0][0]*pt[0][0]+ct[0][1]*pt[1][0],26),'A'+modn(ct[1][0]*pt[0][0]+ct[1][1]*pt[1][0],26));puts("Arbitrary known pairs need an invertible 2x2 plaintext matrix modulo 26.");return 0;
}
