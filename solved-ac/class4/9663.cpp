/*
BOJ No.9663
N-Queen
*/
#include <iostream>
#include <vector>
using namespace std;

int result;

void solve(int queenNum, int n, vector<int> &v) {
	if (queenNum == n) {
		result++;
		return;
	}


	for (int i = 0; i < n; i++) {
		bool lay = true;
		for (int j = 0; j < queenNum; j++) {
			// i번째 자리에 퀸을 놓을 수 없다면
			if (i == v[j] || i == v[j] + (queenNum - j) || i == v[j] - (queenNum - j)) {
				lay = false;
				break;
			}
		}
		if (lay) {
			v[queenNum] = i; // i번째 퀸을 놓는다.
			solve(queenNum + 1, n, v);
		}
	}


}

int main() {
	int n;
	cin >> n;
	vector<int> v(n, -1);
	solve(0, n, v);
	cout << result;
}
