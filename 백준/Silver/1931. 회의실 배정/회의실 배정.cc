#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class roomNode {
public:
    int start;
    int finish;

    roomNode() {
        start = 0;
        finish = 0;
    }
    
};
bool compareMeetings(const roomNode& a, const roomNode& b) {
    if (a.finish == b.finish) {
        // 종료 시간이 같을 경우 시작 시간을 기준으로 정렬
        return a.start < b.start;
    }
    // 종료 시간이 다를 경우 종료 시간을 기준으로 정렬
    return a.finish < b.finish;
}

void solution_1931() {

    int N;
    cin >> N;
    
    vector<roomNode> times(N);
    for (int i = 0; i < N; i++) {
        cin >> times[i].start >> times[i].finish;
    }
    sort(times.begin(), times.end(), compareMeetings);

    int currentEnd = times[0].finish;
    int count = 1;
    for (size_t i = 1; i < times.size(); i++) {
        if (times[i].start >= currentEnd) {
            count++;
            currentEnd = times[i].finish;
        }
    }

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    solution_1931();
    

    

    return 0;
}