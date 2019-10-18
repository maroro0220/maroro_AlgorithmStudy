#include<iostream>
#include<vector>

using namespace std;

int dr[4] = {-2,-1,1,2};
int dc[4] = {1,2,2,1};
int chk[4];
vector<vector<int>> map;
int main() {
	int N, M;
	cin >> N >> M;//start=map[N-1][0];
	map = vector<vector<int>>(N, vector<int>(M, 0));
	return 0;
}