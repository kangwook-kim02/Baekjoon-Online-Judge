/*
BOJ No. 2667
단지번호붙이기
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void DFS(int start_i, int start_j, vector<vector<int>>& v, vector<vector<int>>& visit, int& count) {
	visit[start_i][start_j] = 0;
	count++;
	for (int i = 0; i < 4; i++) {
		int new_i = start_i + dx[i];
		int new_j = start_j + dy[i];
		if (new_i >= 0 && new_i < v.size() && new_j >= 0 && new_j < v.size()) {
			if (v[new_i][new_j] == 1 && visit[new_i][new_j] == -1) {
				DFS(new_i, new_j, v, visit, count);
			}
		}
	}

}

int main() {

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	vector<vector<int>> visit(n);
	for (int i = 0; i < n; i++) {
		string apart;
		cin >> apart;
		for (int j = 0; j < n; j++) {
			v[i].push_back(apart[j]-'0');
			visit[i].push_back(-1);
		}
	}

	vector<int> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1 && visit[i][j] == -1) {
				int count = 0;
				DFS(i, j, v, visit, count);
				result.push_back(count);
			}
		}
	}

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

}