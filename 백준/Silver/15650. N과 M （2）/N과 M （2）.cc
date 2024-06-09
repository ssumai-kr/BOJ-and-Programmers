#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

int n, m;
int arr[MAX] = { 0, };

void dfs(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++) {
		arr[depth] = i;
		dfs(i + 1, depth + 1);
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}
