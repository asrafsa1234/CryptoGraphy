#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){int p=59,q=61,n=p*q,phi=(p-1)*(q-1),old_e=31,new_e=17;printf("Q26 Leaked RSA private key\nModulus n=%d, leaked d=%d\n",n,invmod(old_e,phi));
 printf("Factor n=%d x %d, phi=%d\n",p,q,phi);printf("Rotating exponent under SAME n: e=%d d=%d\n",new_e,invmod(new_e,phi));puts("UNSAFE: knowledge of an old private key plus its public exponent can reveal phi(n)/factorization; generate fresh primes and modulus.");return 0;
}
