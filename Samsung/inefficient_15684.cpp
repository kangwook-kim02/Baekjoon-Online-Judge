/*
BOJ No.15684
사다리 조작
*/
#include <iostream>
#include <vector>

using namespace std;

bool SearchLadder(int H, int N, vector<vector<int>> &Graph) {
	// 모든 세로 선 검사
	for (int i = 1; i <= N; i++) {
		int height = 1;
		int jdx = i;
		while (height <= H) {
			if (Graph[height][jdx] != -1) {
				jdx = Graph[height][jdx];
				height++;
				continue;
			}

			if (Graph[height][jdx] == -1) {
				height++;
			}
		}
		if (jdx != i) return false;
	}
	return true;
}

bool bruteforce(int H, int N, vector<vector<int>> &Graph, int cnt, int s_idx, int s_jdx) {
	for (int i = s_idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == s_idx && j <= s_jdx) continue;
			if (Graph[i][j] == -1 && j+1 <= N && Graph[i][j+1] == -1) {		
				Graph[i][j + 1] = j;
				Graph[i][j] = j + 1;
				if (SearchLadder(H, N, Graph)) {
					cout << cnt;
					return true;
				}
				Graph[i][j + 1] = -1;
				Graph[i][j] = -1;
			}
		}
	}
	return false;
}

bool bruteforce2(int H, int N, vector<vector<int>> &Graph, int cnt, int s_idx, int s_jdx) {
	for (int i = s_idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == s_idx && j <= s_jdx) continue;
			if (Graph[i][j] == -1 && j+1 <= N && Graph[i][j+1] == -1) {
				Graph[i][j + 1] = j;
				Graph[i][j] = j + 1;
				if (bruteforce(H, N, Graph, cnt, i, j)) {
					return true;
				}
				Graph[i][j + 1] = -1;
				Graph[i][j] = -1;
			}
		}
	}
	return false;
}

int main() {
	int N, M, H;
	cin >> N >> M >> H;

	vector<vector<int>> Graph(H + 1, vector<int>(N + 1, -1));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a][b] = b + 1;
		Graph[a][b + 1] = b;
	}

	int cnt = 0;

	if (SearchLadder(H, N, Graph)) {
		cout << cnt;
		return 0;
	}

	cnt++;
	if (bruteforce(H, N, Graph, cnt, 1, 0)) {
		return 0;
	}

	cnt++;
	if (bruteforce2(H, N, Graph, cnt, 1, 0)) {
		return 0;
	}

	cnt++;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (Graph[i][j] == -1 && j + 1 <= N && Graph[i][j + 1] == -1) {
				Graph[i][j + 1] = j;
				Graph[i][j] = j + 1;
				if (bruteforce2(H, N, Graph, cnt, i, j)) {
					return 0;
				}
				Graph[i][j + 1] = -1;
				Graph[i][j] = -1;
			}
		}
	}

	cout << -1;
	

}
