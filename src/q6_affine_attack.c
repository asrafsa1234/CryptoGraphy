#include <stdio.h>
#include <string.h>
#include <ctype.h>
static int mod(int x){int r=x%26;return r<0?r+26:r;}
static int inverse(int a){for(int i=1;i<26;i++)if(a*i%26==1)return i;return -1;}
int main(void){char ct[8192],out[8192];int freq[26]={0},order[26];
 printf("Ciphertext: ");if(!fgets(ct,sizeof ct,stdin))return 1;
 for(size_t i=0;ct[i];i++){unsigned char c=(unsigned char)ct[i];if(c>='a'&&c<='z')freq[c-'a']++;else if(c>='A'&&c<='Z')freq[c-'A']++;}
 for(int i=0;i<26;i++)order[i]=i;
 for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)if(freq[order[j]]>freq[order[i]]){int t=order[i];order[i]=order[j];order[j]=t;}
 puts("Letter frequency (descending):");for(int i=0;i<26;i++)printf("%c: %d\n",'A'+order[i],freq[order[i]]);
 puts("Hypothesis: plaintext E,T encrypt to B,U (not proof). Derived a=3, b=15:");
 /* E=4,T=19 -> B=1,U=20: 4a+b=1,19a+b=20;
    15a=19 (mod26), inverse(15)=7 => a=3; b=1-12=-11=15. */
 for(int a=1;a<26;a++){int inv=inverse(a);if(inv<0)continue;for(int b=0;b<26;b++){
  if(!(a==3&&b==15)&&!(a==3&&b==1))continue;
  strcpy(out,ct);for(size_t i=0;out[i];i++){unsigned char c=(unsigned char)out[i];int base=(c>='A'&&c<='Z')?'A':((c>='a'&&c<='z')?'a':0);if(base)out[i]=(char)(base+mod(inv*((c-base)-b)));}
  printf("Candidate (a=%d,b=%d): %s",a,b,out);if(!strchr(out,'\n'))putchar('\n');
 }}puts("Without full ciphertext and verified mappings, no unique plaintext can be recovered.");return 0;
}
