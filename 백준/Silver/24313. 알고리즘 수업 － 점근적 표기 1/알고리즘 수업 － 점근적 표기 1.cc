#include <iostream>
using namespace std;
void solution_24313() { //알고리즘 수업 - 점근적 표기 1
    int a1, a2;
    int c;
    int n0;

    cin >> a1 >> a2;
    cin >> c;
    cin >> n0;

    int cgn = n0 * c;
    int fn = a1 * n0 + a2;

    if (fn <= cgn && a1 <= c) cout << 1;
    else cout << 0;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solution_24313();

    return 0;
}