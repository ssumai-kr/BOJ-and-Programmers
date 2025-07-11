#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> one   = {1, 2, 3, 4, 5};
    vector<int> two   = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> scores(3, 0); // 각 수포자 맞힌 개수

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i % one.size()]) scores[0]++;
        if (answers[i] == two[i % two.size()]) scores[1]++;
        if (answers[i] == three[i % three.size()]) scores[2]++;
    }

    int maxScore = max(scores[0], max(scores[1], scores[2]));

    for (int i = 0; i < 3; i++) {
        if (scores[i] == maxScore) {
            answer.push_back(i + 1); // 수포자 번호는 1번부터 시작
        }
    }

    return answer;
}
