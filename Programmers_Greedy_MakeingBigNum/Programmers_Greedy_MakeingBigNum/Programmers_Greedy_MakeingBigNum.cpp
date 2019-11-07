#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	vector<int> num;
	int cnt =1,idx=0;
	while (1) {
		for (int i = idx; i < number.size(); i++) {
			if (i + 1 > k + cnt) {//number.size()-1-i<=number.size()-k-cnt
				break;
			}
			if (number[idx] < number[i]) {
				idx = i;
			}
		}
		cnt++;
		answer += number[idx];
		idx++;
		if (cnt > number.size() - k) break;

	}
	/*
	for(int i=0;i<number.size();i=chk){
		int max=0;
		for (int j = i; j < number.size(); j++) {
			
			if ((number.size() - j - 1) < (k - cnt)) {
				//chk = j; 
				break; 
			}
			if (number[j] > max ){ 
				max = number[j];
				chk = j;
			}
		}
		answer += max;
		cnt++;
		if (chk == number.size() - 1)break;
	}*/
	//cout << answer << endl;
	return answer;
}
int main() {

	solution("1924", 2);
	solution("1231234", 3);
	solution("4177252841", 4);
	return 0;
}