#include <iostream>
#include <vector>
using namespace std;

vector<int> DP(1000001);

void solution() {  //1463 1로 만들기
    int N; cin >> N;

    DP[0] = 0;
    DP[1] = 0;
    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + 1;
        if (i % 3 == 0) {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }
        if (i % 2 == 0) {
            DP[i] = min(DP[i], DP[i / 2] + 1);
        }   
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