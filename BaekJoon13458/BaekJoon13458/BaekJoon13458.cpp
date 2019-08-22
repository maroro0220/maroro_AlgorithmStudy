#include<stdio.h>
#include<vector>
#define MIN(X,Y) (((X)<(Y))?(X):(Y))
using namespace std;

int N,B,C;
int min1 = 99999999;
vector<int> A;
long long Cal() {
	long long cnt=0;
	vector<int> A_tmp(A);

	for (int i = 0;i<N; i++) {
		//if (cnt > min1) return cnt;
		A_tmp[i] -= B;
		cnt++;
		if(A_tmp[i]>0){
			if ((A_tmp[i] /C) == 0) {
				cnt += (A_tmp[i] / C);
			}
			else {
				cnt += (A_tmp[i] / C) + 1; 
			}
		}
		/*
		while(A_tmp[i]>0){
			A_tmp[i] -= C;
			cnt++;
		}
		*/
		//min1 = MIN(cnt, min1);
	}//end for
	return cnt;
}
int main() {
	int temp;
	//vector<int> A_tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		A.push_back(temp);
	}
	scanf("%d%d", &B, &C);
	long long ret=0;
	//for (int i = 0; i < N; i++) {
		ret = Cal();
	//}
	printf("%lli",ret);
	return 0;
}