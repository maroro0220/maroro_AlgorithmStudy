#include<iostream>
#include<vector>
#include<queue>
const int INF = 0x7FFFFFFF;
using namespace std;

int main() {
	
	/*
	ios::sync_with_stdio(false);
	ios::sync_with_stdio는 cpp의 iostream을 c의 stdio와 동기화시켜주는 역할을 합니다. 
	이는 iostream, stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생하게 됩니다.
	ios::sync_with_stdio(false)는 이 동기화 부분을 끊는 함수입니다. 
	이를 사용하면 c++만의 독립적인 버퍼를 생성하게 되고 c의 버퍼들과는 병행하여 사용할 수 없게 됩니다. 
	대신 사용하는 버퍼의 수가 줄어들었기 때문에 속도는 높아지게 됩니다.
	출처: https://codecollector.tistory.com/381 [뽕뽑기]
	*/
	ios_base::sync_with_stdio(0);//without this, occur time out
	int V, E,K, u, v, w;
	cin >> V>>E;
	cin >> K;
	//vector<vector<int>> graph(V+1,vector<int>(V+1,0));
	vector<pair<int,int>>graph[20001];
	for (int i = 1; i <= E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int>dist(V + 1, INF);
	pq.push({ 0,K }); //K's weight, start point K
	dist[K] = 0;
	while (!pq.empty()) {
		int cur_weight = pq.top().first;
		int cur_from = pq.top().second;
		pq.pop();
		//if (dist[cur_from] < cur_weight) continue; //don't need
		for (int i = 0; i < graph[cur_from].size(); i++) {
			int next = graph[cur_from][i].first;
			int cost = graph[cur_from][i].second;
			if ( (dist[next] > cost + dist[cur_from])) {
				dist[next] = cost + dist[cur_from];
				pq.push({ dist[next],next });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';//endl is slow
		else cout << dist[i] << '\n';//endl is slow
	}
	return 0;
}