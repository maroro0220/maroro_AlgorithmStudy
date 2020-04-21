#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		bool res = true;
		cin >> s >> e;
		while (s <= e) {
			if (str[s - 1] == str[e - 1]) {
				s++;
				e--;
			}
			else {
				res = false;
				break;
			}
		}
		if (res) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}