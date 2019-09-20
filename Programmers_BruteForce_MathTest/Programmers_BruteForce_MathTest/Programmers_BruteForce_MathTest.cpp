// https://programmers.co.kr/learn/courses/30/lessons/42840
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> st1 = { 1,2,3,4,5 }, st2 = { 2, 1, 2, 3, 2, 4, 2, 5 }, st3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	//int chk1=0, chk2=0, chk3=0;
	int maxS=0;
	vector<int> chk(3);
	for (int i = 0; i < answers.size(); i++) {
		if (st1[i%5] == answers[i]) chk[0]++;
		if (st2[i%8] == answers[i]) chk[1]++;
		if (st3[i%10] == answers[i]) chk[2]++;
	}
	maxS = max(max(chk[0], chk[1]), chk[2]);
	for (int i = 0; i < 3; i++) {
		if (chk[i] == maxS) {
			answer.push_back(i+1);
		}
	}
	return answer;
}

int main() {
	vector<int> ans1 = { 1,2,3,4,5 }, ans2 = { 1,3,2,4,2 };
	solution(ans1);
	solution(ans2);
}