import sys
input = sys.stdin.readline


def solve():
    n = int(input())
    sizes = list(map(int, input().split()))
    t, p = map(int, input().split())

    # --- 티셔츠 계산 ---
    total_t_bundles = 0
    for s in sizes:
        if s == 0:
            continue
        total_t_bundles += (s + t - 1) // t

    print(total_t_bundles)

    # --- 펜 계산 ---
    bundles, singles = divmod(n, p)
    print(f"{bundles} {singles}")


if __name__ == "__main__":
    solve()