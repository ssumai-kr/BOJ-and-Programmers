#include <iostream>
#include <vector>
using namespace std;

class solution_11729 {
public:
    vector<pair<int, int>> record;
    int cnt = 0;

    void recording(int num_disks, int start, int end) {
        cnt++;
        record.push_back({start, end});
    }

    void hanoi(int num_disks, int start, int end) {
        if (num_disks == 0) {
            return;
        }
        else {
            int other = 6 - start - end;

            hanoi(num_disks - 1, start, other);
            
            recording(num_disks, start, end);

            hanoi(num_disks - 1, other, end);
        }
    }

    void solution() {
        int N; cin >> N;
        hanoi(N, 1, 3);
        cout << cnt << "\n";
        for (const auto& k : record) {
            cout << k.first << " " << k.second << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
  solution_11729 run;
    run.solution();

    return 0;
}