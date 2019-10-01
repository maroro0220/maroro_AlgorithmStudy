#include<iostream>
using namespace std;

int main() {
	int A, B, tmp;
	//queue<int> a, b;
	//vector<int> a, b;

	cin >> A >> B;
	int* a = new int[A];
	int* b = new int[B];

	for (int i = 0; i < A; i++) {
		cin >> a[i];
		//a.push(tmp);
		//a.push_back(tmp);
	}
	for (int i = 0; i < B; i++) {
		cin >> b[i];
		//b.push(tmp);
		//b.push_back(tmp);
	}

	int aidx = 0, bidx = 0;
	while (aidx < A && bidx < B) {
		if (a[aidx] < b[bidx]) {
			//comb.push_back(a[aidx]);
			printf("%d ", a[aidx++]);
			//++aidx;
		}
		else {
			//comb.push_back(b[bidx]);
			printf("%d ", b[bidx++]);
			//++bidx;
		}

	}
	while (aidx < A) {
		printf("%d ", a[aidx++]);
	}
	while (bidx < B) {
		printf("%d ", b[bidx++]);
	}
	return 0;
}