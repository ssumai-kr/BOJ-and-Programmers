#백준 주몽 2940번 문제 (실버4)

#제한시간 2초 / N의 개수 15,000개
# => O(nlogn)의 시간복잡도

import sys
input = sys.stdin.readline

N = int(input())
M = int(input())

numbers = list(map(int, input().split()))

numbers.sort()

count = 0

i = 0
j = N -1

#2018번 문제와 다르게, 연속된 수의 합이 아니기 때문에
#양 끝에서 서로를 향해 다가오는 방식을 사용해야 함

while i < j:
    if numbers[i] + numbers[j] < M:
        i += 1
    elif numbers[i] + numbers[j] > M:
        j -= 1
    else:
        count += 1
        i += 1
        j -= 1

print(count)