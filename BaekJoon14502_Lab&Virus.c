/*
 * BaekJoon14502_Lab&Virus.c
 *
 *  Created on: 2018. 5. 29.
 *      Author: maroro
 */
/*
��ü�� ġ������ ���̷����� �����ϴ� �����ҿ��� ���̷����� ����Ǿ���. ������ ���̷����� ���� ������ �ʾҰ�, ���̷����� Ȯ���� ���� ���ؼ� �����ҿ� ���� ������� �Ѵ�.
�����Ҵ� ũ�Ⱑ N��M�� ���簢������ ��Ÿ�� �� ������, ���簢���� 1��1 ũ���� ���簢������ �������� �ִ�. �����Ҵ� �� ĭ, ������ �̷���� ������, ���� ĭ �ϳ��� ���� �����Ѵ�.
�Ϻ� ĭ�� ���̷����� �����ϸ�, �� ���̷����� �����¿�� ������ �� ĭ���� ��� �������� �� �ִ�. ���� ���� �� �ִ� ���� ������ 3���̸�, �� 3���� ������ �Ѵ�.

�Է�
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (3 �� N, M �� 8)
��° �ٺ��� N���� �ٿ� ������ ����� �־�����. 0�� �� ĭ, 1�� ��, 2�� ���̷����� �ִ� ��ġ�̴�. 2�� ������ 2���� ũ�ų� ����, 10���� �۰ų� ���� �ڿ����̴�.
�� ĭ�� ������ 3�� �̻��̴�

���
ù° �ٿ� ���� �� �ִ� ���� ������ �ִ� ũ�⸦ ����Ѵ�.
*/
#include<stdio.h>
#include<stdlib.h>
//int lab[8][8];
#define WALL 3
struct Point{
	int x;
	int y;
};
struct Point vir[10];
struct Point wall[59];
struct Point walltmp[3];
struct Point space[62];
int w, v, s, max;
int **lab;
int **test;
int N,M;

void Move(int X,int Y){
	if((X<0) || (X>=M) || (Y<0) || (Y>=N) || test[Y][X]==1 ||test[Y][X]==3){
		return ;
	}
//	else if(X==M && Y==N){
//		return 1;
//	}
	else{
//		printf("test[%d][%d]=%d \n",Y,X,test[Y][X]);
//		for(int i=0;i<N;i++){
//			for(int j=0;j<M;j++){
//				printf("%d ",test[i][j]);
//			}
//			printf("\n");
//		}

		if(test[Y][X]==0 || test[Y][X]==2){
			test[Y][X]=3;
		}
		else if(test[Y][X]==3){
			return ;
		}
			Move(X+1,Y);
			Move(X,Y+1);
			Move(X-1,Y);
			Move(X,Y-1);
			return ;
	}

}

void Reset(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			test[i][j]=lab[i][j];
		}
	}
}
int Calc(){
	int tmp=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(test[i][j]==0){
				tmp++;
			}
		}
	}
	if(tmp>max){
		max=tmp;
	}
	return 0;
}

void Wall(int cnts, int three){
	if(cnts>s){
		return ;
	}
	else if(cnts==s && three==WALL){
		for(int i=0;i<three;i++){
			test[walltmp[i].y][walltmp[i].x]=1;
		}
		for(int a=0;a<v;a++){
			Move(vir[a].x,vir[a].y);
		}
		Calc();
		Reset();
	}
	if(three<WALL){
		walltmp[three].x=space[cnts].x;
		walltmp[three].y=space[cnts].y;
		Wall(cnts+1,three+1);
	}
	Wall(cnts+1,three);
}


int main(){
	scanf("%d %d",&N, &M);
	fflush(stdout);
	lab=(int**)calloc(N,sizeof(int*));
	test=(int**)calloc(N,sizeof(int*));
	for(int i=0;i<N;i++){
		lab[i]=(int*)calloc(M,sizeof(int));
		test[i]=(int*)calloc(M,sizeof(int));
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
//			printf("%d ",lab[i][j]);
			scanf("%d",&lab[i][j]);
			if(lab[i][j]==1){
				wall[w].x=j;
				wall[w].y=i;
			}
			else if (lab[i][j]==2){
				vir[v].x=j;
				vir[v].y=i;
				v++;
			}
			else if (lab[i][j]==0){
				space[s].x=j;
				space[s].y=i;
				s++;
			}
		}
//		printf("\n");
	}
//	w--;v--;s--;
	Reset();
	Wall(0,0);
	for(int a=0;a<v;a++){
		Move(vir[a].x,vir[a].y);
	}
//	for(int i=0;i<N;i++){
//		for(int j=0;j<M;j++){
//			printf("%d ",test[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d",max);
	// memory free
	for(int i=0;i<N;i++){
		free(lab[i]);
		free(test[i]);
	}
	free(lab);
	free(test);
	return 0;
}
