#백준 구간 합 구하기5 11660번

#2차원의 구간합 배열을 익혀보자!

import sys
input = sys.stdin.readline

N, M = map(int, input().split())

A = [[0] * (N+1)]
D = [[0] * (N+1) for _ in range(N+1)]

#원본 리스트 저장

for i in range(N):
    A_row = [0] + [int(x) for x in input().split()] #한 행 입력받기 인덱스 맞추기 위해서 [0]은 0으로 초기화
    A.append(A_row)

#2차원 합배열 만들기     공식 => D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j]
for i in range(1, N+1):
    for j in range(1, N+1):
        D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j]


#질의에 대한 결과 계산 및 출력하기
for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    result = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1]
    print(result)