// 백준 1074번 Z
#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int ans = 0;
void dc(int x, int y, int n) {
    if (c == x && r == y) {
        cout << ans;
        return;
    }
    else if (c < x + n && r < y + n && c >= x && r >= y) {

        dc(x, y, n / 2);
        dc(x + n / 2, y, n / 2);
        dc(x, y + n / 2, n / 2);
        dc(x + n / 2, y + n / 2, n / 2);
    }
    else {
        ans += n * n;
    }
}
int main() {
    cin >> n >> r >> c;
    dc(0, 0, pow(2, n));
    return 0;
}