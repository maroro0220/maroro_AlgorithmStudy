#include<iostream>
#include<vector>

using namespace std;

int main() {
	int M;
	int N;
	scanf("%d %d", &N, &M);
	vector<int>tree(N);
	int min = 0, max = 0, mid;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);
		if (tree[i] > max) {
			max = tree[i];
		}
	}
	int ans = 0;
	while (min <= max) {
		mid = (min + max) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (mid < tree[i]) {
				sum += (tree[i] - mid);
			}
		}
		//if (sum == M) break;
		//else if (sum > M) {
		if (sum >= M) {
			if (ans < mid) {
				ans = mid;
			}
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	printf("%lld", ans);

	return 0;
}