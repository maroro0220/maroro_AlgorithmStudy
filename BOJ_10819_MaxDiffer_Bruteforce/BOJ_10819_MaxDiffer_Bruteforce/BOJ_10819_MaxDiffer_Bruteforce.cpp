#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> arr;
int N;
int MaxArr() {
	int sum = 0;
	for (int i = 1; i < N; i++) {
		sum += abs(arr[i] - arr[i - 1]);
	}
	return sum;
}
int main() {
	int max_diff = 0;
	cin >> N;
	arr = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int m;
	do {
		m = MaxArr();
		max_diff=max(m,max_diff);
		for (int i = 0; i < N; i++) {
			cout << arr[i]<< ' ';
		}
		cout << endl;
		cout << "sum: " << m << endl;

	} while (next_permutation(arr.begin(), arr.end()));
	cout << max_diff;
	return 0;

}