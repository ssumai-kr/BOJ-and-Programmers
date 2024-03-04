#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph { //2606번 바이러스
private:
    int num_vertices;
    vector<vector<int>> adj_list;
    vector<bool> visited;
    int cnt = 0;

public:
    Graph(int num_vertices, int M) : num_vertices(num_vertices), adj_list(num_vertices), visited(num_vertices, false) {}

    void add_edge(int u, int v) {
        adj_list[u - 1].push_back(v);
        adj_list[v - 1].push_back(u);
    }
    void DFS(int R) {
        visited[R - 1] = true;
        cnt++;
        for (int v : adj_list[R - 1]) {
            if (!visited[v - 1]) {
                DFS(v);
            }
        }
    }
    void solution() {
        DFS(1);
        cout << cnt -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    Graph run(N, M);

    int i, j;
    vector<pair<int, int>> edges; // 입력된 간선들을 저장할 벡터

    for (int a = 0; a < M; a++) {
        cin >> i >> j;
        edges.push_back({ min(i, j), max(i, j) }); // 간선 입력을 오름차순으로 정렬하여 저장
    }

    sort(edges.begin(), edges.end()); // 입력된 간선들을 정렬

    for (auto edge : edges) {
        run.add_edge(edge.first, edge.second); // 정렬된 간선을 그래프에 추가
    }

    run.solution();
    return 0;
}