
#include <iostream>
#include<map>
using namespace std;
int main() {
	int n, m;
	map<int, int>num;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int stud;
		scanf("%d", &stud);
		if (num.count(stud)) {
			int t = num.find(stud)->second;
			num.erase(stud);
			num.insert({ stud,t + 1 });
		}
		else {
			num.insert({ stud,1 });
		}
	}
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (num.count(tmp)) {
			printf("%d ", num.find(tmp)->second);
		}
		else {
			printf("0 ");
		}
	}
	return 0;
}


/*
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	int* cnt;
	scanf("%d %d",&n,&m);
	int* arr = new int[n+1]();
	cnt= new int[n]();
	vector<int> numb;
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
		numb.push_back(arr[i]);
	}
	sort(numb.begin(),numb.end());
	numb.erase(unique(numb.begin(), numb.end()), numb.end());
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(numb.begin(), numb.end(), arr[i]) - numb.begin();
		cnt[idx]++;
	}
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (binary_search(numb.begin(), numb.end(), tmp)) {
			int idx = lower_bound(numb.begin(), numb.end(), tmp) - numb.begin();
			printf("%d ", cnt[idx]);
		}
		else
			printf("0 ");
	}
	return 0;
}
*/

