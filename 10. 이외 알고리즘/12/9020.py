M=10001
L=[1]*M
L[1]=0

for i in range(2,M):
    j=2*i
    while j<M:
        L[j]=0; j+=i

for _ in range(int(input())):
    n=int(input())
    for i in range(2,n//2+1):
        if L[i]==0 or L[n-i]==0:pass
        else: k=i
    print(k,n-k)