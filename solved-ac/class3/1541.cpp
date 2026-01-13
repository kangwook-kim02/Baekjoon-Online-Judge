/*
baekjoon 1541¹ø
silver 2
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string value;
	cin >> value;

	vector<string> token;
	vector<char> op;
	int result = 0;
	int idx = 0;
	for (int i = 0; i < value.size(); i++) {
		if (value[i] == '+') {
			token.push_back(value.substr(idx, i -idx));
			token.push_back("plus");
			idx = i + 1;
		}
		else if (value[i] == '-') {
			token.push_back(value.substr(idx, i - idx));
			token.push_back("minus");
			idx = i + 1;
		}
		
		if (i == value.size() - 1) {
			token.push_back(value.substr(idx, i - idx+1));
		}
	}

	for (int i = 0; i < token.size(); i++) {
		if (i == 0) {
			result = result + stoi(token[i]);
			continue;
		}

		if (token[i] == "minus") {
			int sum = 0;
			i++;
			while (1) {
				sum = sum + stoi(token[i]);
				if (i >= token.size() - 1) {
					result = result - sum;
					break;
				}

				if (token[i + 1] == "plus") {
					i = i + 2;
					
				}
				else if (token[i + 1] == "minus") {
					result = result - sum;
					break;
				}
			}
		}
		else {
			i++;
			result = result + stoi(token[i]);
		}

	}
	
	cout << result;

}