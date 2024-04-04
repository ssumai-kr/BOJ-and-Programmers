#include <iostream>
#include <vector>
using namespace std;

class Solution_2630 {
private:
    vector<vector<int>> idx;
    int count_paper = 0;
    int count_Blue = 0;

public:
    Solution_2630() {}

    bool checkFull(vector<vector<int>>& idx, int x, int y, int z, int w) {
        for (int i = x; i <= z; i++) {
            for (int j = y; j <= w; j++) {
                if (idx[i][j] == 0) return false;
            }
        }
        return true;
    }

    bool CheckWhite(vector<vector<int>>& idx, int x, int y, int z, int w) {
        for (int i = x; i <= z; i++) {
            for (int j = y; j <= w; j++) {
                if (idx[i][j] == 1) return false;
            }
        }
        return true;
    }

    void partition(vector<vector<int>>& idx, int x, int y, int z, int w, bool isfull) {
        if (isfull) {
            count_Blue++;
            return;
        }
        if (CheckWhite(idx, x, y, z, w)) {
            count_paper++;
            return;
        }
        if (x == z && y == w) return;
        
        bool temp;
        temp = checkFull(idx, x, y, x + (z - x) / 2, y + (w - y) / 2);
        partition(idx, x, y, x + (z - x) / 2, y + (w - y) / 2, temp); //1번 구역
        temp = checkFull(idx, x + (z - x) / 2 + 1, y + (w - y) / 2 + 1, z, w);
        partition(idx, x + (z - x) / 2 + 1, y + (w - y) / 2 + 1, z, w, temp); // 4번구역
        temp = checkFull(idx, x, y + (w - y) / 2 + 1, x + (z - x) / 2, w);
        partition(idx, x, y + (w - y) / 2 + 1, x + (z - x) / 2, w, temp); // 2번 구역
        temp = checkFull(idx, x + (z - x) / 2 + 1, y, z, y + (w - y) / 2);
        partition(idx, x + (z - x) / 2 + 1, y, z, y + (w - y) / 2, temp); //3번 구역
    }

    void solution() {
        int N;
        cin >> N;
        idx.resize(N + 1, vector<int>(N + 1, 0));
        bool isfull = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> idx[i][j];
                if (idx[i][j] == 0) isfull = false;
            }
        }
        partition(idx, 1, 1, N, N, isfull);

        cout << count_paper << "\n" << count_Blue;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution_2630 run;
    run.solution();
    return 0;
}
