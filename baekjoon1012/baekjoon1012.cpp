#include<stdio.h>
#include<vector>
using namespace std;
struct POSI {
	int x, y;
};
int map[50][50],M,N,K;
vector<POSI> plant;
void dfs(int cnt, int x, int y) {
	if (x < 0 || y < 0 || x >= M || y >= N) return;
	if (map[y][x] == 1) {
		map[y][x] = 2;
		dfs(cnt, x - 1, y);
		dfs(cnt, x + 1, y);
		dfs(cnt, x, y - 1);
		dfs(cnt, x, y + 1);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	POSI temp;
	for(int a=0;a<T;a++){
		int tot=0;
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d%d", &temp.x, &temp.y);
			map[temp.y][temp.x] = 1;
			plant.push_back(temp);
		}//enter baechoo
		for (int i = 0; i < K; i++) {
			if (map[plant[i].y][plant[i].x] == 1) {
				tot++;
				dfs(i, plant[i].x, plant[i].y);
			}
		}
		printf("\n%d\n", tot);
		plant.clear();
	}//end T case

	return 0;
}//end main
