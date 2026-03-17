N, M = map(int, input().split())

arr = list(map(int, input().split()))
S = [0 for _ in range(N)]
S[0] = arr[0]

#1. 합배열 구현
for i in range(1, N):
    S[i] = S[i-1] + arr[i]

answer = []

for i in range(M):
    i, j = map(int, input().split())

    #시작점인 i가 1이면 인덱스 0이므로
    if i <= 1 :
        answer.append(S[j-1] - 0)
    else:
        answer.append(S[j-1] - S[i-2])


for num in answer:
    print(num)