#include <string>
#include <vector>

using namespace std;
int op[2] = { -1,1 };
int ret;
int T;
void dfs(vector<int> num,int cnt) {
	
	if (cnt == num.size()) {
		int sum = 0;
		for (int i = 0; i < num.size(); i++) {
			sum += num[i];
		}
		if (sum == T) {
			ret++;
		}
		return ;
	}
	for (int a = 0; a < 2; a++) {
		num[cnt] *= op[a];
		dfs(num, cnt + 1);
		num[cnt] *= op[a];
	}
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	T = target;
	dfs(numbers,0);
	answer = ret;
	//printf("%d", answer);
	return answer;
}
int main() {
	int tmpT=3;
	vector<int> tmpV = {1,1,1,1,1};
	solution(tmpV, tmpT);
		return 0;
}