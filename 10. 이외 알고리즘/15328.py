from decimal import *
getcontext().prec=100

T=int(input())
for _ in range(T):
    n=Decimal(input())
    x,y,z=0,0,0
    sum=Decimal('0')
    for i in range(4):
        a,b,c=map(Decimal,input().split())
        sum+=Decimal((a-x)**2+(b-y)**2+(c-z)**2).sqrt()
        x,y,z=a,b,c
    if sum<=n:
        print("YES")
    else:
        print("NO")