/*

#include<stdio.h>
#include<vector>
#define MIN(X,Y) (((X)>(Y))?(Y):(X)) 
using namespace std;
struct Pos {
	int r, c;//row,col
};
//vector<int> map;
int N, M, min=9999;
int visit[10][10][10][10] = {0,};
char **map;
vector<Pos> wall;// , Red, Blue;
Pos hole,Red,Blue;
int dr[4] = { -1,1,0,0 }; //top, down, left, right
int dc[4] = { 0,0,-1,1 }; //top, down, left, right
int Play(Pos R_tmp, Pos B_tmp, int cnt, int d){
	if (cnt > 10) return -1;
	if(R_tmp.r > -1 && R_tmp.r < N && B_tmp.r>-1 && B_tmp.r < N && R_tmp.c > -1 && R_tmp.c < M && B_tmp.c>-1 && B_tmp.c < M){
		while (1) {
			if (R_tmp.r == hole.r && R_tmp.c == hole.c) {
				return cnt+1;
			}
			if (map[R_tmp.r][R_tmp.c] == '#') break;
			R_tmp.r += dr[d];
			R_tmp.c += dc[d];
			if (R_tmp.r < 0 || R_tmp.r > N - 1|| R_tmp.c < 0 || R_tmp.c > M - 1) {
				R_tmp.r -= dr[d];
				R_tmp.c -= dc[d];
				break; 
			}
		}//Red move
		while (1) {
			if (B_tmp.r == hole.r && B_tmp.c == hole.c)  break;
			
			if (map[B_tmp.r][B_tmp.c] == '#') break;
			B_tmp.r += dr[d];
			B_tmp.c += dc[d];
			if (B_tmp.r < 0 || B_tmp.r > N - 1 || B_tmp.c < 0 || B_tmp.c > M - 1) {
				B_tmp.r -= dr[d];
				B_tmp.c -= dc[d];
				break; 
			}
		}//Blue move
		
	}
		for(int i=0;i<4;i++){
			if(visit[R_tmp.r][R_tmp.c][B_tmp.r][B_tmp.c] ==0){
				map[R_tmp.r][R_tmp.c] = 'R';
				map[B_tmp.r][B_tmp.c] = 'B';
				visit[R_tmp.r][R_tmp.c][B_tmp.r][B_tmp.c] = 1;
				Play(R_tmp, B_tmp, cnt + 1,i);
				map[R_tmp.r][R_tmp.c] = '.';
				map[B_tmp.r][B_tmp.c] = '.';
			}
		//	map[R_tmp.r][R_tmp.c] = '1';
		//	map[B_tmp.r][B_tmp.c] = '2';
		}
		min = MIN(cnt, min);
	return min;
}

int main() {
	Pos tmp;
	scanf("%d%d", &N,&M);
	map = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		map[i] = (char*)malloc(sizeof(char) * M+1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M+1; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '#') {
				//tmp.r = i;
				//tmp.c = j;
				//wall.push_back(tmp);
			}
			else if (map[i][j] == 'R') {
			//	tmp.r = i;
			//	tmp.c = j;
			//	Red.push_back(tmp);
				Red.r = i;
				Red.c = j;
			}
			else if (map[i][j] == 'B') {
			//	tmp.r = i;
			//	tmp.c = j;
			//	Blue.push_back(tmp);
				Blue.r = i;
				Blue.c = j;
			}
			else if (map[i][j] == 'O') {
				hole.r = i;
				hole.c = j;
			}
		}
	}//for N

	printf("%d", Play(Red,Blue,0,0));
	return 0;
}
*/
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;
struct INFO {
	int rr, rc,br,bc,cnt;
};

//int R_r, R_c, B_r, B_c;
int N, M,ret;
char** map;
INFO index;

int bfs() {
	const int dr[4] = { -1,1,0,0 };
	const int dc[4] = { 0,0,-1,1};
	queue<INFO> q;
	int visited[10][10][10][10] = { 0, };
	int ret = -1;
	q.push(index);
	visited[index.rr][index.rc][index.br][index.bc]=1;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		if (cur.cnt > 10)break;
		if (map[cur.rr][cur.rc] == 'O' && map[cur.br][cur.bc] != 'O')
		{
			ret = cur.cnt;
			//break;
			return ret;
		}
		for (int i = 0; i < 4; i++) 
		{
			int n_rr = cur.rr + dr[i];
			int n_rc = cur.rc + dc[i];
			int n_br = cur.br + dr[i];
			int n_bc = cur.bc + dc[i];
			while (1)
			{
				if(map[n_rr][n_rc] != '#' && map[n_rr][n_rc] != 'O'){
					n_rr += dr[i];
					n_rc += dc[i];
				}
				else {
					if (map[n_rr][n_rc] == '#') {
						n_rr -= dr[i];
						n_rc -= dc[i];
					}	
					break;
				}
			}//end while red move
			while (1)
			{
				if(map[n_br][n_bc] != '#' && map[n_br][n_bc] != 'O')
				{
				n_br += dr[i];
				n_bc += dc[i];
				}
				else {
					if (map[n_br][n_bc] == '#')
					{
						n_br -= dr[i];
						n_bc -= dc[i];		
					}	
					break;
				}
			}//end while blue move
			if (n_rr == n_br && n_rc == n_bc) 
			{
				if(map[n_rr][n_rc]!='O'){
					int red_dist = abs(cur.rr - n_rr) + abs(cur.rc - n_rc);
					int blue_dist = abs(cur.br - n_br) + abs(cur.bc - n_bc);
					if (red_dist > blue_dist) 
					{
						n_rr -= dr[i];
						n_rc -= dc[i];
					}
					else if (red_dist < blue_dist)
					{
						n_br -= dr[i];
						n_bc -= dc[i];
					}
				}
			}//end if red and blue is same position
			if (visited[n_rr][n_rc][n_br][n_bc] == 0) 
			{
				visited[n_rr][n_rc][n_br][n_bc] = 1;
				INFO next;
				next.rr = n_rr;
				next.rc = n_rc;
				next.br = n_br;
				next.bc = n_bc;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}
		}//end for dir move
	}//while q empty
	return ret;
}
int main() {

	scanf("%d%d", &N, &M);
	map = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		map[i] = (char*)malloc(sizeof(char) * M + 1); //M+1인 이유는 마지막 공백 문자 입력 돼서
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M + 1; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'R') {
				index.rr = i;
				index.rc = j;
			}
			else if (map[i][j] == 'B') {
				index.br = i;
				index.bc = j;
			}
			/*
			else if (map[i][j] == 'O') {
				hole.r = i;
				hole.c = j;
			}
			*/
		}
	}//for N
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M + 1; j++) {
			printf("%c", map[i][j]);
		}
	}
	*/
	printf("%d", bfs());
	return 0;
}//main
