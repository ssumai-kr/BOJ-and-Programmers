#include <iostream>
#include <vector>
using namespace std;

void solution_11659_2() { //구간 합 구하기 4
    int N, M;
    cin >> N >> M;
    vector<int> nums(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        nums[i] = nums[i-1] + num;
    }
    vector<int> results;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        results.push_back(nums[b] - nums[a - 1]);
    }

    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution_11659_2();
    
    return 0;
}