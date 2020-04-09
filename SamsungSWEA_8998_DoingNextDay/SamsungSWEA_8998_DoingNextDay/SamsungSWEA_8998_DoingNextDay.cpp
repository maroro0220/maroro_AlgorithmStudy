
#include<iostream>
//#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
struct cmp
{
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.first > b.first;
	}

};
bool desc(pair<int, int> a, pair<int, int>b) {
	if (a.first > b.first) return true;
	else return false;
}
int main(int argc, char** argv)
{

	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int T, D;
		//priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
		//priority_queue<pair<int, int>> pq;
		vector<pair<int, int>>v;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &T, &D);
			v.push_back({ D,T });
			//pq.push({ D,T });
		}
		sort(v.begin(), v.end(),desc);
		
		int last = v[0].first - v[0].second;
		for (int i = 1; i < N; i++) {
			//last = min(last, v[i].first) - v[i].second;
			
			int now_fin = v[i].first;
			if (last >= now_fin) {
				last = now_fin - v[i].second;
			}
			else {
				last = last - v[i].second;
			}
			
		}
		printf("#%d %d\n", test_case, last);
		/*
		//Time over
		int last=pq.top().first-pq.top().second;
		pq.pop();
		while (!pq.empty()) {
			pair<int,int> front = pq.top();
			pq.pop();
			if (last >= front.first) {
				last = front.first - front.second;
			}
			else if (last<front.first) {
				last = last - front.second;
			}
			//printf("%d %d\n", front.first, front.second);
		}
		*/
		//printf("#%d %d\n", test_case, last);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}