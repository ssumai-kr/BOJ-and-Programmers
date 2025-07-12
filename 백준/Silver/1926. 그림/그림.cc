#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution1926 {
private:
    int n, m;
    vector<vector<int>> paper;
    vector<vector<int>> visited;
    int count;  // 그림 개수
    int maxv;   // 최대 넓이
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

public:
    Solution1926(int n, int m, vector<vector<int>> paper)
        : n(n), m(m), paper(paper), visited(n, vector<int>(m, 0)), count(0), maxv(0) {}

    int BFS(int x, int y) {
        queue<pair<int, int>> q; //xy 좌표
        q.push({ x, y });
        visited[x][y] = 1;
        int area = 1;

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (paper[nx][ny] == 1 && visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        q.push({ nx, ny });
                        area++;
                    }
                }
            }
        }

        return area;
    }

    void solve() {
        count = 0;
        maxv = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (paper[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                    maxv = max(maxv, BFS(i, j));
                }
            }
        }

        cout << count << "\n" << maxv << "\n";
    }
};

int main() {
	int n, m;
	cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    // 입력 받기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    Solution1926 run(n, m, grid);

    run.solve();

    return 0;
}