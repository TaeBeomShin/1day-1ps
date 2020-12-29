sosu=[]
check=[0,0]+[True]*(10200)

for i in range(2,10200):
    if check[i]:
        sosu.append(i)
        for j in range(2*i,10200,i):
            check[j]=False

for _ in range(int(input())):
    n=int(input())
    minn=10000
    for a in sosu:
        if(a>n):break
        if(check[n-a] and abs(n-2*a)<minn):
            minn=abs(n-2*a)
            c,d=a,n-a
    print(c,d)
