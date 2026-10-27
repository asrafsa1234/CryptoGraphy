#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){const char *p="sendmoremoney",*target="cashnotneeded";int key[]={9,0,1,7,23,15,21,14,11,11,2,8,9};char ct[32],altkey[32];int n=13;
 puts("Q14 One-time-pad style letter shifts (educational)");for(int i=0;i<n;i++){ct[i]=(char)('a'+(p[i]-'a'+key[i])%26);altkey[i]=(char)('A'+modn(ct[i]-target[i],26));}ct[n]=altkey[n]=0;
 printf("Plaintext: %s\nCiphertext: %s\nAlternative plaintext: %s\nAlternative key (A=0): ",p,ct,target);for(int i=0;i<n;i++)printf("%d%s",altkey[i]-'A',i+1<n?" ":"\n");return 0;
}
