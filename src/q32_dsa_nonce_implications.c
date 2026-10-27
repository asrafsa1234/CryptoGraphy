#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){int p=23,q=11,g=4,x=3,h=9;int k1=3,k2=7,ks[2]={k1,k2};puts("Q32 Toy DSA nonce demonstration (educational numbers only)");
 for(int j=0;j<2;j++){int k=ks[j],r=(int)(powmod(g,k,p)%q),s=modn(invmod(k,q)*(h+x*r),q);printf("Signature %d: k=%d (r,s)=(%d,%d)\n",j+1,k,r,s);}
 puts("Fresh unpredictable nonces change DSA signatures; nonce reuse or leakage can expose the private key. Deterministic RSA textbook signatures repeat; modern RSA-PSS signatures are randomized.");return 0;
}
