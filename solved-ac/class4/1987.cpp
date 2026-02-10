/*
BOJ No.1987
알파벳
백트래킹, DFS
*/
#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int result = 0;
void DFS(int idx, int jdx, vector<bool>& visit, vector<vector<char>>& graph, int depth) {
	result = max(result, depth);
	
	visit[graph[idx][jdx] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int newIdx = idx + dx[i];
		int newJdx = jdx + dy[i];

		if (newIdx >= 0 && newIdx < graph.size()
			&& newJdx >= 0 && newJdx < graph[newIdx].size()
			&& !visit[graph[newIdx][newJdx] - 'A']) {
			DFS(newIdx, newJdx, visit, graph, depth + 1);
		}
	}
	visit[graph[idx][jdx] - 'A'] = false;
}

int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<char>> graph(r, vector<char>(c));
	vector<bool> visit(26, false);
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			cin >> graph[i][j];
		}
	}

	DFS(0, 0, visit, graph, 1);
	cout << result;
}
