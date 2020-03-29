#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int>a;
void Chk(int b) {
	int left = 0;
	int right = a.size() - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == b) {
			printf("1\n");
			return;
		}
		else if (a[mid] < b) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("0\n");
	return;
}
int main() {
	int N, M;
	scanf("%d", &N);
	//vector<int> a(N);
	a = vector<int>(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	scanf("%d", &M);
	//vector<int>b(M);
	int b;
	for (int i = 0; i < M; i++) {
		scanf("%d", &b);
		Chk(b);
	}

	return 0;
}