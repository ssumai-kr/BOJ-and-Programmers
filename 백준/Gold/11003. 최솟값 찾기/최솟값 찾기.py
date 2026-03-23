#백준 최솟값 찾기 11003번 문제 (골드1)
#제한시간 2.4초 N의 길이 5,000,000 -> 시간복잡도 O(N)

from collections import deque

N, L =  map(int, input().split())
mydeque = deque() #덱 생성
#주어진 숫자를 담는 리스트
now = list(map(int, input().split()))

for i in range(N):
    while mydeque and mydeque[-1][0] > now[i]:
        mydeque.pop()
    mydeque.append((now[i], i))
    if mydeque[0][1] <= i-L:
        mydeque.popleft()
    print(mydeque[0][0], end=' ')


