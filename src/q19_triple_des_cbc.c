#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"
#include <openssl/evp.h>
#include <openssl/provider.h>
static void dump(const char *title,const unsigned char *v,int n){printf("%s",title);for(int i=0;i<n;i++)printf("%02X",v[i]);putchar('\n');}
static int crypt(const EVP_CIPHER *alg,int enc,const unsigned char *key,const unsigned char *iv,const unsigned char *src,int n,unsigned char *dst){EVP_CIPHER_CTX *ctx=EVP_CIPHER_CTX_new();int a=0,b=0;if(!ctx)return -1;
 int ok=EVP_CipherInit_ex(ctx,alg,NULL,key,iv,enc)&&EVP_CipherUpdate(ctx,dst,&a,src,n)&&EVP_CipherFinal_ex(ctx,dst+a,&b);EVP_CIPHER_CTX_free(ctx);return ok?a+b:-1;}

int main(void){OSSL_PROVIDER *legacy=OSSL_PROVIDER_load(NULL,"legacy"),*base=OSSL_PROVIDER_load(NULL,"default");const EVP_CIPHER *alg=EVP_des_ede3_cbc();unsigned char key[24]="0123456789ABCDEF01234567",iv[8]="12345678",src[]="CBC demonstration (3DES)",ct[128],pt[128];
 int n=crypt(alg,1,key,iv,src,(int)strlen((char*)src),ct),m=n<0?-1:crypt(alg,0,key,iv,ct,n,pt);if(m<0){puts("3DES-CBC unavailable");return 1;}pt[m]=0;
 puts("Q19 3DES-CBC encryption/decryption");dump("Ciphertext hex: ",ct,n);printf("Recovered: %s\nSecurity choice: random IV, authentication required (prefer AES-GCM in practice).\nPerformance: independent encryption is parallelizable in ECB; CBC encryption is sequential.\n",pt);OSSL_PROVIDER_unload(legacy);OSSL_PROVIDER_unload(base);return strcmp((char*)pt,(char*)src)!=0;
}
