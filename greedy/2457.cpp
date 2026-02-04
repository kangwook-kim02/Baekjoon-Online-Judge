/*
BOJ No.2457
공주님의 정원
greedy
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		int s_month, s_date, d_month, d_date;
		cin >> s_month >> s_date >> d_month >> d_date;
		v[i].first = s_month * 100 + s_date;
		v[i].second = d_month * 100 + d_date;
	}

	// 꽃이 피는 날짜를 기준으로 정렬
	sort(v.begin(), v.end());

	int threshold = 301; // 처음 기준점
	int result = 0;
	bool notExist = false;
	while (threshold < 1201) {
    	// 기존 Threshold값을 저장해야 기준이 되는 점을 고정시킬 수 있음
		int prevThreshold = threshold;  
		for (int i = 0; i < n; i++) {
			if (v[i].first <= prevThreshold && v[i].second > threshold) { // 최대 threshold를 구하기 위해 뒤에 비교는 threshold를 기준으로
				threshold = v[i].second; // 만족하는 꽃이 존재하면 threshold 값을 update
			}
		}

		// threshold 값이 변경되지 않았다면 문제에 만족하는 꽃이 존재하지 않음
		if (prevThreshold == threshold) {
			notExist = true;
			break;
		}
		result++;
	}

	if (notExist) result = 0;
	cout << result;
	
	
}
