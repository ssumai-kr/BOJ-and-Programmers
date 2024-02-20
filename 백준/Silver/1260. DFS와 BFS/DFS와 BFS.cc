#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class solution_1260 { //DFS와 BFS
public:
    int num_vertices;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> visited_BFS;
    vector<int> results;
    vector<int> results_BFS;
    queue<int> Q;
    int cnt = 0;
    int cnt_BFS = 0;

    solution_1260(int num_vertices, int M) : num_vertices(num_vertices), graph(num_vertices), visited(num_vertices, false), visited_BFS(num_vertices, false), results(num_vertices, 0), results_BFS(num_vertices, 0) {}

    void add_edge(int u, int v) {
        graph[u - 1].push_back(v);
        graph[v - 1].push_back(u);
    }

    void print_adj_list() {
        for (int i = 0; i < results.size(); i++) {
            if(results[i] != 0)
            cout << results[i] << " ";
        }
    }
    void print_adj_list_BFS() {
        for (int i = 0; i < results_BFS.size(); i++) {
            if(results_BFS[i] != 0)
            cout << results_BFS[i] << " ";
        }
    }

    void DFS(int R) {
        visited[R - 1] = true;
        results[cnt++] = R;
        for (int v : graph[R - 1]) {
            if (!visited[v - 1]) {
                DFS(v);
            }
        }
    }

    void BFS(int R) {
        visited_BFS[R - 1] = true;
        results_BFS[cnt_BFS++] = R;
        Q.push(R);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            //if (results_BFS[u - 1] == 0) results_BFS[u - 1] = cnt_BFS++;
            for (int i = 0; i < graph[u - 1].size(); i++) {
                if (visited_BFS[graph[u - 1][i] - 1] == false) {
                    results_BFS[cnt_BFS++] = graph[u - 1][i];
                    visited_BFS[graph[u - 1][i] - 1] = true;
                    Q.push(graph[u - 1][i]);
                }
            }
        }
    }

    void solution(int R) {
        DFS(R);
        BFS(R);
    }

};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;
    solution_1260 run(N, M);

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

    run.solution(R);
    run.print_adj_list();
    cout << "\n";
    run.print_adj_list_BFS();
    return 0;
}