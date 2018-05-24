/*
 * BaekJoon2309.c
 *
 *  Created on: 2018. 5. 24.
 *      Author: maroro
 *
�պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�. �ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.
��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. �پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.
��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
��ȩ ���� �ٿ� ���� �ϰ� �������� Ű�� �־�����. �־����� Ű�� 100�� ���� �ʴ� �ڿ����̸�, ��ȩ �������� Ű�� ��� �ٸ���, ������ ������ ���������� ��쿡�� �ƹ��ų� ����Ѵ�.
���
�ϰ� �������� Ű�� ������������ ����Ѵ�.

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
