#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"
static const double english[26]={8.17,1.49,2.78,4.25,12.70,2.23,2.02,6.09,6.97,.15,.77,4.03,2.41,6.75,7.51,1.93,.10,5.99,6.33,9.06,2.76,.98,2.36,.15,1.97,.07};
int main(void){char ct[4096];int want=10,n=0,counts[26]={0},order[26];double scores[26];
 printf("Q15 Additive/Caesar frequency attack\nCiphertext [KHOOR ZRUOG]: ");read_line(ct,sizeof ct);if(!*ct)strcpy(ct,"KHOOR ZRUOG");
 printf("How many candidates (1-26) [10]: ");char buf[30];read_line(buf,sizeof buf);if(*buf)want=atoi(buf);if(want<1||want>26){puts("Invalid candidate count");return 1;}
 for(int i=0;ct[i];i++)if(letter(ct[i])>=0){counts[letter(ct[i])]++;n++;}
 if(!n){puts("No alphabetic ciphertext");return 1;}
 for(int k=0;k<26;k++){double score=0;for(int j=0;j<26;j++){double expected=english[j]*n/100.0,obs=counts[(j+k)%26];double z=obs-expected;score+=z*z/expected;}scores[k]=score;order[k]=k;}
 for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)if(scores[order[j]]<scores[order[i]]){int x=order[j];order[j]=order[i];order[i]=x;}
 for(int i=0;i<want;i++){int k=order[i];printf("%2d. key=%2d chi2=%8.2f plaintext=",i+1,k,scores[k]);for(int j=0;ct[j];j++)putchar(shifted(ct[j],-k));putchar('\n');}return 0;
}
