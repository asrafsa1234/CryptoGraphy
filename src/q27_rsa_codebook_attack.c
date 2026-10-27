#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){const char *s="HELLO";long long n=3599,e=31;puts("Q27 RSA per-letter deterministic encryption attack");
 for(int i=0;s[i];i++){long long ct=powmod(s[i]-'A',e,n);int found=-1;for(int x=0;x<26;x++)if(powmod(x,e,n)==ct){found=x;break;}printf("Cipher=%4lld recovered=%c\n",ct,found<0?'?':'A'+found);}
 puts("Attack: precompute all 26 RSA encryptions under public key; look up each encrypted symbol. No factoring required.");return 0;
}
