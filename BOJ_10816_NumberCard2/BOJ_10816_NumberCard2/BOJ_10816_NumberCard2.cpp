#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int Up(int *arr,int t,int s){
	int left = 0, right = s - 1;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] > t) {
			right = mid;
		}
		else left=mid+1;
	}
	return right;
}
int Low(int *arr, int t, int s) {
	int left = 0, right = s - 1;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] >= t) {
			right = mid;
		}
		else left = mid + 1;
	}
	return right;
}
int main() {
	int M, N;
	scanf("%d", &N);
	//vector<int>sang(N);
	int *sang = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &sang[i]);
	}
	sort(sang, sang + N);
	//sort(sang.begin(), sang.end());
	scanf("%d",&M);
	int tmp;
	
	int up, low;
	for (int i = 0; i < M; i++) {
		//cin >> tmp;
		scanf("%d", &tmp);
		up = Up(sang, tmp, N);
		low = Low(sang, tmp, N);
		//if (up - low) up++;
		if (up == N - 1 && sang[N - 1] == tmp) { 
			up++; 
		}
		printf("%d ", up-low );
	}
	
	/*
	//slow
	map<int, int>num;
	//int tmp;
	for (int i = 0; i < N; i++) {
		num.insert({ sang[i],0 });
	}
	for (int i = 0; i < N; i++) {
		num.find(sang[i])->second++;
	}
	for (int i = 0; i < M; i++) {
		
		scanf("%d", &tmp);
		if (num.count(tmp))printf("%d ", num.find(tmp)->second);
		else printf("0 ");
	}
	*/
	return 0;
}