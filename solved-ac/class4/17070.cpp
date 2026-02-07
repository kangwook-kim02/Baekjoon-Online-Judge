/*
BOJ No.17070
파이프 옮기기 1
*/

/*
BFS 풀이라고 생각이 들음
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, pair<int, int>>> q;
int result = 0;

void solve(vector<vector<int>>& v) {
	while (!q.empty()) {
		pair<int, int> rear = q.front().first;
		pair<int, int> front = q.front().second;
		q.pop();

		if (front.first == v.size() - 1 && front.second == v.size() - 1) {
			result++;
			continue;
		}

		// 가로
		if (rear.first == front.first) {
			// 직진 가능 여부
			if (front.second + 1 < v.size() && v[front.first][front.second+1] == 0) {
				pair<int, int> newRear = { rear.first, rear.second + 1 };
				pair<int, int> newFront = { front.first, front.second + 1 };
				q.push({ newRear, newFront });
			}
			// 회전 가능 여부
			if (front.first + 1 < v.size() && front.second + 1 < v.size() && v[front.first][front.second+1] == 0 
				&& v[front.first + 1][front.second + 1] == 0 && v[front.first+1][front.second] == 0) {
				pair<int, int> newRear = { rear.first, rear.second + 1 };
				pair<int, int> newFront = { front.first + 1, front.second + 1 };
				q.push({ newRear, newFront });
			}
		}
		else if (rear.second == front.second) { // 세로
			// 직진 가능 여부
			if (front.first + 1 < v.size() && v[front.first + 1][front.second] == 0) {
				// 직진
				pair<int, int> newRear = { rear.first + 1, rear.second };
				pair<int, int> newFront = { front.first + 1, front.second };
				q.push({ newRear,newFront });
			}

			// 회전 가능 여부
			if (front.first + 1 < v.size() && front.second + 1 < v.size() && v[front.first][front.second+1] == 0 
				&& v[front.first + 1][front.second + 1] == 0 && v[front.first+1][front.second] == 0) {
				pair<int, int> newRear = { rear.first + 1, rear.second };
				pair<int, int> newFront = { front.first + 1, front.second + 1 };
				q.push({ newRear, newFront });
			}
		}
		else { // 대각선
			// 직진 가능 여부
			if (front.first + 1 < v.size() && front.second + 1 < v.size() && v[front.first][front.second + 1] == 0 
				&& v[front.first + 1][front.second + 1] == 0 && v[front.first + 1][front.second] == 0) {
				// 직진
				pair<int, int> newRear = { rear.first + 1, rear.second + 1 };
				pair<int, int> newFront = { front.first + 1, front.second + 1 };
				q.push({ newRear, newFront });
			}

			// 가로 회전 가능 여부
			if (front.second + 1 < v.size() && v[front.first][front.second + 1] == 0) {
				pair<int, int> newRear = { rear.first + 1, rear.second + 1 };
				pair<int, int> newFront = { front.first, front.second + 1 };
				q.push({ newRear, newFront });
			}

			// 새로 회전 가능 여부
			if (front.first + 1 < v.size() && v[front.first + 1][front.second] == 0) {
				pair<int, int> newRear = { rear.first + 1, rear.second + 1 };
				pair<int, int> newFront = { front.first + 1, front.second };
				q.push({ newRear,newFront });
			}
		}
	}

}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	pair<pair<int, int>, pair<int, int>> position = { {0,0},{0,1} };
	q.push(position);
	solve(v);
	cout << result;
	
}
