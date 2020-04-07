#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[4];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int* arAB = new int[N * N];
	int* arCD = new int[N * N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arAB[i * N + j] = arr[i][0] + arr[j][1];
			arCD[i * N + j] = arr[i][2] + arr[j][3];
		}
	}
	//sort(arAB, arAB + N * N );
	sort(arCD, arCD + N * N);
	int mid;
	long long ret = 0;
	for (int i = 0; i < N * N; i++) {

		int left = 0, right = N * N;
		while (left < right) {
			mid = (left + right) / 2;
			if (arAB[i] + arCD[mid] < 0) {
				left = mid + 1;
			}
			else right = mid;
		}
		int low_bound = right;
		left = 0; right = N * N;
		while (left < right) {
			mid = (left + right) / 2;
			if (arAB[i] + arCD[mid] <= 0) {
				left = mid + 1;
			}
			else right = mid;
		}
		int up_bound = right;
		ret += (long long)(up_bound - low_bound);
	}
	printf("%lld", ret);
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}