#include <string>
#include <vector>

using namespace std;

int idx = 0;
int result = 0;
vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
bool found = false;

void dfs(string current, const string& target) {
    if (found) return; // 이미 찾았으면 종료
    if (current == target) {
        result = idx;
        found = true;
        return;
    }
    
    if (current.size() >= 5) return;

    for (int i = 0; i < vowels.size(); i++) {
        idx++;
        dfs(current + vowels[i], target);
    }
}

int solution(string word) {
    idx = 0;
    result = 0;
    found = false;
    dfs("", word);
    return result;
}
