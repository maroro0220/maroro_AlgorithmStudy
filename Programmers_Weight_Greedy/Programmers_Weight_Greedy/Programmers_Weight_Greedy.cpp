#include <string>
#include <vector>
#include<algorithm>
using namespace std;


/*
vector<int> chk;
void Combi(vector<int> tmp, int n) {
	vector<int> idx;
	for (int i = 0; i < n; i++) {
		idx.push_back(1);
	}
	for (int i = 0; i < tmp.size() - n; i++) {
		idx.push_back(0);
	}
	sort(idx.begin(), idx.end());
	sort(tmp.begin(), tmp.end());
	do {
		int sum = 0;
		for (int i = 0; i < tmp.size(); i++) {
			if (idx[i] == 1) sum += tmp[i];
		}
		chk[sum] = 1;
	} while (next_permutation(idx.begin(), idx.end()));
	
}
int solution(vector<int> weight) {
	int answer = 0;
	int s = 0;
	for (int i = 0; i < weight.size(); i++) {
		s += weight[i];
	}
	chk = vector<int>(s+1,0);
	
	for (int i = 1; i <=weight.size(); i++) {
		Combi(weight, i);
	}
	for (int i = 1; i < s; i++) {
		if (!chk[i]) {
			answer = i;
			break;
		}
	}
	return answer;
}*/

int solution(vector<int> weight) {
	int answer = 0;
	int sum = 0;
	sort(weight.begin(), weight.end());
	
	for (int i = 0; i < weight.size(); i++) {
		if (sum + 1 >= weight[i]) {
			sum += weight[i];
		}
		else {
			//Not available sum++;. Because, if there are no number between 1 to sum of all
			break;
		}

	}
	answer = ++sum;
	return answer;
}
int main() {
	printf("%d\n", solution({ 3, 1, 6, 2, 7, 30, 1 }));
	return 0;
}