/*
 * baekjoon2606.c
 *신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다.
 *신종 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자.
1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어
2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다.
하지만 4번과 7번 컴퓨터는1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.
어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때,
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.
 *  Created on: 2018. 4. 11.
 *      Author: maroro
 */
#include<stdio.h>
#include<stdlib.h>
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
int main(){
	int** arr;
	int sum=0,n,cn,a,b;
	scanf("%d",&n);
	scanf("%d",&cn);
	arr=(int**)calloc(n+1,sizeof(int*));
	for(int i=0;i<n+1;i++){
		arr[i]=(int*)calloc(n+1,sizeof(int*));
	}
//	printf("n%d  cn%d",n,cn);
	for(int i=0;i<cn;i++){
//		printf("%d",i);
		scanf("%d %d",&a, &b);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j&&arr[i][k] &&arr[k][j]){
					arr[i][j]=1;}
//				printf("arr[%d][%d]=%d\n",i,j,arr[i][j]);

			}
	for(int i=1;i<=n;i++)
		sum+=arr[1][i];
	printf("%d",sum);
	return 0;
}
