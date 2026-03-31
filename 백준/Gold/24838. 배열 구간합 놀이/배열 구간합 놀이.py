import sys
from collections import Counter

input = sys.stdin.readline
MOD = 10**9 + 7

def solve():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    
    # 차분 배열로 O(n+m)에 구간 커버리지 계산
    diff = [0] * (n + 2)
    for _ in range(m):
        x, y = map(int, input().split())
        diff[x] += 1
        diff[y + 1] -= 1
    
    cnt = []
    cur = 0
    for j in range(1, n + 1):
        cur += diff[j]
        cnt.append(cur)
    
    # 내림차순 정렬 후 그리디 매칭
    cnt.sort(reverse=True)
    A.sort(reverse=True)
    
    max_s = sum(A[i] * cnt[i] for i in range(n))
    
    # 같은 cnt 값을 가진 그룹별 k! 곱
    ways = 1
    freq = Counter(cnt)
    for group_size in freq.values():
        for k in range(2, group_size + 1):
            ways = ways * k % MOD
    
    print(max_s, ways)

T = int(input())
for _ in range(T):
    solve()