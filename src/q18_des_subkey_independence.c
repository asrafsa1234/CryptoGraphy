#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"
static const int pc1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4},pc2[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
static const int shifts[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
static unsigned long long perm(unsigned long long x,const int *t,int m,int input){unsigned long long y=0;for(int i=0;i<m;i++)y=(y<<1)|((x>>(input-t[i]))&1ULL);return y;}
static void subkeys(unsigned long long key,unsigned long long out[16]){unsigned long long z=perm(key,pc1,56,64);unsigned c=(unsigned)((z>>28)&0xfffffff),d=(unsigned)(z&0xfffffff);
 for(int i=0;i<16;i++){int s=shifts[i];c=((c<<s)|(c>>(28-s)))&0xfffffff;d=((d<<s)|(d>>(28-s)))&0xfffffff;out[i]=perm(((unsigned long long)c<<28)|d,pc2,48,56);}}

int main(void){unsigned long long k[16];subkeys(0x133457799BBCDFF1ULL,k);puts("Q18 DES PC-1 and PC-2 separation\nPC-1 creates disjoint C and D halves (28 bits each).");
 int a=0,b=0;for(int i=0;i<48;i++){if(pc2[i]<=28)a++;else b++;}printf("PC-2 selects %d bits from C and %d bits from D.\n",a,b);
 printf("Example K1=%012llX K16=%012llX\n",k[0],k[15]);return a!=24||b!=24;}
