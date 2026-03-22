/*
BOJ No.1865
웜홀
벨만-포드 알고리즘 이용
음수 순환이 있으면 가능하므로, 음수 순환의 존재 여부를 파악한다.
*/
#include <iostream>
#include <vector>

using namespace std;

bool bellman_ford(int start, vector<vector<pair<int,int>>> &graph, vector<int> &dist) {
	dist[start] = 0;

	for (int i = 1; i < graph.size(); i++) { // node의 수만큼 반복을 하고, 매 반복마다 모든 edge를 확인한다.
		for (int j = 1; j < graph.size(); j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int src = j;
				int dst = graph[j][k].first;
				int cost = graph[j][k].second;

				// dist[src] != 987654321 조건 삭제
				// 시간초과가 안나면서 음수인 사이클 존재를 확인하기 위해선
				// 끊어져있는 그래프들도 확인을 해봐야한다. 위 조건이 있으면 start값에 종속되어 확인하지 못할 수 있음
				if (dist[dst] > dist[src] + cost) {
					dist[dst] = dist[src] + cost;
					if (i == graph.size() - 1) return true;
				}
			}
		}
	}

	return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<vector<pair<int, int>>> graph(n+1);
		vector<int> dist(n + 1, 987654321);
		for (int i = 0; i < m; i++) {
			int u, v, time;
			cin >> u >> v >> time;
			graph[u].push_back({ v,time });
			graph[v].push_back({ u,time });
		}

		for (int i = 0; i < w; i++) {
			int src, dst, time;
			cin >> src >> dst >> time;
			graph[src].push_back({ dst, -time });
		}

		bool travel = bellman_ford(1, graph, dist);

		if (travel) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}
