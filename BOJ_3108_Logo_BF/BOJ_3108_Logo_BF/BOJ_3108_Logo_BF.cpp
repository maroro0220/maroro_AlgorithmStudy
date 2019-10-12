#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Posi
{
	int x1, y1, x2, y2;
};
queue<int> q;
vector<Posi> arr;
vector<int>chk;
int N;
int cnt;
bool overlap(int a, int b) {
	if (((arr[a].x1 <= arr[b].x1 && arr[a].x2 >= arr[b].x1) && (arr[a].y1 <= arr[b].y1 && arr[a].y2 >= arr[b].y1)) != ((arr[a].x1 <= arr[b].x2 && arr[a].x2 >= arr[b].x2) && (arr[a].y1 <= arr[b].y2 && arr[a].y2 >= arr[b].y2)) ||
		(((arr[a].x1 <= arr[b].x2 && arr[a].x2 >= arr[b].x2) && (arr[a].y1 <= arr[b].y1 && arr[a].y2 >= arr[b].y1)) != ((arr[a].x1 <= arr[b].x1 && arr[a].x2 >= arr[b].x1) && (arr[a].y1 <= arr[b].y1 && arr[a].y2 >= arr[b].y1))))
	{
		cout << "arr[a].x1: " << arr[a].x1 << " arr[a].x2: " << arr[a].x2 << " arr[b].x1: " << arr[b].x1 << " arr[b].x2: " << arr[b].x2 << endl;
		//cout << "arr[a].y1: " << arr[a].y1 << " arr[a].y2: " << arr[a].y2 << " arr[b].y1: " << arr[b].y1 << " arr[b].y2: " << arr[b].y2 << endl;
		return true;
	}
	else return false;
}
void bfs() {
	for (int a = 0; a <= N; a++) {
		if (chk[a]) 
			continue;
		chk[a] = 1;
		q.push(a);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			//chk[cur] = 1;
			for (int b = 0; b <= N; b++) {
				if (b == cur || !overlap(cur, b) || chk[b]) {
					//cout << "b: " << b << endl;
					continue;
				}
				else {
					//cout << "x1: "<<arr[b].x1 << " y1: " << arr[b].y1 << " x2: " << arr[b].x2 << " y2: " << arr[b].y2 << endl;
					chk[b] = 1;
					q.push(b);
				}
			}
		}
		cnt++;
	}
	cout << cnt-1;
}
int main() {
	cin >> N;
	chk = vector<int>(N+1, 0);
	Posi tmp;
	arr.push_back({ 0,0,0,0 });
	for (int a = 1; a <= N; a++) {
		cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
		arr.push_back(tmp);
	}
	bfs();
	return 0;
}

/*
//vector<vector<vector<vector<vector<int>>>>> arr;
int N;
vector<vector<int>>chk;
struct Posi {
	int x, y;

};
int main() { 
	cin >> N;
	vector<pair<Posi, Posi>> p;
	Posi tmp1,tmp2;
	int res = 1;
	if (N == 1) res = 0;
	for (int a = 0; a < N; a++) {
		cin >> tmp1.x >> tmp1.y >> tmp2.x >> tmp2.y;
		if ((tmp1.x == 0 && tmp1.y == 0) || (tmp2.x == 0 && tmp2.y == 0)) res =-1;
		p.push_back({ tmp1,tmp2 });
	}
	chk = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (chk[i][j])continue;
			if ((p[i].first.x <= p[j].first.x && p[i].second.x >= p[j].first.x && p[i].first.y <= p[j].first.y && p[i].second.y >= p[j].first.y) != (p[i].first.x <= p[j].second.x && p[i].second.x >= p[j].second.x && p[i].first.y <= p[j].second.y && p[i].second.y >= p[j].second.y)) {
				chk[i][j]++;
				chk[j][i]++;
			}
			else if ((p[i].first.x <= p[j].first.x && p[i].second.x >= p[j].first.x && p[i].first.y <= p[j].second.y && p[i].second.y >= p[j].second.y) != (p[i].first.x <= p[j].second.x && p[i].second.x >= p[j].second.x && p[i].first.y <= p[j].first.y && p[i].second.y >= p[j].first.y)) {
				chk[i][j]++;
				chk[j][i]++;
			}
		}
	}//for end i
	for (int i = 0; i < N; i++) {
		//int zcnt=0;
		for (int j = 0; j < N; j++) {
			if (chk[i][j]>0) break;
			if (j == N - 1) res++;
		}
	}
	//arr = vector<vector<vector<vector<vector<int>>>>> (1001,vector<vector<vector<vector<int>>>>(1001,vector<vector<vector<int>>>(1001,vector<vector<int>>(1001,vector<int>(N,0)))));
	
	cout << res;
	return 0;
}
*/