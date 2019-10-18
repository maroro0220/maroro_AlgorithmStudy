#include<iostream>
#include<vector>

using namespace std;

int main() {

	int M ,N,cnt=0;
	cin >> N >> M;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];
			if (sum > M) { break; }
			if (sum == M) { cnt++; break; }
		}
	}
	cout << cnt;
	return 0;
}