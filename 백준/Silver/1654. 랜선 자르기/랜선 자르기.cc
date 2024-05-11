#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

class solution_1654 { //랜선 자르기 (매개 변수 탐색 & 이분 탐색)

public:
    int k, n;
    vector<int> lan;

    bool isPossible(int len) {
        int cnt = 0;

        for (int i = 0; i < k; i++) {
            cnt += lan[i] / len;
        }

        if (cnt >= n) return true;
        else return false;
    }

    void solution() {
        cin >> k >> n;
        lan.assign(k, 0);

        for (int i = 0; i < k; i++) {
            cin >> lan[i];
        }

        sort(lan.begin(), lan.end());
        
        unsigned int left = 1, right = lan[lan.size() - 1];
        unsigned int result = 0;

        while (left <= right) {
            unsigned int mid = (left + right) / 2;

            if (isPossible(mid)) {
                result = max(result, mid);
                left = mid + 1;
            }
            else right = mid - 1;
        }
        cout << result;
    }

   

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solution_1654 run;
    run.solution();

    return 0;
}