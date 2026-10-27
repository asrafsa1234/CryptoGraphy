#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lab_common.h"

int main(void){unsigned long long state[5][5]={0};for(int i=0;i<16;i++)state[i%5][i/5]=1ULL;puts("Q29 SHA-3 lane diffusion model (theta only, no permutations)");
 for(int step=0;step<=8;step++){int full=1,n=0;for(int y=0;y<5;y++)for(int x=0;x<5;x++){if(state[x][y])n++;else full=0;}printf("After %d theta applications: %d/25 nonzero lanes\n",step,n);if(full)break;
 unsigned long long c[5]={0},d[5]={0};for(int x=0;x<5;x++)for(int y=0;y<5;y++)c[x]^=state[x][y];for(int x=0;x<5;x++)d[x]=c[(x+4)%5]^((c[(x+1)%5]<<1)|(c[(x+1)%5]>>63));for(int x=0;x<5;x++)for(int y=0;y<5;y++)state[x][y]^=d[x];}
 puts("Illustrative lane initialization, not a guarantee for every permitted nonzero bit configuration.");return 0;
}
