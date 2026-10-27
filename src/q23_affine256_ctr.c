#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){unsigned char p[]={0x00,0x01,0x00,0x02,0x00,0x04},c[sizeof p],d[sizeof p];int a=5,b=7,ctr=0;puts("Q23 CTR using affine modulo 256, counter 00");
 for(size_t i=0;i<sizeof p;i++){unsigned char stream=(unsigned char)modn(a*(ctr++)+b,256);c[i]=p[i]^stream;d[i]=c[i]^stream;}
 printf("Plaintext: ");for(size_t i=0;i<sizeof p;i++)printf("%02X ",p[i]);printf("\nCiphertext: ");for(size_t i=0;i<sizeof p;i++)printf("%02X ",c[i]);printf("\nRecovered: ");for(size_t i=0;i<sizeof p;i++){printf("%02X ",d[i]);if(p[i]!=d[i])return 1;}puts("\nAffine mode demonstration only (not cryptographically secure).");return 0;
}
