#include <iostream>
#include <vector>
using namespace std;

class solution_24416 {//알고리즘 수업- 피보나치 수 1
public:
    int cnt_fib = 0;
    int cnt_fibonacci = 0;
    vector<int> f;

    int fib(int n) {
        
        if (n == 1 || n == 2) {
            cnt_fib++;
            return 1;
            
        }
        else return fib(n - 1) + fib(n - 2);
    }
    int fibonacci(int n) {
        f[1], f[2] = 1;
        int i;
        for (i = 3; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        cnt_fibonacci = n - 2;
        return f[n];

    }

    void solution() {
        int n; cin >> n;
        f.resize(n + 1);
        fib(n);
        fibonacci(n);
        cout << cnt_fib << " " << cnt_fibonacci;
    }

};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution_24416 run;

    run.solution();
    
    return 0;
}