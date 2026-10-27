#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(void) {
 char line[4096], keybuf[100], *end; long k;
 printf("Caesar cipher\nKey (1-25): ");
 if(!fgets(keybuf,sizeof keybuf,stdin)) return 1;
 k=strtol(keybuf,&end,10);
 while(isspace((unsigned char)*end)) end++;
 if(end==keybuf||*end||k<1||k>25) {fputs("Invalid key\n",stderr);return 1;}
 printf("Plaintext: ");if(!fgets(line,sizeof line,stdin))return 1;
 for(size_t i=0;i<strlen(line);i++){
  unsigned char c=(unsigned char)line[i];
  if(c>='a'&&c<='z')line[i]=(char)('a'+(c-'a'+k)%26);
  else if(c>='A'&&c<='Z')line[i]=(char)('A'+(c-'A'+k)%26);
 }
 printf("Ciphertext: %s",line);if(!strchr(line,'\n'))putchar('\n');return 0;
}
