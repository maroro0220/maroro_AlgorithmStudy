#include <string>
#include <vector>

using namespace std;
int ans;
void cal(vector<string> w, string q) {

	for (int i = 0; i < w.size(); i++) {
		int c = 0;
		if (w[i].size() != q.size()) continue;
		for (int j = 0; j < q.size(); j++) {
			if (q[j] != '?' && w[i][j] != q[j]) { break; }
			else if (q[j] == '?' || w[i][j] == q[j]) c++;
		}
		if (c == q.size()) { ans++; }
	}
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	for (int i = 0; i < queries.size(); i++) {
		/*	int cnt = 0;
			for (int j = 0; j < words.size(); j++) {
				if (queries[i].size() != words[j].size()) {
					continue;
				}
				else {
					int c = 0;
					for (int k = 0; k < queries[i].size(); k++) {
						if (queries[i][k] == '?') {
							c++;
							continue;
						}
						else {
							if (queries[i][k] != words[j][k]) {
								break;
							}//end if
							c++;
						}//end else
					}//end for k
					if (c == queries[i].size()) cnt++;
				}
			}//end for j
			*/
		cal(words, queries[i]);
		answer.push_back(ans);
		printf("%d ", ans);
		ans = 0;
	}
	return answer;
}

int main() {
	vector<string> w1 = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> q1 = { "fro??", "????o", "fr???", "fro???", "pro?" };
	solution(w1, q1);
	system("pause");
	return 0;

}