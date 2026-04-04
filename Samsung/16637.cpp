/*
BOJ No.16637
괄호 추가하기
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> tmp;
queue<int> q;

void DFS(string &op, int start, unordered_map<int,bool> &um, long long &result) {
	
	long long sum = 0;
	for (int i = 0; i < op.size(); i = i + 2) {
		if (um[i]) {
			q.push(i);
			int a = op[i] - '0';
			int b = op[i + 2] - '0';
			int c;

			if (op[i + 1] == '+') {
				c = a + b;
			}
			else if (op[i + 1] == '-') {
				c = a - b;
			}
			else if (op[i + 1] == '*') {
				c = a * b;
			}
			tmp.push_back(c);
		}
	}

	int idx = 0;
	for (int i = 0; i < op.size(); i=i+2) {
		int a;
		bool check = false;
		if (!q.empty() && q.front() == i) {
			q.pop();
			a = tmp[idx];
			idx++;
			check = true;
		}
		else {
			a = op[i] - '0';
		}

		if (i == 0) {
			sum += a;
		}
		else {
			if (op[i - 1] == '+') {
				sum += a;
			}
			else if (op[i - 1] == '-') {
				sum -= a;
			}
			else if (op[i - 1] == '*') {
				sum *= a;
			}
		}
		if (check) {
			i += 2;
		}
	}
	result = max(sum, result);
	tmp.clear();
	while (!q.empty()) {
		q.pop();
	}

	for (int i = start; i < (int)op.size()-2; i++) { // .size() 함수는 unsigned int를 반환한다.
		um[i] = true;
		DFS(op, start+4, um, result);
		um[i] = false;
	}
}

int main() {
	int N;
	cin >> N;

	string op;
	unordered_map<int, bool> um; // 괄호가 걸렸는지 체크
	cin >> op;

	long long result = -9999999999;

	DFS(op, 0, um, result);
	cout << result;
}
