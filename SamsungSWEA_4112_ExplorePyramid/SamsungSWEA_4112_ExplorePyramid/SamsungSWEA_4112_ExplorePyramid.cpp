
#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int now, dest;
		scanf("%d %d", &now, &dest);
		int i = 1;
		int now_lev, dest_lev;
		int now_x, dest_x;
		bool nowchk = false, destchk = false;
		while (true) {
			if (now >= (1 + ((i - 1) * i) / 2) && now <= (i * (i +1)) / 2) {
				//now_x = now- (1 + ((i - 1) * i) / 2);
				now_x = (i * (i + 1)) / 2 - now;
				now_lev = i;
				nowchk = true;
			}
			if (dest >= (1 +((i - 1) * i) / 2) && dest <= (i * (i + 1)) / 2) {
				//dest_x = dest- (1 + ((i - 1) * i) / 2);
				dest_x = (i * (i + 1)) / 2 - dest;
				dest_lev = i;
				destchk = true;
			}
			if (destchk && nowchk) {
				break;
			}
			i++;
		}
		//if (dest_lev == now_lev) {
		//	printf("#%d %d\n", test_case, abs(dest - now));
		//}
		//else {
		if (dest_lev >= now_lev) {
			if ((dest_x - now_x)<0) {
				printf("#%d %d\n", test_case, abs(dest_lev - now_lev) + abs(dest_x - now_x));
			}
			else {
				printf("#%d %d\n", test_case, max(abs(dest_lev - now_lev),abs(dest_x - now_x)));
			}
		}
		else if (dest_lev < now_lev) {
			if (( now_x-dest_x) < 0) {
				printf("#%d %d\n", test_case, abs(dest_lev - now_lev) + abs(dest_x - now_x));
			}
			else {
				printf("#%d %d\n", test_case, max(abs(dest_lev - now_lev), abs(dest_x - now_x)));
			}
		}
		//}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}