// 11724

#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &v, vector<int> &visited, int k) {
	visited.push_back(k);
	
	for (int i = 1; i < v[k].size(); i++) {
		int check = 0;
		for (int j = 0; j < visited.size(); j++) {
			if (v[k][i] == visited[j]) { 
				check++;
				break;
			}
		}

		if (check == 0) {
			DFS(v, visited, v[k][i]);
		}
	}
}

int main() {
	int vertexNum, EdgeNum;
	cin >> vertexNum >> EdgeNum;
	vector<vector<int>> v;

	for (int i = 0; i <= vertexNum; i++) {
		vector<int> tmp;
		tmp.push_back(0);
		v.push_back(tmp);
	}

	int src, dst;
	vector<int> visited;
	for (int i = 0; i < EdgeNum; i++) {
		cin >> src >> dst;
		v[src].push_back(dst);
		v[dst].push_back(src);
	}

	int answer = 0;
	for (int i = 1; i <= vertexNum; i++) {
		int check = 0;
		for (int j = 0; j < visited.size(); j++) {
			if (i == visited[j]) {
				check++;
				break;
			}
		}
		if (check == 0) {
			DFS(v, visited, i);
			answer++;
		}
	}

	cout << answer << "\n";


}