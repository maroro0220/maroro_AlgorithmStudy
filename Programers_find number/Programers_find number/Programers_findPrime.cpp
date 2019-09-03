#include <string>
#include<stdlib.h>
#include <vector>
#include<stdio.h>
#include <iostream>
using namespace std;
//vector<char> numbers;
string str_in,stmp;
int cnt;
int visit[9999999];
int prime[9999999];
void dfs(int len, int select);
int change(string chnum);
/*
bool chk_Prime(string chP) {
	bool ret = true;
	int ch_st=change(chP);
	for (int a = 2; a < ch_st; a++) {
		if (ch_st % a == 0) {
			ret = false;
		}//end if
	}//end for chk Prime
	return ret;
}*/
int solution(string numbers) {
	int answer = 0;
	cnt = 0;
	for (int i = 1; i <=numbers.size(); i++) {
		dfs(i,0);

	}
	//str_in=numbers;

	answer = cnt;
	return answer;
}
int change(string chnum) {
	int change_tmp;
	change_tmp = atoi(chnum.c_str());
	return change_tmp;
}
void dfs(int len, int select) {
	//int ch_stmp = change(str_in);
	if (len == select) {//len is numbers length, select is selected number length
		int ch_stmp = change(stmp);
		if (ch_stmp == 1 ||ch_stmp==0) return;
		bool isPrime = true;
		for (int a = 2; a < ch_stmp; a++) {
			if (ch_stmp % a == 0) {
				isPrime = false;
			}//end if
		}//end for chk Prime
		if (isPrime) {
			if(!prime[ch_stmp]){
				prime[ch_stmp] = 1;
				printf("%d\n", ch_stmp);
				cnt++;
			}
		}//end if
	}//end if (len == select)
	for (int i = 0; i < str_in.size(); i++) {
		//if(!visit[str_in.at(i)])
		if(!visit[i])
		{
			stmp.push_back(str_in.at(i));
			//printf("stmp:%s\n", stmp.c_str());
			//visit[str_in.at(i)] = 1;
			//visit[atoi(stmp.c_str())] = 1;
			visit[i] = 1;
			dfs(len, i+1);
			//visit[str_in.at(i)] = 0;
			//visit[atoi(stmp.c_str())] = 0;
			visit[i] = 0;
			stmp.pop_back();
		}
		
	}//end for len

}
int main() {
	char tmp;
//	string tmp_str;
/*	
while(1){
		scanf("%c", &tmp);
		numbers.push_back(tmp);
		if (tmp <'0' || tmp>'9') { 
			numbers.pop_back();
			break; 
		}
	}*/
	  cin >> str_in;
	//	numbers.push_back(tmp_str);
	//  printf("%d", str_in.size());
	
	printf("ans:%d", solution(str_in));

	return 0;
}