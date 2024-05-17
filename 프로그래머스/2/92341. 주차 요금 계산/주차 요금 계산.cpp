#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct record {
    int time;
    int number;
    string status;
};


int timeToint(int hour, int minute) {
    int time = hour * 60;
    time += minute;

    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<record> Records;
    unordered_map<int, int> In;
    unordered_map<int, int> Sum;

    for (int i = 0; i < records.size(); i++) {
        string record = records[i];
        istringstream iss(record);

        string time, number, status;
        iss >> time >> number >> status;
        int hour, minute;

        size_t pos = time.find(":");
        if (pos != string::npos) {
            hour = stoi(time.substr(0, pos));
            minute = stoi(time.substr(pos + 1));
        }

        Records.push_back({ timeToint(hour, minute), stoi(number), status });
    }

    for (int i = 0; i < Records.size(); i++) {
        if (Records[i].status == "IN") {
            In[Records[i].number] = Records[i].time;
        }
        else if (Records[i].status == "OUT") {
            int inTime = In[Records[i].number];
            if (Sum.count(Records[i].number) > 0) {
                Sum[Records[i].number] += Records[i].time - inTime;
            }
            else Sum[Records[i].number] = Records[i].time - inTime;

            In.erase(Records[i].number);
        }
    }

    for (const auto& pair : In) {
        int inTime = pair.second;
        int outTime = timeToint(23, 59); // 23:59에 출차된 것으로 간주
        if (Sum.count(pair.first) > 0) {
            Sum[pair.first] += outTime - inTime;
        }
        else {
            Sum[pair.first] = outTime - inTime;
        }
    }

    // 여기까지는 모든 차량의 총 주차 시간이 Sum에 기록됨
    // 추가로 기본 요금 계산 등의 로직을 구현해야 함

    // 차량 번호 순서대로 주차 요금을 계산하고 answer 벡터에 추가
    vector<pair<int, int>> sortedSum(Sum.begin(), Sum.end());
    sort(sortedSum.begin(), sortedSum.end());

    for (const auto& p : sortedSum) {
        int totalTime = p.second;
        int fee = fees[1]; // 기본 요금

        if (totalTime > fees[0]) {
            fee += ((totalTime - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
        }

        answer.push_back(fee);
    }


    return answer;
}