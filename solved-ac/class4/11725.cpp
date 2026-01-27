/*
BOJ No.11725
트리의 부모 찾기
*/

/*
풀이과정
1에서부터 시작해서 BFS 진행,
parent에 부모 정보 저장
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph(100001);
vector<bool> visit(100001, false);
vector<int> parentArr(100001, -1);
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) {
			if (!visit[graph[parent][i]]) {
				visit[graph[parent][i]] = true;
				q.push(graph[parent][i]);
				parentArr[graph[parent][i]] = parent;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	visit[1] = true;
	q.push(1);
	BFS();
	for (int i = 2; i <= n; i++) {
		cout << parentArr[i] << "\n";
	}
}
