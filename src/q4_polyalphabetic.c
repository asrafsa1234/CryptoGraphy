#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char key[1024],text[4096];size_t j=0,n;
 printf("Keyword: ");if(!fgets(key,sizeof key,stdin))return 1;
 key[strcspn(key,"\r\n")]=0;n=strlen(key);
 if(!n){fputs("Invalid keyword\n",stderr);return 1;}
 for(size_t i=0;i<n;i++){if(!((key[i]>='A'&&key[i]<='Z')||(key[i]>='a'&&key[i]<='z'))){fputs("Invalid keyword\n",stderr);return 1;}key[i]=(char)toupper((unsigned char)key[i]);}
 printf("Plaintext: ");if(!fgets(text,sizeof text,stdin))return 1;
 for(size_t i=0;text[i];i++){unsigned char c=(unsigned char)text[i];int shift;
  if(c>='a'&&c<='z'){shift=key[j++%n]-'A';text[i]=(char)('a'+(c-'a'+shift)%26);}
  else if(c>='A'&&c<='Z'){shift=key[j++%n]-'A';text[i]=(char)('A'+(c-'A'+shift)%26);}
 }
 printf("Ciphertext: %s",text);if(!strchr(text,'\n'))putchar('\n');return 0;
}
