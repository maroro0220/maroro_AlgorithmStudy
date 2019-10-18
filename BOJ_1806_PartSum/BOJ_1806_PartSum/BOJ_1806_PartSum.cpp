#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int S, N, mini = 100001;
	cin >> N >> S;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];
			if (sum >=S) { 
				mini = min(mini, abs(j - i+1));
				break; 
			}
		}
	}
	if (mini == 100001) mini = 0;
	cout << mini;
	return 0;
}