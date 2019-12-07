#include<iostream>
#include<vector>
#include<queue>
const int INF = 0x7FFFFFFF;
using namespace std;

int main() {
	
	/*
	ios::sync_with_stdio(false);
	ios::sync_with_stdio�� cpp�� iostream�� c�� stdio�� ����ȭ�����ִ� ������ �մϴ�. 
	�̴� iostream, stdio�� ���۸� ��� ����ϱ� ������ �����̰� �߻��ϰ� �˴ϴ�.
	ios::sync_with_stdio(false)�� �� ����ȭ �κ��� ���� �Լ��Դϴ�. 
	�̸� ����ϸ� c++���� �������� ���۸� �����ϰ� �ǰ� c�� ���۵���� �����Ͽ� ����� �� ���� �˴ϴ�. 
	��� ����ϴ� ������ ���� �پ����� ������ �ӵ��� �������� �˴ϴ�.
	��ó: https://codecollector.tistory.com/381 [�ͻ̱�]
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