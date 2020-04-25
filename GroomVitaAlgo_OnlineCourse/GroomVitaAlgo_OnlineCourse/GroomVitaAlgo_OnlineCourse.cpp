#include <iostream>
#include<string>
using namespace std;
int main() {
	string  total, stud;
	cin >> total;
	cin >> stud;
	string tot_t, tot_m, stud_t, stud_m;
	for (int i = 0; i < 2; i++) {
		tot_t += total[i];
		stud_t += stud[i];
		tot_m += total[i + 3];
		stud_m += stud[i + 3];
	}
	int tot_time = stoi(tot_t);
	int tot_min = stoi(tot_m);
	int stud_time = stoi(stud_t);
	int stud_min = stoi(stud_m);
	if (abs(stud_time - tot_time) > 1) { printf("0"); }
	else if (abs(stud_time - tot_time) == 1) { 
		if (stud_time > tot_time && (stud_min+60-tot_min<10)) {
			printf("1");
		}
		else if (stud_time < tot_time && (tot_min + 60 - stud_min < 10)) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	else {
		if (abs(tot_min - stud_min) <= 10) {
			printf("1");
		}
		else {
			printf("0");
		}
	}

	return 0;
}