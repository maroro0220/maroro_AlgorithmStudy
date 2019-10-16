#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>>city(N, vector<int>(N));
	vector<vector<int>>tmp(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>city[i][j];
		}
	}
	//tmp = city;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (city[i][j] > city[i][k] + city[k][j]){
					cout << -1;
					return 0;
				}
				if (!city[i][k] || !city[k][j]) continue;
				if (city[i][j] == (city[i][k] + city[k][j])) {
					tmp[i][j] = 1;
				}
			}//end for j
		}//end for i
	}//end for k
	cout << endl;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << tmp[i][j]<<' '
			if (!tmp[i][j]) {
				cout << tmp[i][j] << ' ';
				sum += city[i][j];
			}
		}

	}
		cout<<sum/2 << endl;
	return 0;
}