import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())

tree = [0] * (N + 1)

def update(i, delta):
    while i <= N:
        tree[i] += delta
        i += i & (-i)  # 마지막 비트만큼 앞으로 이동

def query(i):
    total = 0
    while i > 0:
        total += tree[i]
        i -= i & (-i)  # 마지막 비트 제거
    return total

# 초기 배열 입력 및 트리 구성
arr = [0] * (N + 1)
for i in range(1, N + 1):
    arr[i] = int(input())
    update(i, arr[i])

for _ in range(M + K):
    a, b, c = map(int, input().split())

    if a == 1:
        delta = c - arr[b]  # 기존값과의 차이만큼만 업데이트
        arr[b] = c
        update(b, delta)
    elif a == 2:
        print(query(c) - query(b - 1))