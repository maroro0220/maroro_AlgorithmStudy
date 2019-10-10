#include<iostream>
#include<vector>

using namespace std;

int w, h;
int map[50][50];
vector<vector<int>> chk;
void dfs(int r,int c) {
	if (r<0||r>=h||c<0||c>=w) 
		return;
	if (map[r][c] == 0 || chk[r][c] == 1) {
		return;
	}
	else if (chk[r][c] == 0 && map[r][c] == 1) {
		chk[r][c] = 1;
		dfs(r - 1, c - 1); //11
		dfs(r - 1, c); //12
		dfs(r - 1, c + 1); //1
		dfs(r, c + 1);//3
		dfs(r + 1, c + 1);//5
		dfs(r + 1, c);//6
		dfs(r + 1, c - 1);//7
		dfs(r, c - 1);//9
		//chk[r][c] = 0;
	}
}
int main() {
	while (1) {
	int cnt = 0;
		cin >> w >> h;
		if (!w && !h) break;
		chk = vector<vector<int>>(h, vector<int>(w, 0));
		for (int a = 0; a < h; a++) {
			for (int b = 0; b < w; b++) {
				cin >> map[a][b]; //1=land, 0=sea
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!chk[i][j] && map[i][j]==1) {
					dfs(i, j);
					cnt++;
				}
			}
		}//end for i
		cout<<cnt<<endl;
	}
	return 0;
}