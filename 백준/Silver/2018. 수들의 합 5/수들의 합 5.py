#백준 수들의 합5 2018번 문제 (실버5)
#투 포인터 알고리즘 활용

#제한 시간: 2초 / N은 최대 10,000,000
# => O(N) 필요

import sys
input = sys.stdin.readline

N = int(input())

#초기 변수 초기화 -> N은 그대로 sum을 만족하므로 count에 1 기본값 지정
count = 1
start_index = 1
end_index = 1
sum = 1

while end_index != N:
    if sum == N:
        count += 1
        end_index += 1
        sum += end_index
    elif sum > N:
        sum -= start_index
        start_index += 1
    else:
        end_index += 1
        sum += end_index

print(count)
