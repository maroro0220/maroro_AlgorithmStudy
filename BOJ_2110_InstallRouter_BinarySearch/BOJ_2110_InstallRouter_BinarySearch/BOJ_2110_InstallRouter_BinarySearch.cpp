#include<iostream>
//#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, C;
	scanf("%d %d", &N,&C);
	//vector<int>house(N);
	int* house = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &house[i]);
	}
	sort(house, house + N);
	int left=1, right=house[N-1]-house[0];
	int dist;
	int res = 0;
	while (left <= right) {
		dist = (left+right) / 2;
		int pre = house[0];
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if (house[i] - pre >= dist) {
				cnt++;
				pre = house[i];
			}
			if (cnt == C) break;
		}

		if (cnt == C) {
			res = max(res, dist);
			left = dist+1;
		}
		else {
			right = dist - 1;
		}
	}
	printf("%d", res);
	return 0;
}