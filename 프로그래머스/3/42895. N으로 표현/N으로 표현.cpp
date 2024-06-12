#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int getNS(int N, int idx) {
    int result = N;
    for(int i = 1; i <= idx; i++) {
        result = result * 10 + N;
    }
    return result;
}

int solution(int N, int number) {
    if (N == number) return 1;

    vector<unordered_set<int>> DP(8);
    for (int i = 0; i < 8; i++) {
        DP[i].insert(getNS(N, i));
    }

    for (int k = 1; k < 8; k++) {
        for (int i = 0; i < k; i++) {
            for (int a : DP[i]) {
                for (int b : DP[k - i - 1]) {
                    DP[k].insert(a + b);
                    if (a - b > 0) DP[k].insert(a - b);
                    DP[k].insert(a * b);
                    if (b != 0) DP[k].insert(a / b);
                }
            }
        }
        if (DP[k].find(number) != DP[k].end())
            return k + 1;
    }

    return -1; //없거나 8 초과인 경우
}
