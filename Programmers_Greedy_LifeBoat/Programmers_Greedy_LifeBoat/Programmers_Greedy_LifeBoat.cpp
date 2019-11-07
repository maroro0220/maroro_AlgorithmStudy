#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int cnt = 0,idx=0,i;
	//int tmp = limit;
	for (i = people.size() - 1; i >idx;i-- ) {
		if (people[i] + people[idx] <= limit) {
			cnt++;
			idx++;
		}
		else {
			cnt++;
		}
	}
	if (idx == i) {
		cnt++;
	}
	cout << cnt << endl;
	answer = cnt;
	return answer;
}

int main() {
	//solution({ 70, 50, 80, 50 }, 100);
	solution({ 70, 80, 50 }, 100);
	return 0;
}