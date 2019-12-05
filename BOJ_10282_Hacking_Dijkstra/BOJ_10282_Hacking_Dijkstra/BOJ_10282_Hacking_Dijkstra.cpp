#include<iostream>
#include<queue>
#include<vector>
const int Maxi = 0x7FFFFFFF;
using namespace std;
struct Ver{
	int sec,com;
};
struct cmp {
	bool operator()(Ver a, Ver b) {
		return a.sec>b.sec;
	}
};
void Dijkstra_Func(vector<Ver> graph[], int n, int d, int start) {
	vector<int>sec(n + 1, Maxi);
	priority_queue < Ver, vector<Ver>, cmp> pq;
	//priority_queue < Ver, vector<Ver>, greater<Ver>>;
	sec[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cur_com = pq.top().com;
		int cur_sec = pq.top().sec;
		pq.pop();
		for (int i = 0; i < graph[cur_com].size(); i++) {
			int next_sec = graph[cur_com][i].sec;
			int next_com = graph[cur_com][i].com;
			if (sec[next_com] > sec[cur_com] + next_sec) {
				sec[next_com] = sec[cur_com] + next_sec;
				pq.push({ sec[next_com], next_com });
			}

		}
	}
	int cnt = 0,maxi=0;
	for (int i = 1; i <= n; i++) {
		if (sec[i] != Maxi) {
			cnt++;
			maxi = maxi < sec[i] ? sec[i] : maxi;
		}
	}
	cout << cnt << ' ' << maxi << endl;


}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, d, com;
		cin >> n >> d >> com;
		vector<Ver>g[10001];
		for (int i = 0; i < d; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			g[b].push_back({ c,a });
		}
		Dijkstra_Func(g, n, d, com);
	}
	return 0;
}