/*
BOJ No.16953
A --> B
*/
/*
BFS로 풀어야함
visit을 이용하면
10^9+1 만큼의 공간이 필요한데, 이는 1GB를 초과한다.
따라서 다른 방안이 필요하며 STL set을 이용하자
-----
int 형을 쓰면 overflow가 발생해 무한 반복에 빠질 가능성이 존재하니
long long으로 변경하자
*/
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

long long a, b;
queue<long long> q;
unordered_map<long long, int> um;

void BFS() {
	while (!q.empty()) {
		long long num = q.front();
		q.pop();

		long long temp_num = num * 2;
		if (temp_num > b) continue;
		// 방문한 적이 없는 경우만
		if (um[temp_num] == 0) {
			um[temp_num] = um[num] + 1;
			q.push(temp_num);
			if (temp_num == b) return;
		}

		temp_num = num * 10 + 1;
		if (temp_num > b) continue;
		// 방문한적 없는 경우만
		if (um[temp_num] == 0) {
			um[temp_num] = um[num] + 1;
			q.push(temp_num);
			if (temp_num == b) return;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> a >> b;
	q.push(a);
	um[a] = 1;
	BFS();
	if (um[b] == 0) {
		cout << -1;
	}
	else {
		cout << um[b];
	}
}
