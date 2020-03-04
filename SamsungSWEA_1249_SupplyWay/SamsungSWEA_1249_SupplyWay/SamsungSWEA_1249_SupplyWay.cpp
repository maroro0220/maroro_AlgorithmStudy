
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x7FFFFFFF
using namespace std;
vector<vector<int>> map;
vector<vector<int>> chk_map;
int N;
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;//val,r,c
/*
struct a {
	int value;
	int r;
	int c;
};
struct cmp {
	bool operator()(a t, a u) {
		return t.value < u.value;
	}

};
//priority_queue<a, vector<a>, cmp> pq;
*/

/* 
Time Over
void dfs(int r, int c,int cnt) {
	if (r == N - 1 && c == N - 1) {
		mini = min(mini, cnt);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int next_x, next_y;
		next_x = c + dx[d];
		next_y = r + dy[d];
		if (next_x>=0&&next_x<N&&next_y>=0&&next_y<N&&!chk_map[next_y][next_x]) {
			cnt += map[next_y][next_x];
			chk_map[next_y][next_x] = 1;
			dfs(next_y, next_x,cnt);
			chk_map[next_y][next_x] = 0;			
			cnt -= map[next_y][next_x];
		}
	}
}
*/
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		map = vector<vector<int>>(N, vector<int>(N));
		chk_map = vector<vector<int>>(N, vector<int>(N, INF));
		chk_map[0][0] = 0;
		for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < N; j++) {
				map[i][j] = tmp[j] - '0';
			}
		}
		pq.push({ map[0][0],{0,0} });
		//pq.push(make_pair(0, make_pair(0, 0)));
		/*
		a tmp;
		tmp.value = map[0][0];
		tmp.r = 0;
		tmp.c = 0;
		pq.push(tmp);
		*/
		chk_map[0][0] = 0;
		while (!pq.empty()) {
			//int v = pq.top().value;//pq.top().first;
			//int now_r = pq.top().r;//pq.top().second.first;
			//int now_c = pq.top().c;//pq.top().second.second;
			int v = pq.top().first;
			int now_r = pq.top().second.first;
			int now_c = pq.top().second.second;
			pq.pop();						
			if (now_r == N - 1 && now_c == N - 1) break;
			for (int d = 0; d <4; d++) {
				int next_c = now_c+dx[d];
				int next_r = now_r+dy[d];
				if (next_c >= 0 && next_c < N && next_r >= 0 && next_r < N) {
					if (chk_map[next_r][next_c]>v+map[next_r][next_c]) {
						chk_map[next_r][next_c] = v + map[next_r][next_c];
						pq.push(make_pair(chk_map[next_r][next_c], make_pair(next_r, next_c)));
						//pq.push({ chk_map[next_r][next_c], {next_r,next_c} });
						//tmp.value = chk_map[next_r][next_c];
						//tmp.r = next_r;
						//tmp.c = next_c;
						//pq.push(tmp);
					}
				}
			}
		}
		//dfs(0, 0,0);
		cout << '#' << test_case << ' ' << chk_map[N-1][N-1]<<endl;
		//pq = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>();

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


/*
//다른 사람 것 other people's code
#include <iostream>
#include <string>
#include <memory.h>
#include <queue>
#include <utility>
using namespace std;
int a[101][101]={0,};
int mem[101][101]= {0}; // 개선을 위한 배열
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> pq;

int main(){
	int numTestCase;
	scanf("%d", &numTestCase);
	for(int tc=0; tc<numTestCase; tc++){
		memset(a,0,sizeof(a));
		memset(mem,0,sizeof(mem));
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			string str;
			cin>>str;
			for(int j=0; j<n; j++){
				int num = stoi(str.substr(j,1));
				a[i][j]=num;
				mem[i][j] = 100*100*9+1; // 사용 범위 초기화
			}
		}

		pq.push(make_pair(0, make_pair(0,0)));
		mem[0][0] = 0 ;

		int result_time, x, y;
		while(!pq.empty()){
			pair<int,pair<int,int>> poped = pq.top();
			pq.pop();
			result_time = poped.first * -1;
			x = poped.second.first;
			y = poped.second.second;
			if(x==n-1 && y==n-1) break;
			for(int d=0; d<4; d++){
				int nx = direction[d][0]+x;
				int ny = direction[d][1]+y;
				if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
				int n_val = a[nx][ny]+result_time;
				if(n_val < mem[nx][ny]) { // 값이 작아지면
					mem[nx][ny] = n_val; // 업데이트
					pq.push(make_pair(n_val * -1, make_pair(nx,ny))); // 추가
				}
			}
		}
		cout<<"#"<<tc+1<<" "<<result_time<<endl;
		pq = priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>>();
	}
	return 0;
}
*/