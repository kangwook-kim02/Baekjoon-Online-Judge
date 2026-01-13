/*
beakjoon 11659
silver 3
*/
#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	int m;

	cin >> n >> m;

	int* arr = new int[n];
	int* sum = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sum[0] = arr[0];
	for (int i =1; i < n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	int a;
	int b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a == 1) {
			cout << sum[b - 1] << "\n";
			continue;
		}
		
		cout << sum[b - 1] - sum[a - 2] << "\n";
	}
}