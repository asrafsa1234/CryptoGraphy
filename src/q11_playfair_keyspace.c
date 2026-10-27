#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){double lg=0;for(int i=2;i<=25;i++){double x=i;while(x>1.000001){lg+=0.0;break;}}
 /* log2(25!) by multiplying into 64-bit-safe long double */
 long double f=1;for(int i=2;i<=25;i++)f*=i;
 long double distinct=f/25.0L;unsigned long long power=1;for(int i=0;i<25;i++)power*=1; (void)power;(void)lg;
 printf("Q11 Playfair keyspace\n25! labeled matrices = %.0Lf (about 2^83.68)\n",f);
 printf("Accounting for 5 row and 5 column cyclic shifts: 25!/25 = %.0Lf (about 2^79.04)\n",distinct);
 puts("This uses the standard row/column circular-shift equivalence.");return 0;
}
