/*
BOJ No.9019
DSLR
*/
/*
재귀 풀이를 생각해보았지만,
재귀로 풀이를 진행할 경우 스택이 쌓여 overflow가 발생할 가능성이 존재
--> 일단 완전 탐색 방식으로 가야할 것 같다는 생각을 했지만 정확한 알고리즘이 떠오르지 않음
--> 알고리즘 분류를 봤을 때, BFS로 분류되었음
--> BFS 풀이 진행
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int,char>> q;
vector<int> visit(10000); // q 중복문제 다루기
vector<pair<int,char>> node(1); // 부모의 id, 명령어
vector<char> result; // 결과

int a;
int b;

void BFS() {
	int id = 0;
	while (!q.empty()) {
		int num = q.front().first;
		char order = q.front().second;
		q.pop();
		id++;

		// 
		if (num == b) {
			while (id != 1) {
				result.push_back(node[id].second);
				id = node[id].first;
			}

			while (!q.empty()) {
				q.pop();
			}

			return;
		}

		// D
		int temp_num = num * 2;
		if (temp_num > 9999) temp_num = temp_num % 10000;
		if (visit[temp_num] == 0) {
			q.push({ temp_num ,'D' });
			node.push_back({ id,'D' });
			visit[temp_num] = 1;
		}
		// S
		temp_num = num - 1;
		if (temp_num == -1) temp_num = 9999;
		if (visit[temp_num] == 0) {
			q.push({ temp_num, 'S' });
			node.push_back({ id,'S' }); 
			visit[temp_num] = 1;
		}
		// L
		int d1 = num / 1000;
		int d2 = (num % 1000) / 100;
		int d3 = ((num % 1000) % 100) / 10;
		int d4 = ((num % 1000) % 100 % 10);
		temp_num = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
		if (visit[temp_num] == 0) {
			q.push({ temp_num, 'L' });
			node.push_back({ id,'L' });
			visit[temp_num] = 1;
		}
		// R
		temp_num = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
		if (visit[temp_num] == 0) {
			q.push({ temp_num, 'R' });
			node.push_back({ id,'R' });
			visit[temp_num] = 1;
		}

	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> a >> b;
		visit[a] = 1;
		q.push({a,'0'});
		node.push_back({-1,'0'});
		BFS();
		for (int i = result.size() - 1; i >= 0; i--) {
			cout << result[i];
		}
		cout << "\n";
		result.clear();
		node.clear();
		for (int i = 0; i < visit.size(); i++) {
			visit[i] = 0;
		}
		node.push_back({-1,'0'});
	}
}
