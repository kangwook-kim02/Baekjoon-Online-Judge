/*
BOJ No.15686
치킨 배달
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<pair<int, int>> chicken;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	// 현재 치킨 거리 계산
	int chickenDistance = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1) {
				int minDistance = 987654321;
				for (int k = 0; k < chicken.size(); k++) {
					int r = chicken[k].first - i;
					if (r < 0) r = -r;
					int c = chicken[k].second - j;
					if (c < 0) c = -c;

					minDistance = min(minDistance, r + c);
				}
				chickenDistance += minDistance;
			}
		}
	}

	/*
	치킨을 제거하는 모든 경우의 수를 계산하여
	최소 값을 저장한다.
	O((2500 + 100*13)2^13-m)
	*/
	while (chicken.size() > m) {
		
	}
	cout << chickenDistance;
	
}
