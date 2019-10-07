#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,start;
int sum;
vector<vector<int>>city;
vector<int>chk; 
int MinRoot = 10000000;

void dfs(int r,int c,int cnt){
	

	if(N==cnt && r==start){
			//int ret = sum;
			MinRoot = min(MinRoot, sum);
			return ;
		
	}
	for (int i = 0; i < N; i++) {
			if (chk[r]==0 &&city[r][i]>0) {
				chk[r] = 1;
				sum += city[r][i];
				dfs(i, 0, cnt + 1);
				chk[r] = 0;
				sum -= city[r][i];
			}
		}
}

int main() {
	cin >> N;
	city = vector<vector<int>>(N, vector<int>(N));
	chk = vector<int>(N,0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
		}
	}//end for enter map

	int res;
	for (int i = 0; i < N; i++) {
		if (chk[i] == 0) {
			start = i;
			//chk[i] = 1;
			dfs(i, 0, 0);
			//chk[i] = 0;
		}
	}
	cout << MinRoot;
	return 0;
}