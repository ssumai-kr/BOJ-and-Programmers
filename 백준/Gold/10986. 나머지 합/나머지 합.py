#백준 나머지 합 문제 10986번 (골드3)

#수 N개가 주어질 때, 연속된 부분 구군의 합이 M으로 나누어 떨어지는 구간의 개수를 구하시오.

import sys
input = sys.stdin.readline

N,M = map(int,input().split())
A = list(map(int, input().split()))

S = [0] * N
C = [0] * M

S[0] = A[0]
answer = 0

for i in range(1, N):
    S[i] = S[i-1] + A[i]

#구간 별 계산
# for i in range(1, N+1):
#     for j in range(i, N+1):
#         sum = S[j] - S[i-1]
#         if sum % M == 0:
#             count += 1
#
# print(count)
#======> 시간 초과

#S[j] % M의 값과 S[i] % M의 값이 같다면, (S[j]-S[i]) % M은 0이다. 즉, 구간 합 배열의
#원소를 M으로나눈 나머지로 업데이트하고 S[j]와 S[i]가 같은 (i,j)쌍을 찾으면 원본 리스트에서
#i+1 부터 j까지의 구간 합이 M으로 나누어 떨어진다는 것을 알 수 있다.

#2. 합배열의 모든 값에 대해서 M으로 나머지 연산을 수행해 값을 업데이트

for i in range(N):
    remainder = S[i] % M
    if remainder == 0:
        answer += 1
    C[remainder] += 1

for i in range(M):
    #나머지가 같은 인덱스 중 2개를 뽑는 경우의 수 더하기
    # nC2 공식 사용 -> (n * n-1) / 2
    if C[i] > 1:
        answer += (C[i] * (C[i]-1) // 2)

print(answer)