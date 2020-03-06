
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,N;

		cin >> N;
		//vector<int> arr(N+1);
		
		for (int i = 1; i <= N; i++) {
			if (i < 10) {
				if (!(i % 3)) {
					printf("- ");
				}
				else printf("%d ", i);
			}
			else if (i >= 10 && i < 100) {
				int ten = i / 10;
				int num = i % 10;
				bool chk = true;
				if (!(ten % 3)) {
					printf("-");
					chk = false;
				}
				if (!(num % 3) && num) {
					printf("-");
					chk = false;
				}
				if(chk) printf("%d", i);
				printf(" ");
			}
			else if (i >= 100 && i < 1000) {
				int hun = i / 100;
				int ten = i / 10;
				int num = i % 10;
				bool chk = true;
				if (!(hun % 3)) {
					printf("-");
					chk = false;
				}
				if (!(ten % 3)) {
					printf("-");
					chk = false;
				}
				if (!(num % 3)&&num) {
					printf("-");
					chk = false;
				}
				if(chk) printf("%d", i);
				printf(" ");
			}
			else if (i == 1000) {
				printf("1000");
			}
		}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}