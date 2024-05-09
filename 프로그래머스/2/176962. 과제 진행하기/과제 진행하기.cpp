//프로그래머스 | 과제 진행하기 문제 https://school.programmers.co.kr/learn/courses/30/lessons/176962#

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;



struct Plan {
    string name;
    int start;
    int playTime;
    int endTime;
};

int timeToint(int hour, int minute, int playTime = 0) {
    int time = hour * 60;
    time += minute;

    if (playTime > 0) {
        time += playTime;
    }

    return time;

}

bool compareByStart(const Plan& a, const Plan& b) {
    return a.start < b.start;
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Plan> sorted_plans;
    stack<pair<string, int>> stops;

    int nameIndex = 0;
    int startIndex = 1;
    int playTimeIndex = 2;

    for (int i = 0; i < plans.size(); i++) {
        int hour;
        int minute;
        string timeString = plans[i][startIndex];
        size_t pos = timeString.find(":");
        if (pos != string::npos) {
            hour = stoi(timeString.substr(0, pos));
            minute = stoi(timeString.substr(pos + 1));
        }
        int playTime_ = stoi(plans[i][playTimeIndex]);
        sorted_plans.push_back({ plans[i][nameIndex], timeToint(hour, minute), playTime_, timeToint(hour, minute, playTime_)});
    }

    sort(sorted_plans.begin(), sorted_plans.end(), compareByStart);

    for (int i = 0; i < sorted_plans.size() - 1; i++) {

        if (sorted_plans[i].endTime > sorted_plans[i + 1].start) { //다음꺼 이전에 못끝냈을때
            int gap = sorted_plans[i].endTime - sorted_plans[i + 1].start;
            stops.push(make_pair(sorted_plans[i].name, gap));
        }

        else if (sorted_plans[i].endTime < sorted_plans[i + 1].start) {//다음꺼 이전에 끝냈을 때
            answer.push_back(sorted_plans[i].name);
            int gap = sorted_plans[i + 1].start - sorted_plans[i].endTime;
            int remain = 0;
            if (!stops.empty()) {
                remain = stops.top().second;
            }
            while (gap >= remain && !stops.empty()) {
                gap -= remain;
                answer.push_back(stops.top().first);
                stops.pop();
                if (!stops.empty()) {
                    remain = stops.top().second;
                }
            }
            if (!stops.empty()) {
                stops.top().second = remain - gap;
            }
        }
        else if (sorted_plans[i].endTime == sorted_plans[i+1].start) {
            answer.push_back(sorted_plans[i].name);
        }
    }
    answer.push_back(sorted_plans[sorted_plans.size() - 1].name);

    while (!stops.empty()) {
        answer.push_back(stops.top().first);
        stops.pop();
    }
    
    
    return answer;
}