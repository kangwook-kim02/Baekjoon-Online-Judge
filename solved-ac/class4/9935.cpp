/*
BOJ No.9935
문자열 폭발
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string explosion;
	cin >> str >> explosion;
	
	string result = "";
	for (int i = 0; i < str.size(); i++) {
		result += str[i];
		
		bool same = true;
		if (result.size() >= explosion.size()) {
			
			for (int j = 0; j < explosion.size(); j++) {
				if (explosion[j] != result[result.size() - explosion.size() + j]) {
					same = false;
					break;
				}
			}
			if (same) {
				for (int i = 0; i < explosion.size(); i++) {
					result.pop_back();
				}
			}
		}
	}

	if (result.size() == 0) {
		cout << "FRULA";
	}
	else {
		cout << result;
	}
}
