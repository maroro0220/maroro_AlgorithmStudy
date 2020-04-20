
#include<iostream>

using namespace std;
struct POSI{
	int x=1, y=1;
};
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//x,y=141
	cin >> T;
	int arr[284][284] = { 0, };
	int num = 1;
	for (int i = 1; i <284; i++) {
		int x = 1;
		for (int j = i; j >0; j--) {
			arr[j][x] = num;
			num ++;
			x++;
		}
	}
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int a, b;
		cin >> a >> b;
		POSI a_po, b_po;
		bool ac=false, bc = false;
		for (int i = 1; i < 284; i++) {
			if (!ac && a > (((i + 1) * i) / 2) && a <= ((((i + 1) + 1) * (i + 1)) / 2)) {
				int num = (((i + 1) * i) / 2) + 1;
				int idx = 1;
				for (int j = i + 1; j > 0; j--) {
					if (num == a) {
						a_po.x = idx;
						a_po.y = j;
						ac = true;
						break;
					}
					idx++;
					num++;
				}
			}
			if (!bc && b > (((i + 1) * i) / 2) && b <= ((((i + 1) + 1) * (i + 1)) / 2)) {
				int num = (((i + 1) * i) / 2) + 1;
				int idx = 1;
				for (int j = i + 1; j > 0; j--) {
					if (num == b) {
						b_po.x = idx;
						b_po.y = j;
						bc = true;
						break;
					}
					idx++;
					num++;
				}
			}
			if (ac && bc) {
				break;
			}
		}
		printf("#%d %d\n", test_case, arr[a_po.y + b_po.y][a_po.x + b_po.x]);
		


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}