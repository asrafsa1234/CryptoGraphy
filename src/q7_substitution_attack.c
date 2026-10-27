#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/* UTF-8 glyphs are treated as indivisible ciphertext symbols. */
typedef struct {char bytes[5];int count;} Symbol;
static int glyph(FILE *f,char out[5]){int c=fgetc(f);if(c==EOF)return 0;unsigned char x=(unsigned char)c;int size=x<128?1:(x>=0xF0?4:(x>=0xE0?3:2));out[0]=(char)x;for(int i=1;i<size;i++){c=fgetc(f);if(c==EOF)return -1;out[i]=(char)c;}out[size]=0;return 1;}
int main(int argc,char**argv){const char *path=argc>1?argv[1]:"data/q7_ciphertext.txt";FILE *f=fopen(path,"rb");Symbol syms[256]={0};int n=0,ret;char g[5];
 if(!f){perror(path);return 1;}while((ret=glyph(f,g))>0){if(!strcmp(g,"\n")||!strcmp(g,"\r")||!strcmp(g," "))continue;int i;for(i=0;i<n;i++)if(!strcmp(g,syms[i].bytes))break;if(i==n){if(n==256){fputs("Too many symbols\n",stderr);fclose(f);return 1;}strcpy(syms[n++].bytes,g);}syms[i].count++;}fclose(f);if(ret<0){fputs("Truncated UTF-8 input\n",stderr);return 1;}
 for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(syms[j].count>syms[i].count){Symbol t=syms[i];syms[i]=syms[j];syms[j]=t;}
 puts("Ciphertext symbol frequencies:");for(int i=0;i<n;i++)printf("%s : %d\n",syms[i].bytes,syms[i].count);
 puts("Hypothesis testing: optional mapping file lines are SYMBOL LETTER, one per line.");
 if(argc>2){FILE *map=fopen(argv[2],"r");if(!map){perror(argv[2]);return 1;}char from[16],to[16];while(fscanf(map,"%15s %15s",from,to)==2){if(strlen(to)!=1){fputs("Mapping value must be a letter\n",stderr);fclose(map);return 1;}for(int i=0;i<n;i++)if(!strcmp(syms[i].bytes,from))printf("Hypothesis %s -> %s (count %d)\n",from,to,syms[i].count);}fclose(map);}
 puts("Symbol frequencies alone do not verify a complete plaintext.");return 0;
}
