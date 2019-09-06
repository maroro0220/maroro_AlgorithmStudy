	#include <string>
	#include <vector>
	#include<algorithm>
	using namespace std;
	int cnt;
	int min_cnt = 99999;
	int visit[50] = {0,};
	void dfs(string b, string t, vector<string> word, int next) {
		int c = 0;
		if (!b.compare(t)) {
			min_cnt = min(min_cnt, next );
			return;
		}
			if (next == word.size()) {
				cnt = 0;
				return;
			}

			for(int a=0; a < word.size();a++){
				c = 0;
				if (!visit[a]) {
					for (int i = 0; i < b.size(); i++) {
						if (b[i] == word.at(a)[i]) {
							c++;
						}
					}//end for check word
				}
				else continue;
				if (c == b.size() - 1) {
					b = word.at(a);
					visit[a] = 1;
					dfs(b, t, word, next+1);
					//visit[a] = 0;
				}
			}//end for a word isze
	
	}

	void clearF() {
		for (int i = 0; i < 50; i++) {
			visit[i] = 0;
		}
	}
	int solution(string begin, string target, vector<string> words) {
		int answer = 0;
		int tmp;
		min_cnt = 99999;
		dfs(begin, target, words, 0);
		if (min_cnt == 99999) min_cnt=0;
		answer = min_cnt;
		printf("%d\n", answer);
		clearF();
		return answer;
	}
	int main() {

		string b = "hit";
		string t = "cog";
		string t2 = "hhh";
		vector<string> str1 = { "hot","dot","dog","lot","log","cog" };
		vector<string> str2 = { "hot","dot","dog","lot","log" };
		vector<string> str3 = { "hhh","hht" };
		solution(b, t, str1);
		clearF();
		solution(b, t, str2);
		clearF(); 
		solution(b, t2, str3);
		clearF();

		return 0;
	}