#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){int a=9,b=4,c=5,d=7,det=modn(a*d-b*c,26),iv=invmod(det,26);const char *s="meet me at the usual place at ten rather than eight oclock";char clean[256],encrypted[256],restored[256];int n=0;
 for(size_t i=0;s[i];i++)if(letter(s[i])>=0)clean[n++]=(char)('A'+letter(s[i]));
 if(n%2)clean[n++]='X';
 clean[n]=0;
 if(iv<0){puts("Matrix is not invertible");return 1;}
 for(int i=0;i<n;i+=2){int x=clean[i]-'A',y=clean[i+1]-'A';encrypted[i]=(char)('A'+modn(a*x+b*y,26));encrypted[i+1]=(char)('A'+modn(c*x+d*y,26));}
 encrypted[n]=0;int ia=modn(iv*d,26),ib=modn(-iv*b,26),ic=modn(-iv*c,26),id=modn(iv*a,26);
 for(int i=0;i<n;i+=2){int x=encrypted[i]-'A',y=encrypted[i+1]-'A';restored[i]=(char)('A'+modn(ia*x+ib*y,26));restored[i+1]=(char)('A'+modn(ic*x+id*y,26));}restored[n]=0;
 printf("Q12 Hill cipher 2x2\nKey: [[9,4],[5,7]]\nDeterminant mod 26: %d, inverse %d\nInverse matrix: [[%d,%d],[%d,%d]]\nPrepared plaintext: %s\nCiphertext: %s\nDecrypted: %s\n",det,iv,ia,ib,ic,id,clean,encrypted,restored);
 return strcmp(clean,restored)!=0;
}
