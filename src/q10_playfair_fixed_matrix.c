#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){const char grid[26]="MFHIKUNOPQZVWXYELARGDSTBC";const char *msg="Must see you over Cadogan West. Coming at once.";char pt[256],out[256];int n=0,m=0;
 printf("Q10 Playfair fixed matrix\n");for(int i=0;i<25;i++)printf("%c%c",grid[i],i%5==4?'\n':' ');
 for(size_t i=0;msg[i];i++){int x=letter(msg[i]);if(x>=0)pt[n++]=(char)('A'+(x==9?8:x));}
 for(int i=0;i<n;){char a=pt[i++],b='X';if(i<n&&pt[i]!=a)b=pt[i++];else if(a=='X')b='Q';out[m++]=a;out[m++]=b;}
 printf("Message: %s\nPrepared: %.*s\nCiphertext: ",msg,m,out);
 for(int i=0;i<m;i+=2){int a=-1,b=-1;for(int j=0;j<25;j++){if(grid[j]==out[i])a=j;if(grid[j]==out[i+1])b=j;}if(a<0||b<0)return 1;
 if(a/5==b/5){a=a/5*5+(a%5+1)%5;b=b/5*5+(b%5+1)%5;}else if(a%5==b%5){a=(a/5+1)%5*5+a%5;b=(b/5+1)%5*5+b%5;}else{int x=a%5;a=a/5*5+b%5;b=b/5*5+x;}putchar(grid[a]);putchar(grid[b]);}putchar('\n');return 0;
}
