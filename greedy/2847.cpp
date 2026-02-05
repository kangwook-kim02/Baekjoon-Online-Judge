/*
BOJ No.2847
게임을 만든 동준이
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int result = 0;
	for (int i = n - 1; i > 0; i--) {
		if (v[i - 1] >= v[i]) {
			int diff = v[i - 1] - v[i] + 1;
			v[i - 1] = v[i - 1] - diff;
			result += diff;
		}
	}

	cout << result;
}
