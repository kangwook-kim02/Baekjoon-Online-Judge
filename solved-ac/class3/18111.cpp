/*
Boj no. 18111
MineCraft
*/

/*
풀이 과정 
bruteforce
근거 500*500*256 = 64,000,000 이므로 1초 연산안에 들어옴
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m, b;

	cin >> n >> m >> b;

	vector<vector<int>> v(n);
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < m; j++) {
			int h;
			cin >> h;
			v[i].push_back(h);
		}
	}

	int height = 256;
	int time = 987654321;
	int resultHeight = -1;
	while (height >= 0) {
		int tempBlock = b;
		int tempTime = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] > height) {
					tempBlock = tempBlock + (v[i][j] - height);
					tempTime = tempTime + 2 * (v[i][j] - height);
				}
				else if (v[i][j] < height) {
					tempBlock = tempBlock - (height - v[i][j]);
					tempTime = tempTime + 1 * (height - v[i][j]);
				}
			}
		}

		if (tempBlock >= 0) {
			if (tempTime < time) {
				time = tempTime;
				resultHeight = height;
			}
		}

		height--;
	}
	cout << time << " " << resultHeight;
}