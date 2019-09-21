#include <string>
#include<iostream>
using namespace std;
int solution(string dirs)
{
	int answer = 7;
	int map[11][11][11][11] = { 0, };
	int len,cx=5,cy=5,x=5,y=5,cnt=0,i=0;
	len = dirs.length();
	while (len > 0) {
		switch (dirs[i])
		{
		case 'U':
			if(cy>0){
				y = cy;
				x = cx;
				cy--;
			}
			break;
		case 'D':
			if (cy < 10) {
				y = cy;
				x = cx;
				cy++;
			}
			break;
		case 'L':
			if(cx>0){
				x = cx;
				y = cy;
				cx--;
			}
			break;
		case 'R':
			if (cx < 10) {
				x = cx;
				y = cy;
				cx++;
			}
			break;
		default:
			cout << "error" << endl;
			break;
		}
		//cout<<cy<<" "<<cx<<" "<<y<<" "<<x<<" "<<cnt<<endl;
		if (!map[cy][cx][y][x]) {//first visit
			map[cy][cx][y][x] = 1;
			map[y][x][cy][cx] = 1;
			cnt++;
		}
		else if (map[cy][cx][y][x]) {//aleady passed
			
		}	
		len--;
		i++;
	}
	//cout << cnt << endl;
	answer = cnt;
	return answer;
}
int main() {
	string a1 = "ULURRDLLU",a2="LULLLLLLU";
	solution(a1);
	//solution(a2);
	return 1;
}