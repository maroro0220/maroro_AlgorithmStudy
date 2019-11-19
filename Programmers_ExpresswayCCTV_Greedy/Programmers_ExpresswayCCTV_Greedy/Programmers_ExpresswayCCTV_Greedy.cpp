#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int solution(vector<vector<int>> routes) {
	int answer = 0;
	int end;
	sort(routes.begin(), routes.end());
	end = routes[0][1];
	for (int i = 0; i < routes.size(); i++) {
		if (routes[i][0] <= end) {
			end = min(end, routes[i][1]);
		}
		else {
			answer++;
			end = routes[i][1];
		}
	}
	answer++;
	
	return answer;
}
int main() {
	printf("%d\n", solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} }));//2
	printf("%d\n", solution({ {-2,-1},{1,2},{-3,0}}));//2
	printf("%d\n", solution({ {0,0}}));//1
	printf("%d\n", solution({ {0,1},{0,1},{1,2} }));//1
	printf("%d\n", solution({ {0,1},{2,3},{4,5},{6,7} }));//4
	printf("%d\n", solution({ {-20,-15},{-14,-5},{-18,-13},{-5,-3} }));//2
	printf("%d\n", solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} }));//2
	printf("%d\n", solution({ {-20,-15},{-20,15},{-14,-5},{-5,-3} }));//2

	printf("%d\n", solution({ {0,0},{0,0},{2,2} }));//2
	printf("%d\n", solution({ {0,1},{0,1},{2,2} }));//2

	return 0;
}