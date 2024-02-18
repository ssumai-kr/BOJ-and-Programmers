#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void solution_17219() { //비밀번호 찾기
    unordered_map<string, string> passwords;

    int N, M; cin >> N >> M;
    string url, pw;
    for (int i = 0; i < N; i++) {
        cin >> url >> pw;
        passwords.insert({ url, pw });   
    }
    string search;
    for (int i = 0; i < M; i++) {
        cin >> search;
        cout << passwords[search] << "\n";
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    solution_17219();

    return 0;
}