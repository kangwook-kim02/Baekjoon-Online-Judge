/*
BOJ No.30805
사전 순 최대 공통 부분 수열
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int M;
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	vector<int> C;
	vector<int> D;
	if (N > M) {
		C = B;
		D = A;
	}
	else {
		C = A;
		D = B;
	}

	stack<pair<int,int>> stk; // (value,index) 
	for (int i = 0; i < C.size(); i++) {
		for (int j = 0; j < D.size(); j++) {
			if (C[i] == D[j]) {
				stack<pair<int, int>> tmp;

				// 큰 값을 넣기 전 다 빼버리기
				while (!stk.empty() && stk.top().first < C[i]) {
					tmp.push({ stk.top().first, stk.top().second });
					stk.pop();
				}

				if (stk.empty()) {
					stk.push({ C[i],j });
					break;
				}
				
				if (stk.top().second < j) {
					stk.push({ C[i],j });
					break;
				}

				while (!tmp.empty()) {
					stk.push({ tmp.top().first,tmp.top().second });
					tmp.pop();
				}
			}
		}
	}

	cout << stk.size() << "\n";
	stack<int> stk_reverse;
	while (!stk.empty()) {
		stk_reverse.push(stk.top().first);
		stk.pop();
	}
	while (!stk_reverse.empty()) {
		cout << stk_reverse.top() << " ";
		stk_reverse.pop();
	}
}
