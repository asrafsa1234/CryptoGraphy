#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){char msg[256];unsigned char padded[512]={0};printf("Q21 ISO-style 1-bit then zero padding (block size 8 bytes)\nMessage [HELLO123]: ");read_line(msg,sizeof msg);if(!*msg)strcpy(msg,"HELLO123");size_t len=strlen(msg),total=((len/8)+1)*8;memcpy(padded,msg,len);padded[len]=0x80;
 printf("Plaintext bytes: %zu\nPadded bytes: %zu\nPadded hex: ",len,total);for(size_t i=0;i<total;i++)printf("%02X",padded[i]);puts("\nAlways append a full block for already-aligned input to make padding removal unambiguous.");return 0;
}
