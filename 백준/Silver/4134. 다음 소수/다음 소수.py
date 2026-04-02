import sys
input = sys.stdin.readline

def is_prime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    # Miller-Rabin deterministic witnesses for n < 3.2*10^18
    d, r = n - 1, 0
    while d % 2 == 0:
        d //= 2
        r += 1
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if a >= n: continue
        x = pow(a, d, n)
        if x == 1 or x == n - 1: continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1: break
        else:
            return False
    return True

T = int(input())
for _ in range(T):
    n = int(input())
    if n < 2:
        n = 2
    while not is_prime(n):
        n += 1
    print(n)