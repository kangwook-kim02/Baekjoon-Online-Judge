/*
BOJ No.2170
선 긋기
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
		int x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}

	sort(v.begin(), v.end());

	
	int result = v[0].second - v[0].first;
	int threshold = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first >= threshold) {
			result = result + v[i].second - v[i].first;
			threshold = v[i].second;
		}
		else {
			if (v[i].second <= threshold) continue;
			else {
				result = result + v[i].second - threshold;
				threshold = v[i].second;
			}
		}
	}
	cout << result;

}
