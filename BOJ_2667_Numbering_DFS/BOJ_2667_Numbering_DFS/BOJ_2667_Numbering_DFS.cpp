#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

vector<vector<int>> map;
vector<int> chk;
int N, cnt;
void dfs(int r,int c) {
	
	if (c < 0 || r < 0 || c >= N || r >= N) {
		return;
	}
	if (map[r][c] == 1) {
		map[r][c] = cnt;
		chk[cnt]++;
		dfs(r, c + 1); //right
		dfs(r+1, c ); //down
		dfs(r, c - 1); //left
		dfs(r-1, c ); //up
		
	}
}

int main() {
		cin >> N;
	map = vector<vector<int>>(N, (vector<int>(N, 0)));
	chk = vector<int >(N * N,0);
	cnt = 2;
	long long tmp;
	//enter map
	for (int i = 0; i < N; i++) {
		//cin >> tmp;
		for (int j = 0; j <N; j++) {
			//map[i][j]=(int)(tmp%10);
			scanf("%1d", &map[i][j]);
			//tmp /=10;
		}//end for j
	}//end for i
	//cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << map[i][j];
			if (map[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
		//printf("\n");
	}

	cout << cnt - 2 << endl;
	sort(chk.begin(), chk.end());
	for (int i = 0; i < N*N; i++) {
		if (chk[i]) {
			//cout <<"cnt: "<<cnt<<"chk"<< chk[i] << endl;
			cout << chk[i] << endl;
		}
	}

	return 0;
}