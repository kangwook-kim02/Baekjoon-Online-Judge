/*
BOJ No.11000
강의실 배정
Greedy
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		v[i] = { s,t };
	}
	sort(v.begin(), v.end());
	
	int result = 0;
	// 끝나는 시간이 제일 빠른 친구를 top으로 두는 우선순위 큐 --> 최소 힙
	priority_queue<int, vector<int>, greater<int>> pq; 
	for (int i = 0; i < n; i++) {
		while (!pq.empty()) {
			if (pq.top() <= v[i].first) {
				pq.pop();
			}
			else {
				break;
			}
		}
		pq.push(v[i].second);
		int size = pq.size();
		result = max(result,size); // 필요한 강의실 개수, 즉 겹치는 수업 시간의 최대 개수
	}
	cout << result;
}
