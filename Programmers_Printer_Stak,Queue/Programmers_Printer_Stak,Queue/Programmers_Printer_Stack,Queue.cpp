#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int idx = 0, size = priorities.size();

	while (1) {
		bool flag = true;
		for (int i = idx + 1; i < priorities.size(); i++) {
			if (priorities[idx] < priorities[i]) {
				priorities.push_back(priorities[idx]);
				if (location == idx) {
					location = priorities.size() - 1;
				}
				idx++;
				flag = false;
				break;
			}
		}
		if (flag) {
			if (idx == location) {
				return ++answer;
			}
			idx++;
			++answer;
		}
	}

	return answer;
}


int main() {
	cout<<solution({ 2, 1, 3, 2 }, 2)<<'\n';
	cout<<solution({ 1, 1, 9, 1, 1, 1 }, 0);
	return 0; }