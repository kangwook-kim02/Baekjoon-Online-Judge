/*
baekjoon 1676
silver 5
*/

#include <iostream>
using namespace std;

int main() {
	int two = 0;
	int five = 0;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num = i;
		int check_two = 0;
		int check_five = 0;
		while (check_two < 1 || check_five < 1) {
			if (num % 2 == 0) {
				two++;
				num = num / 2;
			}
			else {
				check_two++;
			}

			if (num % 5 == 0) {
				five++;
				num = num / 5;
			}
			else {
				check_five++;
			}
		}
	}

	if (two < five) {
		cout << two;
	}
	else {
		cout << five;
	}
	
}