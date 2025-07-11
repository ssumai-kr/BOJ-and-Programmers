#include <string>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end()); // 사전순 정렬

    for (int i = 0; i < phone_book.size() - 1; i++) {
        // 바로 다음 번호가 현재 번호로 시작하는지 확인 (접두사인지)
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            answer = false;
        }
    }

    
    return answer;
}