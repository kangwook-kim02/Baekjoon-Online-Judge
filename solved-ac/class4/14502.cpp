/*
BOJ No.14502
연구소
*/
#include <iostream>
#include <vector>

using namespace std;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

void DFS(vector<vector<int>> &map, vector<vector<bool>> &visit, int start_i, int start_j) {
	visit[start_i][start_j] = true;
	if (map[start_i][start_j] == 0) map[start_i][start_j] = 2;

	for (int i = 0; i < 4; i++) {
		int new_i = start_i + di[i];
		int new_j = start_j + dj[i];
		if (new_i >= 0 && new_i < map.size() && new_j >= 0 && new_j < map[0].size()&& map[new_i][new_j] != 1 && !visit[new_i][new_j]) {
			DFS(map, visit, new_i, new_j);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> _map(n, vector<int>(m, -1));
	vector<pair<int, int>> posOf0;
	vector<pair<int, int>> posOf2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 0) posOf0.push_back({ i,j });
			if (_map[i][j] == 2) posOf2.push_back({ i,j });
		}
	}

	/*
	Brute-Force
	*/
	int result = 0;
	for (int i = 0; i < posOf0.size(); i++) {
		for (int j = i + 1; j < posOf0.size(); j++) {
			for (int k = j + 1; k < posOf0.size(); k++) {
				vector<vector<int>> temp_map = _map;
				vector<vector<bool>> visit(n, vector<bool>(m, false));

				// 벽 세우기
				temp_map[posOf0[i].first][posOf0[i].second] = 1;
				temp_map[posOf0[j].first][posOf0[j].second] = 1;
				temp_map[posOf0[k].first][posOf0[k].second] = 1;

				// DFS
				for (int l = 0; l < posOf2.size(); l++) {
					int start_i = posOf2[l].first;
					int start_j = posOf2[l].second;
					if (temp_map[start_i][start_j] == 2 && !visit[start_i][start_j]) {
						DFS(temp_map, visit, start_i, start_j);
					}
				}

				// 개수 구하기
				int cnt = 0;
				for (int l = 0; l < n; l++) {
					for (int o = 0; o < m; o++) {
						if (temp_map[l][o] == 0) cnt++;
					}
				}
				result = max(result, cnt);

			}
		}
	}
	cout << result;
}
