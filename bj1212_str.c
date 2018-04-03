/*
 * bj1212.c
 *
 *  Created on: 2018. 4. 3.
 *      Author: maroro
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 333335
int main(){
	int a;
	char oct[MAX];
	printf("enter:");
	fflush(stdout);
	scanf("%s",oct);
	int *arr;
	arr=(int*)malloc(sizeof(int)*strlen(oct)*3);
	int tcnt,len;
	len=strlen(oct);
	tcnt=len*3;
	for(int i=1;i<=strlen(oct);i++){
		a=oct[--len]-'0';
		for(int j=i;j<i+3;j++){
			arr[--tcnt]=a%2;
			a=a/2;
		}
	}
	int chk=0;
	if(strlen(oct)==1 && oct[0]=='0'){
		printf("0");
	}
	else if(strlen(oct)==1 && oct[0]=='1')
		printf("1");
	else{
	for(int i=0; i<strlen(oct)*3; i++){
		if(chk==0 && arr[i]==0)
			continue;
		else{
			chk=1;
		printf("%d",arr[i]);
		}
	}
	}
}
