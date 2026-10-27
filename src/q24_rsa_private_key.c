#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){int n=3599,e=31,p=0,q=0;for(int x=2;x*x<=n;x++)if(n%x==0){p=x;q=n/x;break;}if(!p)return 1;
 int phi=(p-1)*(q-1),d=invmod(e,phi);printf("Q24 RSA private key\nn=%d = %d * %d\nphi(n)=%d\nPublic e=%d\nPrivate d=%d\n",n,p,q,phi,e,d);if(d<0)return 1;
 long long m=42,c=powmod(m,e,n),v=powmod(c,d,n);printf("Test %lld -> %lld -> %lld\n",m,c,v);return m!=v;
}
