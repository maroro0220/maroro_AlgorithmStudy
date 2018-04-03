/*
 * bj1212.c
 *
 *  Created on: 2018. 4. 3.
 *      Author: maroro
 */


#include<stdio.h>
#include<stdlib.h>
int main(){
	int o,temp;
	int a,cnt=0;
	scanf("%o",&o);
	temp=o;
	while(temp>0 && cnt<=333334){
		cnt++;
		temp=temp/8;
	}
	int *arr;
	arr=(int*)malloc(sizeof(int)*cnt*3);
	int tcnt;
	tcnt=cnt*3;
	for(int i=1;o>0;i++){
		a=o%8;
		for(int j=i;j<i+3;j++){
			arr[--tcnt]=a%2;
			a=a/2;
		}
		o=o/8;
	}
	int chk=0;
	if(cnt==0){
		printf("%d",0);
	}
	else
	for(int i=tcnt;i<cnt*3;i++){
		if(chk==0 && arr[i]==0)
			continue;
		else{
			chk=1;
		printf("%d",arr[i]);
		}

	}
}
