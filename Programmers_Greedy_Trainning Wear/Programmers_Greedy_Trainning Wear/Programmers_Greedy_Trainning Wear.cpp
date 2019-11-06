#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<int> chk;
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	chk = vector<int>(n + 1, 1);
	for (int i = 0; i < lost.size(); i++) {
		chk[lost[i]] --;
	}//chk student who lost trainning wear
	for (int i = 0; i < reserve.size(); i++) {
		chk[reserve[i]] ++;
	}//chk student who lost trainning wear

	for (int i = 0; i < reserve.size(); i++) {
		if (reserve[i] - 1 > 0 && chk[reserve[i] - 1] == 0 && chk[reserve[i]] == 2) {
			chk[reserve[i] - 1] ++;
			chk[reserve[i]]--;
			continue;
			//chk[reserve[i]] = 1;
		}
		else if (reserve[i] + 1 <= n && chk[reserve[i] + 1] == 0 && chk[reserve[i]] == 2) {
			chk[reserve[i] + 1] ++;
			chk[reserve[i]]--;
			continue;
			//chk[reserve[i]] = 1;
		}
	}//chk student who is having extra trainning wear
	for (int i = 1; i <= n; i++) {
		if (chk[i]>0) {
			answer++;
		}
	}
	cout << answer << endl;
	return answer;
}
int main() {
	solution(5, { 2,4 }, { 1,3,5 });
	solution(5, { 2,4 }, { 3 });
	solution(3, { 3 }, { 1 });
	solution(5, { 2,3 }, { 5,3,1 });
	return 0;
}