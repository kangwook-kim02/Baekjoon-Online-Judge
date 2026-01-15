/*
BOJ No.1389
케빈 베이컨의 6단계 법칙
플로이드 워셜 알고리즘
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int user, association;
	cin >> user >> association;

	vector<vector<int>> graph(user+1);
	vector<vector<int>> dist(user + 1);

	for (int i = 0; i < association; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int INF = 987654321;

	// dist 초기화
	for (int i = 1; i < dist.size(); i++) {
		for (int j = 0; j < dist.size(); j++) {
			if (i == j) {
				dist[i].push_back(0);
			}
			else {
				dist[i].push_back(INF);
			}
		}
	}

	for (int i = 1; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			dist[i][graph[i][j]] = 1;
		}
	}

	// 플로이드 워셜 알고리즘
	for (int k = 1; k < graph.size(); k++) { // 중간 지점
		for (int i = 1; i < graph.size(); i++) { // 출발 지점
			for (int j = 1; j < graph.size(); j++) { // 도착 지점
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		} 
	}

	vector<int> sum(user + 1);
	for (int i = 1; i < dist.size(); i++) {
		for (int j = 1; j < dist.size(); j++) {
			sum[i] += dist[i][j];
		}
	}
	int min = sum[1];
	int minIdx = 1;
	for (int i = 1; i < sum.size(); i++) {
		if (min > sum[i]) {
			min = sum[i];
			minIdx = i;
		}
	}
	cout << minIdx;
}