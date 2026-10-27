#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char key[100],text[4096];int seen[26]={0};
 printf("Substitution alphabet (26 letters): ");if(!fgets(key,sizeof key,stdin))return 1;
 key[strcspn(key,"\r\n")]=0;
 if(strlen(key)!=26){fputs("Invalid substitution key\n",stderr);return 1;}
 for(int i=0;i<26;i++){
  unsigned char c=(unsigned char)key[i];if(!isalpha(c)||c>127){fputs("Invalid substitution key\n",stderr);return 1;}
  key[i]=(char)toupper(c);if(seen[key[i]-'A']++){fputs("Duplicate key letter\n",stderr);return 1;}
 }
 printf("Plaintext: ");if(!fgets(text,sizeof text,stdin))return 1;
 for(size_t i=0;text[i];i++){
  unsigned char c=(unsigned char)text[i];
  if(c>='A'&&c<='Z')text[i]=key[c-'A'];
  else if(c>='a'&&c<='z')text[i]=(char)tolower((unsigned char)key[c-'a']);
 }
 printf("Ciphertext: %s",text);if(!strchr(text,'\n'))putchar('\n');return 0;
}
