#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){char key[128],pt[2048],alphabet[27]={0};int used[26]={0},k=0;
 printf("Q08 Keyword monoalphabetic substitution\nKeyword [CIPHER]: ");read_line(key,sizeof key);if(!*key)strcpy(key,"CIPHER");
 for(size_t i=0;key[i];i++){int x=letter(key[i]);if(x<0){puts("Invalid keyword");return 1;}if(!used[x]){used[x]=1;alphabet[k++]=(char)('A'+x);}}
 for(int x=0;x<26;x++)if(!used[x])alphabet[k++]=(char)('A'+x);
 printf("Plain alphabet : ABCDEFGHIJKLMNOPQRSTUVWXYZ\nCipher alphabet: %s\nPlaintext: ",alphabet);read_line(pt,sizeof pt);
 for(size_t i=0;pt[i];i++){int x=letter(pt[i]);if(x>=0)pt[i]=(char)((pt[i]>='a'&&pt[i]<='z'?'a':'A')+alphabet[x]-'A');}
 printf("Ciphertext: %s\n",pt);return 0;
}
