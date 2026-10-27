#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
static int mod(long x){int r=(int)(x%26);return r<0?r+26:r;}
static int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
static int inverse(int a){for(int i=1;i<26;i++)if((a*i)%26==1)return i;return -1;}
static int readint(const char*prompt,long*value){char buf[100],*end;printf("%s",prompt);if(!fgets(buf,sizeof buf,stdin))return 0;*value=strtol(buf,&end,10);if(end==buf)return 0;while(isspace((unsigned char)*end))end++;return *end==0;}
int main(void){char text[4096],enc[4096],dec[4096];long av,bv;int a,b,inv;
 if(!readint("a: ",&av)||!readint("b: ",&bv)){fputs("Invalid integer key\n",stderr);return 1;}
 a=mod(av);b=mod(bv);if(gcd(a,26)!=1){fputs("Invalid a: gcd(a,26) must equal 1\n",stderr);return 1;}
 inv=inverse(a);printf("Plaintext: ");if(!fgets(text,sizeof text,stdin))return 1;
 strcpy(enc,text);strcpy(dec,text);
 for(size_t i=0;text[i];i++){unsigned char c=(unsigned char)text[i];int base=(c>='A'&&c<='Z')?'A':((c>='a'&&c<='z')?'a':0);if(!base)continue;
  enc[i]=(char)(base+mod(a*(c-base)+b));dec[i]=(char)(base+mod(inv*(enc[i]-base-b)));
 }
 printf("Normalized key: a=%d b=%d inverse=%d\nCiphertext: %s",a,b,inv,enc);if(!strchr(enc,'\n'))putchar('\n');printf("Decrypted: %s",dec);if(!strchr(dec,'\n'))putchar('\n');return 0;
}
