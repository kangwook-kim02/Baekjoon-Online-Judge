/*
BOJ No.5525
IOIOI
Sliding Window
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;

	int count = 0;
	
	int k = 0; // IOIÀÇ °³¼ö
	for (int i = 1; i + 1 < M;) {
		if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
			k++;
			if (k == N) {
				count++;
				k--;
			}
			i = i + 2;
		}
		else {
			k = 0;
			i++;
		}
	}

	cout << count;
	
}