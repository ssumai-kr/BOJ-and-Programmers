#include <iostream>
using namespace std;

void solution_10039() {
    int sum = 0;
    int n;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        if (n < 40) n = 40;
        sum += n;
    }
    cout << sum / 5;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    solution_10039();

    return 0;
}