#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(string name) {
	int answer = 0;
	int cnt = 0,tmp;
	int min = 520;
	string tmp_str;
	for (int i = 0; i < name.size(); i++) {
		tmp_str.push_back('A');
	}

	if (!name.compare(0, name.size(), tmp_str)) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < name.size(); i++) {
		if (!name.compare(0, name.size() , tmp_str)) break;
		tmp=name[i] - 'A' > 'Z' - name[i] + 1 ? 'Z' - name[i] + 1 : name[i] - 'A';
		tmp_str[i] =name[i];
		cnt += tmp;
		cnt++;
	}
	if (min > cnt)min = cnt;
	tmp_str.clear();
	for (int i = 0; i < name.size(); i++) {
		tmp_str.push_back('A');
	}
	cnt = 0;
	tmp= name[0] - 'A' > 'Z' - name[0] + 1 ? 'Z' - name[0] + 1 : name[0] - 'A';
	tmp_str[0] = name[0];
	cnt += tmp;
	//tmp++;
	if (name.compare(0, name.size(), tmp_str)) {
		for (int i = name.size() - 1; i > 0; i--) {
			int res = name.compare(0, name.size() , tmp_str);
			if (!res) {
				break; 
			}
			cnt++;
			tmp= name[i] - 'A' > 'Z' - name[i] + 1 ? 'Z' - name[i] + 1 : name[i] - 'A';
			cnt += tmp;
			tmp_str[i] = name[i];
		}
	}

	if (min > cnt)min = cnt;
	answer = min;
	cout << answer << endl;
	return answer;
}
int main() {
	solution("JAZ");
	solution("JEROEN");
	solution("JAN");
	solution("ABABAAAAABA");
	return 0;
}