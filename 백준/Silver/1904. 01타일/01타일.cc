#include <iostream>
#include <vector>
using namespace std;


void solution() { //1904번 01타일
	int N;
	cin >> N;
	vector<long long> DP(N + 1);
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
	}
	cout << DP[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}