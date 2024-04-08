#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph { //2178번 미로 탈출
private:
    vector<vector<pair<int, int>>> idx;
    vector<vector<bool>> visited;
    queue<pair<int, int>> q;
    int N, M;

public:
    Graph() {}

    void BFS(int x, int y) {
        // 이동할 네 방향 정의 (상, 하, 좌, 우)
        int dx[4] = { -1, 1, 0, 0 };
        int dy[4] = { 0, 0, -1, 1 };

        q.push(make_pair(x, y));
        visited[x][y] = true;

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            // 네 방향으로 이동할 수 있는지 확인
            for (int i = 0; i < 4; i++) {
                int nx = a + dx[i];
                int ny = b + dy[i];

                // 범위를 벗어나거나, 이동할 수 없는 경우는 무시
                if (nx < 1 || ny < 1 || nx > N || ny > M || idx[nx][ny].first != 1 || visited[nx][ny])
                    continue;

                // 이동할 수 있는 경우
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                idx[nx][ny].second = idx[a][b].second + 1;
            }
        }
    }

    void solution() {
        cin >> N >> M;
        idx.resize(N + 1, vector<pair<int, int>>(M + 1, { 0,0 }));
        visited.resize(N + 1, vector<bool>(M + 1, false));

        //입력 받기
        for (int i = 1; i <= N; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < M; j++) {
                idx[i][j + 1].first = row[j] - '0'; // 문자열로 입력받은 값을 정수로 변환하여 저장
            }
        }

        // 시작점은 항상 (1, 1)
        idx[1][1].second = 1; // 시작점에서부터 이동했으므로 1로 초기화
        BFS(1, 1);

        // 결과 출력
        cout << idx[N][M].second << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Graph graph;
    graph.solution();

    return 0;
}
