#ifndef LAB_COMMON_H
#define LAB_COMMON_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
static inline int modn(int x,int n){int r=x%n;return r<0?r+n:r;}
static inline int gcd_int(int a,int b){a=abs(a);b=abs(b);while(b){int t=a%b;a=b;b=t;}return a;}
static inline int invmod(int a,int n){for(int x=1;x<n;x++)if(modn(a*x,n)==1)return x;return -1;}
static inline void read_line(char *s,size_t n){if(fgets(s,(int)n,stdin))s[strcspn(s,"\n")]=0;else s[0]=0;}
static inline int letter(char c){unsigned char x=(unsigned char)c;if(x>='A'&&x<='Z')return x-'A';if(x>='a'&&x<='z')return x-'a';return -1;}
static inline char shifted(char c,int n){int v=letter(c);if(v<0)return c;return (char)((c>='a'&&c<='z'?'a':'A')+modn(v+n,26));}
static inline long long powmod(long long a,long long e,long long n){long long r=1;a%=n;while(e>0){if(e&1)r=r*a%n;a=a*a%n;e>>=1;}return r;}
#endif
