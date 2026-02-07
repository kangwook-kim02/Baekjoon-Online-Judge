/*
BOJ No.15686
치킨 배달
*/
#include <iostream>
#include <vector>

using namespace std;

int chickenDistance = 987654321;
/*
제거할 m개의 치킨 (brute-force)
*/
void solve(int depth,int start , vector<vector<int>> &v, vector<pair<int,int>>& chicken, vector<bool>& visit, int &del) {
	if (depth >= del) {
		int tempChickenDistance = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				if (v[i][j] == 1) {
					int minDistance = 987654321;
					// 치킨 거리 계산
					for (int k = 0; k < chicken.size(); k++) {
						if (!visit[k]) { // 제거할 치킨집이 아닌 경우
							int r = i - chicken[k].first;
							if (r < 0) r = -r;
							int c = j - chicken[k].second;
							if (c < 0) c = -c;
							minDistance = min(minDistance, r + c);
						}
					}
					tempChickenDistance += minDistance;
				}
				
			}
		}
		chickenDistance = min(chickenDistance, tempChickenDistance);
		return;
	}

	for (int i = start; i < chicken.size(); i++) {
		visit[i] = true;
		solve(depth + 1, i+1, v, chicken, visit, del);
		visit[i] = false;
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<pair<int, int>> chicken;
	vector<bool> visit(13, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	int del = chicken.size() - m;
	solve(0, 0, v, chicken, visit, del);
	cout << chickenDistance;

	
}
