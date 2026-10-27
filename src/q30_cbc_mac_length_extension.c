#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){unsigned char x=0x42,key=0x37;unsigned char t=(unsigned char)((x^0)+key),y=x^t,tag2=(unsigned char)((y^t)+key);
 printf("Q30 Variable-length CBC-MAC forgery, toy block cipher E(v)=v+key mod 256\nX=%02X T=MAC(X)=%02X\nForged second block X xor T=%02X\nMAC(X||(X xor T))=%02X\n",x,t,y,tag2);puts("Security issue: basic CBC-MAC must fix message length or use CMAC.");return t!=tag2;
}
