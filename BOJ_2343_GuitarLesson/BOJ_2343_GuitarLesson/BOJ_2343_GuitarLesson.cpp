#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int* arr = new int[N];
	int left = 1, right = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		right += arr[i];
		if (left < arr[i])left = arr[i];
	}
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int tmp = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (tmp + arr[i] > mid) {
				tmp = 0;
				cnt++;
			}
			tmp += arr[i];
		}
		if (tmp > 0) cnt++;
		if (cnt > M) {
			left = mid + 1;
		}
		else if (cnt <= M) {
			right = mid - 1;
		}
	}
	printf("%d\n", left);
	return 0;
}