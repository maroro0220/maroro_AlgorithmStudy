#include <string>
#include <vector>
#include<iostream>
#include <math.h>
using namespace std;

vector<vector<char>> carpet;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int sum = brown + red;
	int limit = (int)sqrt(sum);

	for (int i = 3; i <= limit; i++)
	{
		if (sum % i == 0)
		{
			int tmp = sum / i;
			//��ü ī�� ��,�Ʒ� row ����,������ col�� �����ϰ� ���ϸ� redŸ���� ������ ���´�.
			if ((tmp - 2) * (i - 2) == red)
			{
				answer.push_back(tmp);
				answer.push_back(i);
				break;
			}
		}
	}
	cout << answer[0] << ", " << answer[1] << endl;
	return answer;
}

int main() {
	solution(10, 2);//B,R => 4,3
	solution(8, 1);//B,R => 3,3
	solution(24, 24);//B,R => 48,6

	return 1;
}