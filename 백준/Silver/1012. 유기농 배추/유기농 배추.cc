#include <iostream>
#include <vector>

using namespace std;

class Graph { //유기농 배추 문제
private:
    vector<vector<int>> idx;
    vector<vector<bool>> visited;
    vector<int> results;
    int ro;
    int ca;
    int cnt = 0;
    int recent_c;
    int recnet_r;

public:
    Graph(int row, int cal) : idx(cal + 1, vector<int>(row + 1, 0)),
        visited(cal + 1, vector<bool>(row + 1, false)), ro(row), ca(cal) {}

    void add(int r, int c) {
        idx[c][r] = 1;
    }
    //처음에는 0,0 부터 돌아야할듯 -> 전수조사

    void DFS(int c, int r, vector<vector<bool>>& visited) {
        if (c < 0 || c >= ca || r < 0 || r >= ro) // 범위를 벗어나면 종료
            return;

        visited[c][r] = true;
      
        bool visit = false;
        if (r - 1 >= 0 && idx[c][r - 1] == 1 && !visited[c][r - 1]) {
            DFS(c, r - 1, visited);
            visit = true;
        }
        if (r + 1 <= ro && idx[c][r + 1] == 1 && !visited[c][r + 1]) {
            DFS(c, r + 1, visited);
            visit = true;
        }
        if (c - 1 >= 0 && idx[c - 1][r] == 1 && !visited[c - 1][r]) {
            DFS(c - 1, r, visited);
            visit = true;
        }
        if (c + 1 <= ca && idx[c + 1][r] == 1 && !visited[c + 1][r]) {
            DFS(c + 1, r, visited);
            visit = true;
        }
        /*if (!visit) {
            cnt++;
            recent_c = c;
            recnet_r = r;
        }*/
        idx[c][r] = 0;
    }

    //입력을 x y로 받으면[y][x]로 넣어야 한다!

    void solution() {
        for (int i = 0; i <= ca; i++) {
            for (int j = 0; j <= ro; j++) {
                if (idx[i][j] == 1) {
                    DFS(i, j, visited);
                    cnt++;

                }
            }
        }

        cout << cnt << '\n';
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, row, cal, k;
    cin >> T;

    for (int j = 0; j < T; j++) {
        cin >> row >> cal >> k;
        Graph run(row, cal);
        for (int i = 0; i < k; i++) {
            int r, c;
            cin >> r >> c;
            run.add(r, c);
        }
        run.solution();
    }

    return 0;
}