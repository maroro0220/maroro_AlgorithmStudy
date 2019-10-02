#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, K;
	int tmp,cnt=0;
	cin >> N >> K;
	vector<int>arr;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	//reverse(arr.begin(), arr.end());
	for (int i = arr.size() - 1; i >= 0; i--) {
		while(arr[i] <= K) {
			cnt++;
			K -= arr[i];
		}
	}
	cout << cnt;
	return 0;
}