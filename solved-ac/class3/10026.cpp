/*
BOJ No.10026
적록 색약
*/
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void DFS (int idx, int jdx, vector<vector<char>>& graph, vector<vector<int>>& visit) {
	visit[idx][jdx] = 1;
	for (int i = 0; i < 4; i++) {
		int new_i = idx + dx[i];
		int new_j = jdx + dy[i];
		if (new_i >= 0 && new_i < graph.size() && new_j >= 0 &&
			new_j < graph.size() && visit[new_i][new_j] == -1 &&
			graph[idx][jdx] == graph[new_i][new_j]) {
			DFS(new_i, new_j, graph, visit);
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<char>> graph(N, vector<char>(N, '-1'));
	vector<vector<int>> visit(N, vector<int>(N, -1));
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			cin >> graph[i][j];
		}
	}

	// 일반인
	int normalCount = 0;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			if (visit[i][j] == -1) {
				DFS(i, j, graph, visit);
				normalCount++;
			}
		}
	}


	// 적록색약인 사람을 위한 전처리
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			if(graph[i][j] == 'G'){
				graph[i][j] = 'R';
			}
			visit[i][j] = -1;
		}
	}

	// 적록색약
	int abnormalCount = 0;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			if (visit[i][j] == -1) {
				DFS(i, j, graph, visit);
				abnormalCount++;
			}
		}
	}

	cout << normalCount << " " << abnormalCount;
}
