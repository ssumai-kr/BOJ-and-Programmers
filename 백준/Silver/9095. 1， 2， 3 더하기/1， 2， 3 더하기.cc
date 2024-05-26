#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        // dp 배열 선언 및 초기화
        int dp[11] = {0};
        dp[0] = 1;  // 0을 만드는 방법은 1가지 (아무것도 선택하지 않는 것)
        dp[1] = 1;  // 1을 만드는 방법은 1가지 (1)
        dp[2] = 2;  // 2를 만드는 방법은 2가지 (1+1, 2)
        dp[3] = 4;  // 3을 만드는 방법은 4가지 (1+1+1, 1+2, 2+1, 3)

        // dp[i] 계산
        for(int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        // 결과 출력
        cout << dp[n] << endl;
    }

    return 0;
}
