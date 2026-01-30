/*
BOJ No.1991
트리순회
*/
#include <iostream>
#include <vector>

using namespace std;

void preorderTraversal(vector<vector<int>>& graph, int current) {
	// ASCII 코드를 활용한 출력
	cout << char(current + 65);

	// .은 아스키코드상 13이고 13-65를 빼면 음수이므로 0의 대소로 자식의 유무 판단 가능
	if (graph[current][0] > 0) { // 왼쪽 자식이 존재하면
		preorderTraversal(graph, graph[current][0]);
	}
	if (graph[current][1] > 0) { // 오른쪽 자식이 존재하면
		preorderTraversal(graph, graph[current][1]);
	}
}

void inorderTraversal(vector<vector<int>>& graph, int current) {
	if (graph[current][0] > 0) { 
		inorderTraversal(graph, graph[current][0]);
	}
	cout << char(current + 65);
	if (graph[current][1] > 0) { 
		inorderTraversal(graph, graph[current][1]);
	}
}

void postorderTraversal(vector<vector<int>>& graph, int current) {
	if (graph[current][0] > 0) {
		postorderTraversal(graph, graph[current][0]);
	}
	if (graph[current][1] > 0) {
		postorderTraversal(graph, graph[current][1]);
	}
	cout << char(current + 65);
}

int main() {
	int n;
	cin >> n;
	// A == 0, B == 1, C == 2 ...
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		char u, left, right;
		cin >> u >> left >> right;
		graph[int(u - 'A')].push_back(int(left - 'A'));
		graph[int(u - 'A')].push_back(int(right - 'A'));
	}

	preorderTraversal(graph, 0);
	cout << "\n";
	inorderTraversal(graph, 0);
	cout << "\n";
	postorderTraversal(graph, 0);
}
