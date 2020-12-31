import math
n=int(input())
M=10000000
sosu=[]
check=[0,0]+[1]*M

for i in range(2,M):
    if check[i]:
        if(i>=n):
            sosu.append(i)
        for j in range(2*i,M,i):
            check[j]=False

ans=0
for i in range(len(sosu)):
    num=str(sosu[i])
    if(num==num[::-1]):
        ans=num
        break

print(ans)