/*
BOJ No.11501
주식
Greedy
*/
/*
문제 풀이
주식을 최대한 사고
주식이 최대로 오른날 팔면 최대 이득
그 날이 지나면 다시 계산을 한다.
*/
#include <iostream>
#include <vector>
using namespace std;


int main() {

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		int idx = 0; // 시작 인덱스
		long long result = 0; // 결과값
		while (idx < n) {
			int maxIdx = idx;
			for (int i = idx; i < n; i++) {
				if (v[i] >= v[maxIdx]) {
					maxIdx = i;
				}
			}

			// maxIdx에 변화가 없다면
			// logic 오류 필요 없음
			/*
			반례
			1
			3
			10 7 9
			0
			ans: 2
			*/
			/*if (maxIdx == idx) {
				break;
			}*/

			long long sum = 0;
			// 주식 총 구매 가격 계산5
			for (int i = idx; i < maxIdx; i++) {
				sum += v[i];
			}

			result += (maxIdx - idx) * v[maxIdx] - sum;
			idx = maxIdx + 1;
		}
		cout << result << "\n";
	}

}
