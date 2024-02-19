#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class solution_2444 { //BFS
public:
	int num_vertices;
	vector<bool> visited;
	vector<vector<int>> graph;
	vector<int> results;
	queue<int> Q;
	int cnt = 0;

	solution_2444(int N, int M) {
		num_vertices = N;
		graph.resize(N);
		visited.resize(N, false);
		results.resize(N, 0);
		
	}

	void add_edge(int u, int v) {
		graph[u - 1].push_back(v);
		graph[v - 1].push_back(u);
	}

	void BFS(int R) {
		visited[R - 1] = true;
		results[R - 1] = cnt++;
		Q.push(R);
		
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			if (results[u - 1] == 0) results[u - 1] = cnt++;
			for (int i = 0; i < graph[u - 1].size(); i++) {
				if (visited[graph[u-1][i]-1] == false) {
					results [graph[u - 1][i] - 1] = cnt++;
					visited[graph[u - 1][i] - 1] = true;
					Q.push(graph[u - 1][i]);
				}
			}
		}
	}

	void solution(int R) {
		BFS(R);

		for (int i = 0; i < results.size(); i++) {
			cout << results[i] << "\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M, R;
	cin >> N >> M >> R;
	solution_2444 run(N, M);

	vector<pair<int, int>> edges;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		edges.push_back({ min(u,v), max(u,v) });
	}
	sort(edges.begin(), edges.end());

	for (const auto& edge : edges) {
		run.add_edge(edge.first, edge.second);
	}
	run.solution(R);

	return 0;
}