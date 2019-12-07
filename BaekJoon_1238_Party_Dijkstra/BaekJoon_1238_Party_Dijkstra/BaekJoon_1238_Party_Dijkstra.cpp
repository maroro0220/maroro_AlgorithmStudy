#include<iostream>
#include<vector>
#include<queue>
#define INF 0x7FFFFFFF
using namespace std;

struct Dijk
{
	int point, time;
};
struct comp
{
	bool operator()(Dijk a,Dijk b) {
		return a.time > b.time;
	}
};
vector<int>res;
Dijk tmp;	
int s, d, t;
int N, M, X;
vector<Dijk>cityo[1001];
vector<Dijk>cityr[1001];
int FindFar(vector<int> d) {
	int maxi = 0;
	for (int i = 1; i < d.size(); i++) {
		if (maxi < d[i]) maxi = d[i];
	}
	return maxi;
}
void Dijkstra(vector<Dijk> city[],int n,int m,int x) {


	vector<int> dist(n+1,INF);
	priority_queue<Dijk, vector<Dijk>, comp> pq;

	tmp.time = 0, tmp.point = x;
	pq.push(tmp);
	dist[x] = 0;
	while (!pq.empty()) {
		int cur_loc = pq.top().point;
		int cur_tottime = pq.top().time;
		pq.pop();
		for (int i = 0; i < city[cur_loc].size(); i++) {
			int dest_loc = city[cur_loc][i].point;
			int time2dest = city[cur_loc][i].time;
			if (city[cur_loc][i].time != INF && dist[dest_loc] > dist[cur_loc] + city[cur_loc][i].time) {
				dist[dest_loc] = dist[cur_loc] + city[cur_loc][i].time;
				tmp.time = dist[dest_loc], tmp.point = dest_loc;
				pq.push(tmp);
			}
		}
	}
	/*
	//use it when you try N time Dijkstra
	if (x==X ) {
		for (int i = 1; i < dist.size(); i++) {
				res[i] += dist[i];
		}
	}
	
	else {
		res[x] += dist[X];
	}
	*/
	for (int i = 1; i < dist.size(); i++) {
		res[i] += dist[i];
	}
}
int main() {
	cin >> N >> M >> X;
	res.assign(N + 1, 0);
	Dijk tmp2;
	for (int i = 0; i < M; i++) {
		cin >> s >> d >> t;
		tmp.point = d; tmp.time = t;
		tmp2.point = s, tmp2.time = t;
		cityo[s].push_back(tmp);
		cityr[d].push_back(tmp2);
	}
	Dijkstra(cityo, N, M, X);
	Dijkstra(cityr, N, M, X);
	/*
	//N time Dijkstra
	for (int i = 1; i <= N; i++) {
		Dijkstra(cityo,N, M, i);
	}
	*/
	cout<<FindFar(res);
	return 0;
}