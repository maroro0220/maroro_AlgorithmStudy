#include<iostream>
#include<vector>
#define INF 0x7FFFFFFF
using namespace std;
struct Edge {
	int s, d, w;
};
int v, e;
int a, b, c;
int res;
vector<int>chk;
void Bellman(vector<Edge>& m) {
	vector<int> dist(v+1,INF);
	dist[1] = 0;
	for (int i = 1; i <=v; i++) {
		for (int j = 0; j < m.size(); j++) {
			int start = m[j].s, desti = m[j].d, w = m[j].w;
			if (desti!=0&&dist[start]!=INF && dist[desti] > dist[start] + w) {
				dist[desti] = dist[start] + w;
				chk[desti] = start;//start->desti
			}
		}
	}
	res += dist[v];
}
int main() {

	vector<Edge> map;
	Edge tmp;
	cin >> v >> e;
	chk = vector<int>(v + 1, 0);
	for (int i = 0; i < e; i++) {
		cin >> tmp.s >> tmp.d >> tmp.w;
		map.push_back(tmp);
	}
	Bellman(map);
	Bellman(map);
	cout << res;

	return 0;
}