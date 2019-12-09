#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		vector<pair<int, int>> m;

		int cnt = 1;
		cin >> n;
		while (n--) {
			int a, b;
			cin >> a >> b;
			m.push_back({ a,b });
		}
		sort(m.begin(), m.end());
		int p = m[0].second;
		for (int i = 1; i < m.size(); i++) {
			if (m[i].second < p) {
				p = m[i].second;
				cnt++;
			}
		}
		/*
		//time over
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m.size(); j++) {
				if (i == j)continue;
				if ((m[i].first > m[j].first) && (m[i].second > m[j].second)) {
					cnt++;
					break;
				}
			}
		}
		*/
		cout <<  cnt << '\n';
		//cout << "result:"<< m.size()-cnt << '\n';
	}
	return 0;
}