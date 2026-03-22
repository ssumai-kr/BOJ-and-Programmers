#백준 좋다 1253번 문제 (골드 4)

#투포인터를 어떻게 활용할지..!

'''
N개의 수 중에서 어떤 수가 다른 수 두개의 합으로 나타낼 수
있다면 그 수를 '좋다' 라고 함.

N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇개인지 출력하라.
* 수의 위치가 다르면 값이 같아도 다른 수이다.
'''

import sys
input = sys.stdin.readline

N = int(input())

#1. 받은 리스트 정렬하기
numbers = list(map(int, input().split()))
numbers.sort()

#2. 포인터 이동 원칙 정하기
# A[i] + A[j] > K => j--
# A[i] + A[j] < K => i++
# A[i] + A[j] == K => count++

#K가 어떤 두 수의 합이 되려면 정렬되어 있으므로 무조건 K보다 왼쪽이여야 함 ㅇㅈ?
#아 근데 음의 정수도 있으니.. 양쪽 끝에서 오되, K랑 겹치면 포인터 이동
count = 0

for K in range(N):
    find = numbers[K]
    i = 0
    j = N - 1

    #투포인터 알고리즘
    while i < j:
        if numbers[i] + numbers[j] == find:
            if i != K and j != K:
                count += 1
                break
            elif i == K:
                i += 1
            elif j == K:
                j -= 1
        elif numbers[i] + numbers[j] < find:
            i += 1
        else:
            j -= 1
print(count)


