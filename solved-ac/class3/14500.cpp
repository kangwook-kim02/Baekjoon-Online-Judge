/*
BOJ No.14500
테트로미노
*/
/*
4개의 블록의 연결성을 물어보고 있기 때문에
DFS로 풀 수 있음
--> DFS로 풀려고 했더니, ㅗ ㅓ ㅏ ㅜ 모양이 처리가 안됨
--> 그렇다고, BFS로 풀려고 하자니 다른 모양은 어떻게 처리를 해야할지..
// ㅗ ㅓ ㅏ ㅜ 모양 따로 처리하기
*/
#include <iostream>
#include <vector>

using namespace std;
int maxNum = 0;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void DFS(int idx, int jdx,vector<vector<int>> &graph,vector<vector<bool>> &visit , int depth, int sum) {
	visit[idx][jdx] = true;
	sum = sum + graph[idx][jdx];
	
	if (depth == 3) {
		maxNum = max(maxNum, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int new_i = idx + dx[i];
		int new_j = jdx + dy[i];
		if (new_i >= 0 && new_i < graph.size() && new_j >= 0 && new_j < graph[0].size() &&
			visit[new_i][new_j] == false) {
			DFS(new_i, new_j, graph, visit, depth + 1, sum);
			/*
			DFS가 끝났을 때 false로 바꿔야함
			왜냐하면 다른 순회에서 new_i, new_j를 방문했다면 방문을 하지 않음
			*/
			visit[new_i][new_j] = false; 
		}
	}
	// 아래 코드가 핵심인데
	// 저 로직이 없으면 ㄱ 과 같은 테르로미노 모양이 안만들어 질 수 있음
	// 따라서 모든 visit 함수를 false로 바꿔주어야함
	visit[idx][jdx] = false; 
}

// ㅗ ㅓ ㅏ ㅜ 모양처리
void solve(int i, int j, vector<vector<int>> &graph) {
	// ㅏ
	if (i - 1 >= 0 && i + 1 < graph.size() && j + 1 < graph[0].size()) {
		maxNum = max(maxNum, graph[i][j] + graph[i - 1][j] + graph[i + 1][j] + graph[i][j + 1]);
	}
	// ㅓ
	if (j - 1 >= 0 && i - 1 >= 0 && i + 1 < graph.size()) {
		maxNum = max(maxNum, graph[i][j] + graph[i][j - 1] + graph[i - 1][j] + graph[i + 1][j]);
	}
	// ㅗ
	if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < graph[0].size()) {
		maxNum = max(maxNum, graph[i][j] + graph[i][j - 1] + graph[i][j + 1] + graph[i - 1][j]);
	}
	// ㅜ
	if (j - 1 >= 0 && j + 1 < graph[0].size() && i + 1 < graph.size()) {
		maxNum = max(maxNum, graph[i][j] + graph[i][j - 1] + graph[i][j + 1] + graph[i + 1][j]);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N, vector<int>(M, 0));
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			DFS(i,j,graph,visit ,0, 0);
			solve(i, j, graph);
			// visit 값 초기화
		}
	}

	cout << maxNum;
}
