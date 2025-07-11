#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size() / 2;
    unordered_map<int, int> count;
    int answer = 0;
    for(const auto& num : nums) {
        count[num]++;
    }
    
    answer = count.size();
    if(answer > max) answer = max;
    return answer;
}