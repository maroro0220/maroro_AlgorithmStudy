#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int solution(string s) {
	int answer = 0;
	string sind, stmp;
	int ans_min = 999999;
	for (int n = 1; n <= s.size(); n++) {
		stmp.clear();
		int idx = 0;
		//int cnt = 1;
		while (1) {
			if (idx == s.size()) break;
			else if (idx > s.size()) {
				idx -= n;
				for (int a = idx; a < s.size(); a++) {
					stmp += s[a];
				}
			}
			sind.clear();
			int cnt = 0;
			for (int i = idx; i < idx + n && i < s.size(); i++) {
				sind += s[i];
			}//sind 
			while (1) {
				if (!s.compare(idx, sind.size(), sind)) {
					cnt++;
					idx += sind.size();
				}
				else {
					//idx += n;
					break;
				}
			}//end while
			if (!cnt || cnt == 1) {
				stmp += sind;
			}
			else {
				stmp += to_string(cnt) + sind;
			}

		}//end while
		int a = stmp.size();
		//cout << "stmp: " << stmp << endl;
		ans_min = min(ans_min, a);
		//printf("%d\n", ans_min);

	}//for n
	printf("%d\n", ans_min);
	answer = ans_min;
	return answer;
}
int main() {
	string s1 = "aabbaccc";
	solution(s1);
	string s2 = "ababcdcdababcdcd";
	solution(s2);
	string s3 = "abcabcdede";
	solution(s3);
	string s4 = "abcabcabcabcdededededede";
	solution(s4);
	string s5 = "xababcdcdababcdcd";
	solution(s5);
	system("pause");
	return 1;
}