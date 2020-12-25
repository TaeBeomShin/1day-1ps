import sys
input=sys.stdin.readline
n,q=map(int,input().split())
A=sorted(list(map(int,input().split())))
dp,s=[0],0
for i in range(len(A)):
    s+=A[i]
    dp.append(s)
for _ in range(q):
    l,r=map(int,input().split())
    print(dp[r]-dp[l-1])