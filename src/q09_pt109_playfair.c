#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){const char *ct="KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";char key[128],table[25],prepared[256]={0};int seen[26]={0},p=0;
 printf("Q09 PT-109 Playfair cryptogram\nCiphertext: %s\n",ct);
 printf("Enter candidate Playfair keyword (required): ");read_line(key,sizeof key);if(!*key){puts("A unique decoding needs the original key. No plaintext has been guessed.");return 0;}
 for(size_t i=0;key[i];i++){int x=letter(key[i]);if(x<0){puts("Invalid key");return 1;}if(x==9)x=8;if(!seen[x]){seen[x]=1;table[p++]=(char)('A'+x);}}
 for(int x=0;x<26;x++)if(x!=9&&!seen[x])table[p++]=(char)('A'+x);
 for(int i=0;i<25;i++)printf("%c%c",table[i],i%5==4?'\n':' ');
 int positions[26];for(int i=0;i<25;i++)positions[table[i]-'A']=i;positions[9]=positions[8];int n=0;
 for(size_t i=0;ct[i];i++)if(letter(ct[i])>=0)prepared[n++]=(char)('A'+letter(ct[i]));
 printf("Candidate decryption: ");for(int i=0;i+1<n;i+=2){int a=positions[prepared[i]-'A'],b=positions[prepared[i+1]-'A'];if(a/5==b/5){a=a/5*5+(a%5+4)%5;b=b/5*5+(b%5+4)%5;}else if(a%5==b%5){a=(a/5+4)%5*5+a%5;b=(b/5+4)%5*5+b%5;}else{int z=a%5;a=a/5*5+b%5;b=b/5*5+z;}putchar(table[a]);putchar(table[b]);}putchar('\n');puts("This is a candidate only; verify with historical context.");return 0;
}
