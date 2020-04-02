#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	int M, N;
	cin >> N;
	/*
	//time over
	map<int, int>num;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (num.count(tmp)) {
			num[tmp]++;
			//num.insert(pair<int,int>(tmp, 1));
		}
		else {
			num.insert(make_pair(tmp,1));
			//num[tmp]=num[tmp]+1;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (num[tmp])printf("%d ", num[tmp]);
		else printf("0 ");
	}
	*/
	return 0;
}