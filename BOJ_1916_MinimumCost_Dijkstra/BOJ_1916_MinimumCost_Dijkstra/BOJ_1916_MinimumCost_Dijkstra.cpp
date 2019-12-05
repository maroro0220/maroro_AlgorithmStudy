#include<iostream>
#include<queue>
#include<vector>
const int INF = 0x7FFFFFFF;
using namespace std;
struct FromTo {
	int s, d;
};

int main() {
	int N, M;
	//priority_queue<pair<int,FromTo>, vector<pair<int, FromTo>>, greater<pair<int, FromTo>>> pq;
	priority_queue < pair<int, int>, vector < pair<int, int> >, greater<pair<int, int>>>pq;
	vector<int> dist;
	cin >> N >> M; // city num, Bus num
	
	dist = vector<int>(N + 1, INF);
	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
	for (int i = 0; i < M; i++) {
		int a, b, c;
//		FromTo tmp;
		cin >> a >> b >> c;//start,dest,weight
		if (graph[a][b] != INF) {
			graph[a][b] = graph[a][b] > c ? c : graph[a][b];
		}
		else {
			graph[a][b] = c;
		}
//		tmp.s = a, tmp.d = b;
//		pq.push({ c, tmp });
	}
	int S, D;
	cin >> S >> D;
	pq.push({ 0, S });
	dist[S] = 0;
	while (!pq.empty()) {
		//pair<int, int> cur = pq.top();
		int cur_weight = pq.top().first;//dist[cur_from]
		int cur_from = pq.top().second;
		pq.pop();
		for (int i = 1; i <= N; i++) {
			//if (graph[cur_from][i] >= 0 && graph[cur_from][i] < 100000) {//exist
			if (graph[cur_from][i]!=INF){
				if (dist[i] > dist[cur_from] + graph[cur_from][i]) {// dist[cur_from] =cur_weight
					dist[i] = cur_weight + graph[cur_from][i];
					pq.push({dist[i],i});
				}
			}
		}
	}
	cout << dist[D];
	return 0;
}