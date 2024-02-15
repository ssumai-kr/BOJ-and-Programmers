#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class solution_20920 { //영단어 암기는 어려워
public:
    void solution() {
        int N, M;
        cin >> N >> M;

        string input;
        unordered_map<string, int> dict;
        for (int i = 0; i < N; i++) {
            cin >> input;
            if (input.length() >= M)
                dict[input]++;
        }

        // 비교자 함수 정의
        auto compare = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) // 1. 자주 나오는 단어일수록 앞에 배치
                return a.second > b.second;
            if (a.first.length() != b.first.length()) // 2. 단어의 길이가 긴 것을 앞에 배치
                return a.first.length() > b.first.length();
            // 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
            return a.first < b.first;
        };

        vector<pair<string, int>> sortedDict(dict.begin(), dict.end());
        sort(sortedDict.begin(), sortedDict.end(), compare);

        for (const auto& word : sortedDict) {
            cout << word.first << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution_20920 run;
    run.solution();

    return 0;
}