#include <iostream>
#include<map>
using namespace std;
int main() {
	int n, m;
	//int* stud;
	//int* num;
	map<int,int>num;
	cin >> n >> m;
	//stud = new int[n];
	//num = new int[m];
	for (int i = 0; i < n; i++) {
		//cin >> stud[i];
		int stud;
		cin >> stud;
		if (num.count(stud)) {
			int t = num.find(stud)->second;
			num.erase(stud);
			num.insert({ stud,t + 1 });
		}
		else {
			num.insert({stud,1});
		}
	}
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (num.count(tmp)) {
			printf("%d ", num.find(tmp)->second);
		}//num.insert({ tmp,true });
		else {
			printf("0 ");
		}
	}
	return 0;
}