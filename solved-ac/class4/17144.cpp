/*
BOJ No.17144
미세먼지 안녕!
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	int R, C, T;
	cin >> R >> C >> T;
	vector<vector<int>> v(R, vector<int>(C, 0));
	vector<int> airClearPos; // 공기 청정기의 위치

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> v[i][j];
			if (v[i][j] == -1) {
				airClearPos.push_back(i);
			}
		}
	}
	while (T--) {

		// 1번 동작
		queue<pair<int, int>> q;
		queue<int> value; // 동시에 확산이 일어남
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (v[i][j] != 0 && v[i][j] != -1) {
					q.push({ i,j });
					value.push({ v[i][j] });
				}
			}
		}

		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();

			int cnt = 0; // 확산된 방향의 수
			int A = value.front() / 5; // 확산 되는 양
			value.pop();

			for (int k = 0; k < 4; k++) {
				int new_i = i + dx[k];
				int new_j = j + dy[k];
				if (new_i >= 0 && new_i < R && new_j >= 0 && new_j < C &&
					v[new_i][new_j] != -1 ) {
					v[new_i][new_j] += A;
					cnt++;
				}
			}

			v[i][j] = v[i][j] - A * cnt;
		}

		// 2번 동작
		// 반시계 방향
		for (int i = airClearPos[0] - 1; i >= 0; i--) {
			if (i == airClearPos[0] - 1) {
				continue;
			}

			v[i + 1][0] = v[i][0];
		}
		for (int i = 0; i < C-1; i++) {
			v[0][i] = v[0][i + 1];
		}
		for (int i = 0; i <= airClearPos[0] -1; i++) {
			v[i][C - 1] = v[i + 1][C - 1];
		}
		for (int i = C - 1; i >= 1; i--) {
			if (i == 1) {
				v[airClearPos[0]][i] = 0;
				continue;
			}
			v[airClearPos[0]][i] = v[airClearPos[0]][i - 1];
		}

		// 시계 방향
		for (int i = airClearPos[1] + 1; i < R-1; i++) {
			v[i][0] = v[i + 1][0];
		}

		for (int i = 0; i < C-1; i++) {
			v[R - 1][i] = v[R - 1][i + 1];
		}

		for (int i = R - 1; i >= airClearPos[1]+1; i--) {
			v[i][C - 1] = v[i - 1][C - 1];
		}

		for (int i = C - 1; i >= 1; i--) {
			if (i == 1) {
				v[airClearPos[1]][i] = 0;
				continue;
			}
			v[airClearPos[1]][i] = v[airClearPos[1]][i - 1];	
		}
	}

	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (v[i][j] != -1) {
				sum += v[i][j];
			}
		}
	}

	cout << sum;
}
