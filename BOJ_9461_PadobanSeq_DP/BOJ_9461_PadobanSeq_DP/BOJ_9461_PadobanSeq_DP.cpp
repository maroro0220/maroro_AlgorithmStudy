#include<iostream>
#include<vector>

using namespace std;

int main() {
	int T, N;
	cin >> T;
		while (T--) {
			cin >> N;
			vector<long long>p(N+1);
			p[0] = 1; p[1] = 1; p[2] = 1;
			for (int i = 3; i <= N; i++) {
				p[i] = p[i - 2] + p[i - 3];
			}
			cout << p[N-1]<<endl;
		}
	return 0;
}