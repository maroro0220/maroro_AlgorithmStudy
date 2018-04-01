#include<stdio.h>
//#include<math.h>
int cnt;
int z(int n, int r, int c){
  if(n<1)
    return cnt;
  if(n/2>r && n/2>c)
  {//1���и�
    z(n/2,r,c);
  }
  else if(n/2>r && c>=n/2)//2���и�
  {
    cnt+=(n/2)*(n/2);//pow(n/2,2);
    z(n/2,r,c-n/2);
  }
  else if(n/2<=r && n/2>c)//3
  {
    cnt+=2*(n/2)*(n/2);//n/2<<2;//pow(n/2,2);
    z(n/2,r-n/2,c);
  }
  else if(n/2<=r && c>=n/2)
  {
      cnt+=3*(n/2)*(n/2);//n/2<<2;//pow(n/2,2);
      z(n/2,r-n/2,c-n/2);
  }
  //z(n/2,r,c);
}
int main(){
  int n,N,r,c;
  while(scanf("%d %d %d",&n,&r,&c)!=EOF){

    if(n<0 || n>15 || r<0 || c<0 || (r>((1<<n)-1)) || (c>(1<<n)-1)){
      printf("s\n");
      continue;
    }
  cnt=0;
  N=1<<n;//pow(2,n);
  //int a[N][N]={0,};
  printf("%d\n",z(N,r,c));

  }
  return 0;
}
