
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
struct POSI
{
	int x, y;
};

POSI comp, home;
vector<POSI> cust;
vector<int>chk;
int N,ans;
void dfs(int cnt,int x,int y,int dist) {
	if (dist > ans)return;
	if (cnt == N) {
		ans = ans > dist + abs(x - home.x) + abs(y - home.y) ? dist + abs(x - home.x) + abs(y - home.y) : ans;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (chk[i] == 1) continue;
		chk[i] = 1;
		int dist_tmp = dist + abs(x - cust[i].x) + abs(y - cust[i].y);
		dfs(cnt+ 1, cust[i].x, cust[i].y, dist_tmp);
		chk[i] = 0;

	}

}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 10000;
		scanf("%d", &N);
		scanf("%d %d", &comp.x, &comp.y);
		scanf("%d %d", &home.x, &home.y);
		cust = vector<POSI>(N);
		chk = vector<int>(N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &cust[i].x, &cust[i].y);
		}
		dfs(0, comp.x, comp.y, 0);
		printf("#%d %d\n", test_case, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}