#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int> a,vector<int>b) {
	return a[2] < b[2];
}
vector<int> parent;
//Kruskal Algorithm
int find(int node) {
	if (node == parent[node]) return node;
	else return parent[node] = find(parent[node]);
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<int>chk(n,0);
	parent.clear();
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
		//parent[i] = i;
	}
	sort(costs.begin(), costs.end(), cmp);
	for (int i = 0; i < costs.size(); i++) {
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];
		if (start != end) {
			parent[start] = end;
			answer += cost;
		}
	}

	return answer;
}
int main() {
	printf("%d\n", solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} }));
	printf("%d\n", solution(4, { {0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4} }));
	printf("%d\n", solution(6, { {0,1,5},{0,3,2},{0,4,3},{1,4,1},{3,4,10},{1,2,2},{2,5,3},{4,5,4} }));
	return 0;
}