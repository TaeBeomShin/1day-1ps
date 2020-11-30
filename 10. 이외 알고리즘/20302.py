from math import gcd
from sys import stdin
primes=[]
check=[False,False]+[True]*(100000-1)
for i in range(2,100000):
    if check[i]:
        primes.append(i)
        for j in range(2*i,100000,i):
            check[j]=False

n=int(input())
num=stdin.readline().split()
result=[0]*100000

# 분모와 분자를 리스트에 집어넣는다.
for i in range(len(num)):
    if(i==0):
        x=int(num[i])
        if x<0:x=-x
        for p in primes:
            degree = 0
            while x % p == 0:
                degree += 1
                x = x // p
            result[p] += degree
            if x == 1:
                break
    elif(num[i].isdigit()):
        if(num[i-1]=="*"):
            x = int(num[i])
            if x < 0: x = -x
            for p in primes:
                degree = 0
                while x % p == 0:
                    degree += 1
                    x = x // p
                result[p] += degree
                if x == 1:
                    break
        elif(num[i-1]=="/"):
            x = int(num[i])
            if x < 0: x = -x
            for p in primes:
                degree = 0
                while x % p == 0:
                    degree += 1
                    x = x // p
                result[p] -= degree
                if x == 1:
                    break

check=True
for r in result:
    if(r<0):check=False

if(check):print("mint chocolate")
else:print("toothpaste")
