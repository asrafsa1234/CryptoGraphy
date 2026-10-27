#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){puts("Q36 Affine cipher bijection restrictions\nC=(aP+b) mod 26; b can be ANY integer (normalized mod 26).");printf("Allowed a residues: ");for(int a=0;a<26;a++)if(gcd_int(a,26)==1)printf("%d ",a);
 printf("\nInvalid example a=2,b=3: E(A=0)=%d, E(N=13)=%d => collision.\n",3,modn(2*13+3,26));return 0;
}
