#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){int n=3599,known_plaintext=59,f=gcd_int(n,known_plaintext);printf("Q25 RSA plaintext shares nontrivial factor with modulus\nn=%d, known plaintext block=%d\ngcd=%d\n",n,known_plaintext,f);
 if(f>1&&f<n)printf("FACTOR LEAK: p=%d q=%d, modulus factored.\n",f,n/f);else puts("No factor recovered.");puts("Knowing only that a block has a factor is insufficient without the block or another exploitable relation.");return 0;
}
