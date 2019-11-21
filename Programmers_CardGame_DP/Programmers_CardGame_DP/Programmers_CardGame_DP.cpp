#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	sort(left.begin(), left.end(), greater<int>());//Descending order
	int left_max = left[0];
	for (int i = 0; i < right.size(); i++) {
		if (left_max > right[i]) answer += right[i];
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