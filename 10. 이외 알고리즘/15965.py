import math
k=int(input())
M=10000000
sosu=[]
check=[0,0]+[1]*M

for i in range(2,M):
    if check[i]:
        sosu.append(i)
        for j in range(2*i,M,i):
            check[j]=False
print(sosu[k-1])