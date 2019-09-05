#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> combi;

void seper(int arr[],int a) {
	int t;
	t = a;
	arr[2] = t % 10;
	t /= 10;
	arr[1] = t % 10;
	t /= 10;
	arr[0] = t % 10;
}
int Permutation() {/* Permutation https://hahaite.tistory.com/294 */ 
	vector<int> comb_tmp;
	for (int i = 0; i < 9; i++) {
		comb_tmp.push_back(i+1);
	}
	vector<int> ind;
	int k = 3;
	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	for (int j = 0; j < comb_tmp.size() - k; j++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	while (1) {
		int cnt = 0;
		int tmp_num;
		for (int i = 0; i < 3; i++) {
			if (cnt == 0) {
				tmp_num = comb_tmp[i];
			}
			else {
				tmp_num = tmp_num * 10 + comb_tmp[i];
			}
			cnt++;
		}
		combi.push_back(tmp_num);
		reverse(comb_tmp.begin() + 2, comb_tmp.end());
		if (!next_permutation(comb_tmp.begin(), comb_tmp.end()))break;
	}
	
	return 0;
}
int solution(vector<vector<int>> baseball) {
	int answer = 0;
	int* arr_comb;
	int* arr_tmp;
	arr_comb = (int*)calloc(3, sizeof(int));
	arr_tmp = (int*)calloc(3, sizeof(int));
	int arr_chk[100][988][2] = { 0, };
	Permutation();
	for (int i = 0; i < combi.size(); i++) {
		int test = 0;
		for (int j = 0; j < baseball.size(); j++) {
			 seper(arr_tmp,baseball[j][0]);
			 seper(arr_comb,combi[i]);
			for(int z=0;z<3;z++){
				if (arr_tmp[z] == arr_comb[z]) {
					//strike
					arr_chk[j][combi[i]][0]++;
				}
			}//end for a
			if (arr_tmp[0] == arr_comb[1] || arr_tmp[0] == arr_comb[2] ) {
				//ball
				arr_chk[j][combi[i]][1]++;
			}
			if ( arr_tmp[1] == arr_comb[0] || arr_tmp[1] == arr_comb[2]) {
				//ball
				arr_chk[j][combi[i]][1]++;
			}
			if ( arr_tmp[2] == arr_comb[0] || arr_tmp[2] == arr_comb[1]) {
				//ball
				arr_chk[j][combi[i]][1]++;
			}
			if (arr_chk[j][combi[i]][0] == baseball[j][1] && arr_chk[j][combi[i]][1] == baseball[j][2]) {
				++test;
			}
			if (test== baseball.size()) {
				answer++;
			}
		}//end for j. baseball. init.

		

	}//end for i
	return answer;
}

int main() {
	vector<vector<int>> num_tmp2;
	vector<int> tmp1;
	vector<int> num_tmp1;
	int tmp;
	for(int i=0;i<12;i++){
		scanf("%d", &tmp);
		tmp1.push_back(tmp);
	}
	for (int j = 0; j < tmp1.size(); j+=3) {
		num_tmp1.push_back(tmp1[j]);
		num_tmp1.push_back(tmp1[j+1]);
		num_tmp1.push_back(tmp1[j+2]);
		num_tmp2.push_back(num_tmp1);
		num_tmp1.clear();
	}
	printf("%d",solution(num_tmp2));
	return 0;
}