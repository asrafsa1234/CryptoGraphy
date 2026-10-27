#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"
int main(void){char ct[4096],out[4096];int want=10,cnt[26]={0},indices[26],seen[26]={0};const char *rank="ETAOINSHRDLCUMWFGYPBVKJXQZ";
 printf("Q40 Substitution frequency heuristic (NOT proven cryptanalysis)\nCiphertext [GSRH RH Z HVXIVG]: ");read_line(ct,sizeof ct);if(!*ct)strcpy(ct,"GSRH RH Z HVXIVG");
 printf("Candidate count (1-26) [10]: ");char t[40];read_line(t,sizeof t);if(*t)want=atoi(t);if(want<1||want>26)return 1;
 for(size_t i=0;ct[i];i++)if(letter(ct[i])>=0)cnt[letter(ct[i])]++;
 for(int i=0;i<26;i++)indices[i]=i;
 for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)if(cnt[indices[j]]>cnt[indices[i]]){int x=indices[j];indices[j]=indices[i];indices[i]=x;}
 for(int a=0;a<want;a++){char map[26];for(int i=0;i<26;i++)map[indices[i]]=rank[i];
 /* Vary the assignment of two lower-ranked characters for alternate hypotheses. */
 if(a){int i=modn(a+7,24),j=i+1;char x=map[indices[i]];map[indices[i]]=map[indices[j]];map[indices[j]]=x;}
 for(size_t i=0;ct[i];i++){int v=letter(ct[i]);out[i]=v<0?ct[i]:(char)((islower((unsigned char)ct[i])?'a':'A')+map[v]-'A');out[i+1]=0;}
 printf("%2d. frequency-mapping candidate: %s\n",a+1,out);seen[a]=1;}
 (void)seen;puts("CAUTION: unigram mapping does not reliably solve arbitrary substitution ciphertext.");return 0;
}
