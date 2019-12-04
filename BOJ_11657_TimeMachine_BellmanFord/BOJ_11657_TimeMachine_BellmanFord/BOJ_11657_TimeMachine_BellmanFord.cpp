#include<iostream>
#include<vector>
const int INF= 0x7FFFFFFF;
using namespace std;

int main() {
	int N, M, A, B, C;
	cin >> N >> M;
	vector<vector<int>> city(N+1, vector<int>(N+1, INF));
	vector<int> dist(N + 1, INF);
	while (M--) {
		cin >> A >> B >> C;
		if (city[A][B] == INF) {
			city[A][B] = C;
		}
		else {
			if (city[A][B] > C) {
				city[A][B] = C;
			}
		}
	}
	dist[1] = 0;
	bool chk = false;
	for (int i = 0; i < N; i++) {
		for (int s = 1; s <= N; s++) {//Find way
			for (int d = 1; d <= N; d++) {
				if (s != d && dist[s] != INF &&city[s][d]!=INF) {//s!=d because it mean goes itself
					if (dist[d] > dist[s] + city[s][d]) {
						dist[d] = dist[s] + city[s][d];
						if (i ==N-1) {
							chk = true;
							//cout << -1 ;
							//return 0;
						}
					}
				}
			}
		}
	}
	if(chk) cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << endl;
			else cout << dist[i] << endl;
		}
	}
	return 0;
}