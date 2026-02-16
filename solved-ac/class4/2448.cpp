/*
BOJ No.2448
별 찍기 - 11
*/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<char>>& arr, int i, int j, int size) {
	// 별 삽입
	if (size == 3) {
		arr[i][j] = '*';

		arr[i + 1][j - 1] = '*';
		arr[i + 1][j + 1] = '*';

		arr[i + 2][j - 2] = '*';
		arr[i + 2][j - 1] = '*';
		arr[i + 2][j] = '*';
		arr[i + 2][j + 1] = '*';
		arr[i + 2][j + 2] = '*';
		return;
	}


	solve(arr, i, j, size / 2);
	solve(arr, i + size / 2, j - size / 2, size / 2);
	solve(arr, i + size / 2, j + size / 2, size / 2);
}

int main() {
	int n;
	cin >> n;
	
	// n행, 2*n - 1 열
	vector<vector<char>> arr(n, vector<char>(2 * n - 1, ' '));
	solve(arr, 0, n - 1, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
