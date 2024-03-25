#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Graph {
private:
	vector<vector<int>> idx;
	vector<vector<bool>> visited;
	vector<int> houses;
	int N;
	int cnt = 0;
	int count = 0;
public:
	Graph(int N) : idx(N, vector<int>(N, 0)), visited(N, vector<bool>(N, false)), N(N) {}

	void add(int i, int j) {
		idx[i][j] = 1;
	}
	void DFS(int i , int j, vector<vector<bool>>& visited) {
		visited[i][j] = true;

		if (i - 1 >= 0 && idx[i - 1][j] == 1 && !visited[i - 1][j]) {
			DFS(i - 1, j, visited);
		}
		if (i + 1 < N && idx[i + 1][j] == 1 && !visited[i + 1][j]) {
			DFS(i + 1, j, visited);
		}
		if (j - 1 >= 0 && idx[i][j - 1] == 1 && !visited[i][j - 1]) {
			DFS(i, j - 1, visited);
		}
		if (j + 1 < N && idx[i][j + 1] == 1 && !visited[i][j + 1]) {
			DFS(i, j + 1, visited);
		}
		idx[i][j] = 0;
		count++;
	}
	void solution() {
		for (int i = 0; i < N; i++) {
			string temp = "";
			cin >> temp;
			for (int j = 0; j < N; j++) {
				if (temp[j] == '1') {
					add(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (idx[i][j] == 1) {
					DFS(i, j, visited);
					cnt++;
					houses.push_back(count);
					count = 0;
				}
			}
		}
		sort(houses.begin(), houses.end());
		cout << cnt << '\n';
		for (int i = 0; i < houses.size(); i++) {
			cout << houses[i] << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	Graph run(N);

	run.solution();

	return 0;
}