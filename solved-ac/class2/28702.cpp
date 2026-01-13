/*
baekjoon No.28702
tier: bronze1
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string a[3];

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	int idx = 0;
	int num;
	for (int i = 0; i < 3; i++) {
		if (a[i][0] != 'F' && a[i][0] != 'B') {
			idx = i;
			num = stoi(a[i]);
		}
	}
	
	num = num + 3 - idx;

	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0 && num % 5 != 0) {
		cout << "Fizz";
	}
	else if (num % 3 != 0 && num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}


}