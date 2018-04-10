/*
 * arr_minmax_num.c
 *
 *  Created on: 2018. 3. 30.
 *      Author: maroro
 */


//#define N 256
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN(a,b) (((a)<=(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
int main(){
	int *a, *b;
	int n, max=0;
	printf("enter!");
	fflush(stdout);
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
			printf("%d",a[i]);
		}
	for(int i=0; i<n; i++){
		printf("h1\n");
			max=MAX(a[i],max);
		}
	printf("max %d \n",max);
	b=(int *)malloc(sizeof(int)*max+1);
	memset(b, 0, sizeof(int)*max +1 );

	for(int i=0;i<n;i++){
		printf("h2\n");
		if(a[i]>0){
			b[a[i]]++;
			printf("a[i}%d: %d",a[i],b[a[i]]);
		}
		else{
			continue;
		}
	}
	for(int i=1;i<=max;i++){
		printf("h3\n");
		if(b[i]==0){
			printf("1:%d",i);
			break;
		}
		else if(i==max)
			printf("2:%d",i++);
//		if(b[i]>0 && b[i+1]>0){
//			continue;
//		}
//		else if(b[i]>0 && b[i+1]==0){
//			printf("%d",i+1);
//		}
	}
return 0;
}
