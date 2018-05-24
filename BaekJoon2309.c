/*
 * BaekJoon2309.c
 *
 *  Created on: 2018. 5. 24.
 *      Author: maroro
 *
왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.
아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

입력
아홉 개의 줄에 걸쳐 일곱 난쟁이의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러가지인 경우에는 아무거나 출력한다.
출력
일곱 난쟁이의 키를 오름차순으로 출력한다.

20
7
23
19
10
15
25
8
13
 */


#include<stdio.h>
#include<stdlib.h>
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
int arr[9],arrtmp[7],arrres[7];
void Sort(){
	int tmp,index;
	for(int i=0;i<7;i++){
		index=i;
		for(int j=i+1;j<7;j++){
			if(arrres[index]>arrres[j]){
				index=j;
			}
		}
		tmp=arrres[index];
		arrres[index]=arrres[i];
		arrres[i]=tmp;
	}
}
void Seven(int s,int n){
	if(s>9){
		return;
	}
	//printf("%d",s);
	if(n==7 && s==9){
		int sum=0;
		for(int i=0;i<7;i++){
			sum+=arrtmp[i];
//			printf("%d ",arrtmp[i]);
		}
//		printf("\n");
		if(sum==100){
			for(int i=0;i<7;i++){
				arrres[i]=arrtmp[i];
			}
//			printf("\nsum=%d\n",sum);
			return;
		}
		return;
	}
	if(n<7){
		arrtmp[n]=arr[s];
		Seven(s+1,n+1);
	}
	Seven(s+1,n);
}
int main(){
	for(int i=0;i<9;i++){
		scanf("%d",&arr[i]);
	}
	Seven(0,0);
	Sort();
	printf("\n");
	for(int i=0;i<7;i++){
		printf("%d\n",arrres[i]);
	}
	return 0;
}
