n,m=map(int,input().split())
b,b2={},{}
for i in range(1,n+1):p=input();b[i]=p;b2[p]=i
for i in range(m):
    q=input()
    try:print(b[int(q)])
    except:print(b2[q])