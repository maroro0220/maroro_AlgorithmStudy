#include<iostream>
#include<vector>
using namespace std;
int main() {
	int T,n;
	//vector<int> arr;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		vector<int>arr(n + 1);
		arr[0]=1;//0
		arr[1]=1;//1
		arr[2]=2;//2
		arr[3]=4;//3
		for (int i = 4; i <=n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
		cout << arr[n]<<endl;
	
	}
	return 0;
}

/*
//more batter
#include<stdio.h>
#include<stdlib.h>

int main() {
	int T,n;

	scanf("%d", &T);
	while (T--) {
		int arr[12] = { 0, };
		scanf("%d", &n);
		arr[0] = 1;
		for (int i = 0; i <= n; i++) {
			if (i - 1 >= 0) {
				arr[i] += arr[i - 1];
			}if (i - 2 >= 0) {
				arr[i] += arr[i - 2];
			}if (i - 3 >= 0) {
				arr[i] += arr[i - 3];
			}
		}
		printf("%d\n", arr[n]);
	}


}
*/