#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){unsigned char p[]={0x00,0x01,0x02,0x03},c[sizeof p],d[sizeof p];int a=5,b=7,iv=0xAA,prev=iv,inverse=invmod(a,256);puts("Q22 CBC using affine modulo 256; a=5 b=7 IV=AA");
 for(size_t i=0;i<sizeof p;i++){c[i]=(unsigned char)modn(a*(p[i]^prev)+b,256);prev=c[i];}prev=iv;
 for(size_t i=0;i<sizeof p;i++){d[i]=(unsigned char)(modn(inverse*(c[i]-b),256)^prev);prev=c[i];}
 printf("Plaintext: ");for(size_t i=0;i<sizeof p;i++)printf("%02X ",p[i]);printf("\nCiphertext: ");for(size_t i=0;i<sizeof p;i++)printf("%02X ",c[i]);printf("\nDecrypted: ");for(size_t i=0;i<sizeof p;i++){printf("%02X ",d[i]);if(p[i]!=d[i])return 1;}puts("\nEducational affine cipher (not secure). S-DES vector does not apply to this selected cipher.");return 0;
}
