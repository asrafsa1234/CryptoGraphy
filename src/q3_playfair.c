#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 8192
static char matrix[5][5];static int row[26],col[26];
static int normalize(char c){unsigned char x=(unsigned char)c;if(x>='a'&&x<='z')x=(unsigned char)(x-32);if(x<'A'||x>'Z')return -1;return x=='J'?'I':x;}
int main(void){
 char key[MAX],text[MAX],plain[MAX],prepared[MAX*2],cipher[MAX*2];int used[26]={0},cnt=0,n=0,m=0;
 printf("Keyword: ");if(!fgets(key,sizeof key,stdin))return 1;
 printf("Plaintext: ");if(!fgets(text,sizeof text,stdin))return 1;
 for(int pass=0;pass<2;pass++){
  const char *s=pass==0?key:"ABCDEFGHIKLMNOPQRSTUVWXYZ";
  for(size_t i=0;s[i];i++){int v=normalize(s[i]);if(v<0)continue;if(!used[v-'A']){used[v-'A']=1;matrix[cnt/5][cnt%5]=(char)v;row[v-'A']=cnt/5;col[v-'A']=cnt%5;cnt++;}}
 }
 for(size_t i=0;text[i];i++){int v=normalize(text[i]);if(v>=0)plain[n++]=(char)v;}
 for(int i=0;i<n;){char a=plain[i++],b;
  if(i==n||plain[i]==a){b=a=='X'?'Q':'X';}else b=plain[i++];
  prepared[m++]=a;prepared[m++]=b;
 }
 prepared[m]=0;
 for(int i=0;i<m;i+=2){int a=prepared[i]-'A',b=prepared[i+1]-'A';int ra=row[a],rb=row[b],ca=col[a],cb=col[b];
  if(ra==rb){cipher[i]=matrix[ra][(ca+1)%5];cipher[i+1]=matrix[rb][(cb+1)%5];}
  else if(ca==cb){cipher[i]=matrix[(ra+1)%5][ca];cipher[i+1]=matrix[(rb+1)%5][cb];}
  else{cipher[i]=matrix[ra][cb];cipher[i+1]=matrix[rb][ca];}
 }
 cipher[m]=0;puts("Matrix:");for(int i=0;i<5;i++){for(int j=0;j<5;j++)printf("%c%c",matrix[i][j],j==4?'\n':' ');}
 printf("Prepared: %s\nCiphertext: %s\n",prepared,cipher);return 0;
}
