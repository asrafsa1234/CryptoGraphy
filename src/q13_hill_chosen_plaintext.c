#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){int key[2][2]={{9,4},{5,7}};puts("Q13 Chosen-plaintext attack on Hill 2x2 cipher");
 puts("Choose BA (vector [1,0]) and AB (vector [0,1]).");
 for(int t=0;t<2;t++){int x=t==0,y=t==1;printf("%s -> %c%c (column %d of secret key)\n",t==0?"BA":"AB",'A'+modn(key[0][0]*x+key[0][1]*y,26),'A'+modn(key[1][0]*x+key[1][1]*y,26),t+1);}
 printf("Recovered key: [[%d,%d],[%d,%d]]\n",key[0][0],key[0][1],key[1][0],key[1][1]);return 0;
}
