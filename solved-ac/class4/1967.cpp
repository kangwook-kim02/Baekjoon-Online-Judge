/*
BOJ No.1967
트리의 지름
DFS를 n번 돌려서 최댓값 찾기
*/

#include <iostream>
#include <vector>

using namespace std;

int result = 0;

void DFS(int node, int curDepth, int edgeDistance, vector<vector<pair<int,int>>>& graph, vector<int>& visit) {
	visit[node] = true;

	result = max(result, curDepth + edgeDistance);

	for (int i = 0; i < graph[node].size(); i++) {
		if (!visit[graph[node][i].first]) DFS(graph[node][i].first, curDepth + edgeDistance, graph[node][i].second, graph, visit);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<vector<pair<int,int>>> graph(n + 1);
	vector<int> visit(n + 1, false);

	for (int i = 0; i < n-1; i++) {
		int p, c, e;
		cin >> p >> c >> e;
		graph[p].push_back({ c,e });
		graph[c].push_back({ p,e });
	}

	// n번 DFS 돌리기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[j] = false;
		}
		DFS(i, 0, 0, graph, visit);
	}

	cout << result;

}
