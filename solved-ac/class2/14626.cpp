/*
น้มุ 14626น๘ ISBN 
Bronze 1
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string num;
	cin >> num;

	int sum = 0;
	int d = 1;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '*') {
			if (i % 2 != 0) {
				d = 3;
			}
		}
		else {
			if (i == num.size() - 1) {
				int n = num[i] - '0';
				sum = sum + n;
			}
			else if (i % 2 == 0) {
				int n = num[i] - '0';
				sum = sum + n;
			}
			else {
				int n = num[i] - '0';
				sum = sum + (3 * n);
			}
		}
	}
	/* debug */
	//cout << "sum : " << sum << "\n";
	//cout << "result : " << 10 - (sum % 10) << "\n";

	int result = 10-(sum % 10);
	if (d == 3) {
		for (int i = 0; i <= 9; i++) {
			if ((sum + 3 * i) % 10 == 0) {
				cout << i;
				break;
			}
		}
	}
	else {
		cout << result;
	}
}