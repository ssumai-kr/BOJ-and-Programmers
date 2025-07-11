#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int target, int index, int currentSum) {
    if(index == numbers.size()) {
        return currentSum == target ? 1: 0;
    }
    
    return dfs(numbers, target, index + 1, currentSum + numbers[index]) +
        dfs(numbers, target, index +1, currentSum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}