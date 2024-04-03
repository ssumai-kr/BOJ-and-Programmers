#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    vector<vector<int>> record(friends.size(), vector<int>(friends.size(), 0));
    vector<int> counts(friends.size(), 0);

    for (int i = 0; i < gifts.size(); i++) {
        string give = "", get = "";
        bool isGive = true;
        for (int j = 0; j < gifts[i].size(); j++) {
            if (gifts[i][j] == ' ') {
                isGive = false;
                continue;
            }
            if (isGive)
                give += gifts[i][j];
            else
                get += gifts[i][j];
        }
        int giveidx = -1, getidx = -1;
        for (int k = 0; k < friends.size(); k++) {
            if (give == friends[k]) {
                giveidx = k;
            }
            if (get == friends[k]) {
                getidx = k;
            }
        }
        if (giveidx != -1 && getidx != -1) {
            record[giveidx][getidx]++;
        }
    }

    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < friends.size(); j++) {
            if (record[i][j] > 0) {
                if (record[i][j] > record[j][i]) counts[i]++;
                else if (record[i][j] == record[j][i]) {
                    int giftscore = 0, othergiftscore = 0;
                    for (int a = 0; a < friends.size(); a++) {
                        giftscore += record[i][a] - record[a][i];
                        othergiftscore += record[j][a] - record[a][j];
                    }
                    if (giftscore > othergiftscore) counts[i]++;
                }
            }
            else if (record[i][j] == 0 && record[j][i] == 0) {
                int giftscore = 0, othergiftscore = 0;
                for (int a = 0; a < friends.size(); a++) {
                    giftscore += record[i][a] - record[a][i];
                    othergiftscore += record[j][a] - record[a][j];
                }
                if (giftscore > othergiftscore) counts[i]++;
            }
        }
    }

    sort(counts.begin(), counts.end());
    answer = counts.back();

    return answer;
}
