#include <iostream>
#include <vector>

using namespace std;

void generateSequence(int N, int M, vector<int>& sequence, vector<bool>& visited) {
    if (sequence.size() == M) { // 길이가 M인 수열이 완성된 경우 출력
        for (int i = 0; i < M; ++i) {
            cout << sequence[i];
            if (i != M - 1) cout << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) { // 아직 사용되지 않은 숫자라면
            visited[i] = true; // 해당 숫자를 사용 표시
            sequence.push_back(i); // 수열에 추가
            generateSequence(N, M, sequence, visited); // 재귀 호출
            sequence.pop_back(); // 백트래킹
            visited[i] = false; // 사용 표시 초기화
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> sequence;
    vector<bool> visited(N + 1, false); // 숫자 사용 여부를 표시하는 배열

    generateSequence(N, M, sequence, visited);

    return 0;
}