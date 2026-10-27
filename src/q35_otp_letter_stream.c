#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){char msg[2048],keys[8192];int shifts[2048],n=0;printf("Q35 One-time-pad-style Vigenere shift stream\nPlaintext [SENDMOREMONEY]: ");read_line(msg,sizeof msg);if(!*msg)strcpy(msg,"SENDMOREMONEY");
 printf("Key shifts (space separated) [9 0 1 7 23 15 21 14 11 11 2 8 9]: ");read_line(keys,sizeof keys);if(!*keys)strcpy(keys,"9 0 1 7 23 15 21 14 11 11 2 8 9");
 char *t=strtok(keys," ,");while(t&&n<2048){char *end;long k=strtol(t,&end,10);if(*end||k<0||k>25){puts("Invalid shift (0..25)");return 1;}shifts[n++]=(int)k;t=strtok(NULL," ,");}
 int i=0;printf("Ciphertext: ");for(size_t j=0;msg[j];j++){if(letter(msg[j])>=0){if(i>=n){puts("\nInsufficient key stream");return 1;}putchar(shifted(msg[j],shifts[i++]));}else putchar(msg[j]);}printf("\nConsumed %d of %d key shifts\n",i,n);return 0;
}
