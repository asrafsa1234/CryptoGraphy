#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"
#include <openssl/evp.h>
#include <openssl/provider.h>
static void dump(const char *title,const unsigned char *v,int n){printf("%s",title);for(int i=0;i<n;i++)printf("%02X",v[i]);putchar('\n');}
int main(void){OSSL_PROVIDER *legacy=OSSL_PROVIDER_load(NULL,"legacy"),*base=OSSL_PROVIDER_load(NULL,"default");const EVP_CIPHER *alg=EVP_des_ecb();unsigned char key[8]={0x13,0x34,0x57,0x79,0x9B,0xBC,0xDF,0xF1},pt[8]={0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},ct[32],recovered[32];
 EVP_CIPHER_CTX *ctx=EVP_CIPHER_CTX_new();int a=0,b=0;if(!legacy||!base||!ctx){puts("OpenSSL DES provider unavailable");return 1;}
 if(!EVP_EncryptInit_ex(ctx,alg,NULL,key,NULL)||!EVP_CIPHER_CTX_set_padding(ctx,0)||!EVP_EncryptUpdate(ctx,ct,&a,pt,8)||!EVP_EncryptFinal_ex(ctx,ct+a,&b))return 1;
 EVP_CIPHER_CTX_free(ctx);
 ctx=EVP_CIPHER_CTX_new();int n=0,m=0;if(!EVP_DecryptInit_ex(ctx,alg,NULL,key,NULL)||!EVP_CIPHER_CTX_set_padding(ctx,0)||!EVP_DecryptUpdate(ctx,recovered,&n,ct,a+b)||!EVP_DecryptFinal_ex(ctx,recovered+n,&m))return 1;
 EVP_CIPHER_CTX_free(ctx);
 puts("Q33 DES single-block known answer test");dump("Plaintext: ",pt,8);dump("Ciphertext: ",ct,8);dump("Decrypted: ",recovered,8);puts("Expected ciphertext: 85E813540F0AB405 (FIPS reference). DES is obsolete and insecure.");OSSL_PROVIDER_unload(legacy);OSSL_PROVIDER_unload(base);return (a+b)!=8||memcmp(ct,"\x85\xE8\x13\x54\x0F\x0A\xB4\x05",8)!=0||memcmp(pt,recovered,8)!=0;
}
