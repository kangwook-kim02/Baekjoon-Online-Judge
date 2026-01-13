/*
baekjoon 15829
Bronze 2
Hashing
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int M = 1234567891;
	int r = 31;

	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	unordered_map<char, int> um;

	for (int i = 0; i < alphabet.length(); i++) {
		um[alphabet[i]] = i + 1;
	}

	int l;
	cin >> l;

	string input;
	cin >> input;

	long long int sum = 0;
	long long int a = 0;
	for (int i = 0; i < l; i++) {
		a = um[input[i]];
		for (int j = 0; j < i; j++) {
			a = a * r;
			if (a > 1234567891) {
				a = a % 1234567891; // sum이 너무 큰 숫자를 갖게 될 경우
			}
		}
		sum = sum + a;
	}

	cout << sum % M;
}