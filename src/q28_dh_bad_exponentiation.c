#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){long long a=5,x=3,y=4,A=powmod(a,x,23),B=powmod(a,y,23),good=powmod(B,x,23);
 printf("Q28 Diffie-Hellman comparison\nCorrect modular DH: a=%lld mod 23, Alice=%lld Bob=%lld, key=%lld\n",a,A,B,good);
 long long ax=1,ay=1;for(int i=0;i<a;i++){ax*=x;ay*=y;}printf("Incorrect exchange x^a=%lld y^a=%lld\n",ax,ay);
 puts("Eve recovers secrets with integer a-th roots (or obvious small-domain trial); this is insecure. Multiplication/xor of transmitted values is not a shared-secret protocol.");return 0;
}
