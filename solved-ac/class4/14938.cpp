/*
BOJ No.14938
서강그라운드
*/

/*
처음 풀이 DFS 실패
DFS로 할 경우 visit한 노드는 절대 다시 방문하지 않으므로 그 뒤로 문제가 생길 수 있음.
따라서 다익스트라 n번 돌려서 거리가 m미만이면 방문하는 걸로 해야할 듯
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<bool>& visit, vector<int>& dist) {
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int node = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (visit[node]) continue;
		visit[node] = true;

		for (int i = 0; i < graph[node].size(); i++) {
			if (dist[graph[node][i].first] > curDist + graph[node][i].second) {
				dist[graph[node][i].first] = curDist + graph[node][i].second;
				pq.push({ dist[graph[node][i].first] ,graph[node][i].first });
			}
		}
	}
}
int main() {
	int node, m, r;
	cin >> node >> m >> r;
	vector<vector<pair<int, int>>> graph(node+1);
	vector<int> item(node + 1, 0);

	for (int i = 1; i < item.size(); i++) {
		cin >> item[i];
	}

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back({ b,l });
		graph[b].push_back({ a,l });
	}

	int maxNum = 0;
	for (int i = 1; i <= node; i++) {
		vector<bool> visit(node + 1, false);
		vector<int> dist(node + 1, 987654321);
		Dijkstra(i, graph, visit, dist);
		int sum = 0;
		for (int i = 1; i < dist.size(); i++) {
			if (m >= dist[i]) {
				sum += item[i];
			}
		}
		maxNum = max(maxNum, sum);
	}

	cout << maxNum;

}
