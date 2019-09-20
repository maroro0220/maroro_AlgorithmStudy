#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<string>> tick;
vector<string> res;
int chk[10000];
int Cmp(string a, string b) {
	int cmpString = a.compare(b);
	if (cmpString == 0) {
		//same
		return 0;
	}
	else if (cmpString < 0) {
		//a first
		return -1;
	}
	else if (cmpString > 0) {
		//b first
		return 1;
	}

}
bool dfs(string from,int cnt) {
	//if (cnt == tick.size()) return;
		res.push_back(from);
	if (cnt == tick.size() ) {
		return true;
	}
	for (int i = 0; i < tick.size(); i++) {

		if (tick[i][0] ==from && chk[i]==0) {
			chk[i] = 1;
			//res.push_back(from);
			bool r=dfs(tick[i][1], cnt + 1);
			if (r) { 
				return true; 
			}
			chk[i] = 0;
			//break;

		}
	}
	res.pop_back();
	return false;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<int> icn;
	sort(tickets.begin(), tickets.end());
	res.clear();
	tick.clear();
	tick = tickets;
	/*
	for (int i = 0; i < tickets.size(); i++) {
		//cout<<tickets[i][0] <<" "<<tickets[i][1]<<endl;
		if (tickets[i][0]=="ICN") {
			res.push_back(tickets[i][0]);
			dfs(tickets[i][1], 0);
			break;
		}
	}
	*/
	dfs("ICN", 0);
	answer = res;
	
	for (int i = 0; i < res.size(); i++) {
		cout << res[i]<<"-";
		chk[i] = 0;
	}
	cout << endl;
	
	/*
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0].compare("ICN")==0) {
			ICN.push_back(i);
		}
	}
	if (ICN.size() > 1){
		int min_tmp=0;
		for (int i = 1; i < ICN.size(); i++) {
			if (Cmp(tickets[1][min_tmp], tickets[1][i]) == -1) {
				
			}
			else if (Cmp(tickets[1][min_tmp], tickets[1][i]) == 1) {

			}
		}
	}
	*/
	return answer;
}

int main() {
	vector<vector<string>> tic1 = { {"ICN","JFK"},{"HND", "IAD"},{"JFK", "HND"} }, tic2 = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} };
	vector<vector<string>> tic3={ { "ICN", "BOO" }, { "ICN", "COO" }, { "COO", "DOO" }, { "DOO", "COO" }, { "BOO", "DOO" }, { "DOO", "BOO" }, { "BOO", "ICN" }, { "COO", "BOO" } };
	//printf("%s\n", tic1[0][0]);
	//cout << tic1.size() <<" "<< tic1[0][0]<< endl;
	//tick = tic1;
	solution(tic1);
	//tick = tic2;
	solution(tic2);
	solution(tic3);
	
	return 1;

}
