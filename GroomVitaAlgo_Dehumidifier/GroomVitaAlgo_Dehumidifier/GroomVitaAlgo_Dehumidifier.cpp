#include <iostream>
#include<queue>
using namespace std;
struct POSI
{
	int r, c;
};
int main() {
	int n;
	cin >> n;
	int** map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
	}
	queue<POSI>q;
	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]==0) {
				POSI tmp;
				tmp.r = i; tmp.c = j;
				q.push(tmp);
			}
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int nsize = q.size();

		for (int i = 0; i < nsize; i++) {
			POSI now = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				POSI next;
				next.r = now.r + dr[i];
				next.c = now.c + dc[i];
				if (next.r < 0 || next.r >= n || next.c < 0 || next.c >= n) continue;
				if (map[next.r][next.c] == 1) {
					map[next.r][next.c] = 0;
					q.push(next);
				}
			}
		}
		cnt++;
	}
	printf("%d", cnt-1);
	return 0;
}