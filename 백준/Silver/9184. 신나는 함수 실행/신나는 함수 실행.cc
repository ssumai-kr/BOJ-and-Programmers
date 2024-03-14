#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> DP(21, vector<vector<int>>(21, vector<int>(21)));
//메모이제이션을 위한 3차원 vector

int w(int a, int b, int c, vector<vector<vector<int>>>& DP) { //문제 예시대로 함수 작성
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1; //하나라도 0 이하인경우 1 return
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20,20,20, DP); //하나라도 20 초과인경우 (20, 20 , 20) return
        //그냥 값을 20으로 맞춰주는것 같음.
    }
    if (DP[a][b][c] != 0) { //DP[a][b][c]에 값이 있다면, 그 값을 return 해주자.
        //여기에서 메모이제이션을 수행. -> 이미 계산된 값은 다시 계산 안한다!
        return DP[a][b][c];
    }
    if (a < b && b < c) {
        //문제 조건에 따라서 DP 배열에 넣고
        DP[a][b][c] = w(a, b, c - 1, DP) + w(a, b - 1, c - 1, DP) - w(a, b - 1, c, DP);
       return DP[a][b][c]; //그 값을 return
    }
    DP[a][b][c] = w(a - 1, b, c, DP) + w(a - 1, b - 1, c,DP) + w(a - 1, b, c - 1, DP) - w(a - 1, b - 1, c - 1, DP);
    return DP[a][b][c]; //마찬가지
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) { //입력으로 -1 -1 -1을 받을 때까지 수행하겠다.
            break;
        }
        int result = w(a, b, c, DP);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
    }
    return 0;
}