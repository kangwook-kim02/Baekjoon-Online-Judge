/*
BOJ NO.11403
경로 찾기
*/
#include <iostream>
#include <vector>
using namespace std;


void DFS(int start, vector<vector<int>> &graph, vector<int> &visited, int depth) {
	if (depth > 0) visited[start] = 0;
	for (int i = 0; i < graph.size(); i++) {
		if (graph[start][i] == 1 && visited[i] == -1) {
			DFS(i, graph, visited, depth+1);
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> graph(n);
	vector<int> visited(n);
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			graph[i].push_back(num);
		}
	}

	vector<vector<int>> result(n);

	for (int i = 0; i < n; i++) {
		// visited 초기화
		for (int j = 0; j < n; j++) {
			visited[j] = -1;
		}
		DFS(i, graph, visited, 0);
		
		for (int j = 0; j < n; j++) {
			if (visited[j] == 0) {
				result[i].push_back(1);
			}
			else {
				result[i].push_back(0);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}