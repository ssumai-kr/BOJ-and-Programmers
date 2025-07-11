#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Song {
    int play;
    int index;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genrePlaySum;                   // 장르별 총 재생 수
    unordered_map<string, vector<Song>> genreToSongs;          // 장르별 노래 리스트

    // 1. 장르별 재생 수와 곡 목록 저장
    for (int i = 0; i < genres.size(); i++) {
        genrePlaySum[genres[i]] += plays[i];
        genreToSongs[genres[i]].push_back({plays[i], i});
    }

    // 2. 장르들을 총 재생 수 기준으로 정렬
    vector<pair<string, int>> sortedGenres(genrePlaySum.begin(), genrePlaySum.end());
    sort(sortedGenres.begin(), sortedGenres.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    // 3. 각 장르에서 재생 수 많은 노래 2개씩 선택
    for (const auto& g : sortedGenres) {
        string genre = g.first;
        auto& songs = genreToSongs[genre];

        // 곡 정렬: 재생 수 내림차순 → 인덱스 오름차순
        sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            if (a.play == b.play) return a.index < b.index;
            return a.play > b.play;
        });

        // 최대 2곡까지 answer에 추가
        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].index);
        }
    }

    return answer;
}
