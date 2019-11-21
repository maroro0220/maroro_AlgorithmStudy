#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int Find(vector<int> card) {
	int maxi=0,maxi_idx=0;
	for (int i = 0; i < card.size(); i++) {
		if (maxi < card[i]) { maxi = card[i]; maxi_idx = i; }
	}
	return maxi_idx;
}
int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	//sort(left.begin(), left.end(), greater<int>());//Descending order
	//int left_max = left[0];
	int left_max_idx = Find(left);
	for (int i = 0; i < right.size(); i++) {
		if (left[left_max_idx] > right[i]) { 
			answer += right[i]; 
		}
		else {
			left[left_max_idx] = 0; right[i] = 0;
			left_max_idx = Find(left);
		}
	}
	/*
	int l_idx =0, r_idx = 0;

	while (l_idx < left.size() && r_idx < right.size()) {
		if (left[l_idx] > right[r_idx]) {
			answer += right[r_idx];
			right[r_idx] = 0;
			r_idx++;
		}
		else {
			left[l_idx] = 0; l_idx++;
		}
	}
	*/
	return answer;
}

int main() {

	printf("%d\n", solution({ 3,2,5 }, { 2,4,1 }));//7
	return 0;
}