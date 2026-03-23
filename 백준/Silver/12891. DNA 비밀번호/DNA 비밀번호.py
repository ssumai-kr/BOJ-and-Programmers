#백준 DNA 비밀번호 12891번 문제 (실버2)

#슬라이딩 윈도우

'''
DNA 문자열 = 등장하는 모든 문자가 {'A','C',G','T'}인 문자열
임의의 DNA문자열을 만들고 만들어진 DNA 문자열의 부분 문자열을 비밀번호로 사용한다.

[규칙]
등장하는 문자의 개수가 특정 개수 이상이어야 비밀번호로 사용할 수 있음.
'''

#P와 S의 길이 = 1,000,000 => O(N)의 시간복잡도로 해결 필요

import sys
input = sys.stdin.readline

P, S = map(int, input().split())
string = input().strip()
minimum = list(map(int, input().split()))

DNA = {'A': minimum[0], 'C': minimum[1], 'G': minimum[2], 'T': minimum[3]}

#초기 카운트 세팅
counts = {c: string[:S].count(c) for c in DNA}

def is_valid():
    return all(counts[c] >=DNA[c] for c in DNA)

answer = 0
if is_valid():
    answer +=1

#슬라이딩 윈도우 시작
for i in range(1, P - S + 1):
    removed = string[i-1]
    added = string[i + S - 1]

    if removed in DNA:
        counts[removed] -= 1
    if added in DNA:
        counts[added] += 1

    if is_valid():
        answer += 1

print(answer)