/*
BOJ No.1439
뒤집기
Greedy
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int zeroSpace = 0;
	int oneSpace = 0;
	
	char pivot = s[0];
	if (pivot == '0') {
		zeroSpace++;
	}
	else {
		oneSpace++;
	}

	for (int i = 1; i < s.size(); i++) {
		if (s[i] != pivot) {
			pivot = s[i];
			if (pivot == '0') {
				zeroSpace++;
			}
			else {
				oneSpace++;
			}
		}
	}
	cout << min(zeroSpace,oneSpace);
}
