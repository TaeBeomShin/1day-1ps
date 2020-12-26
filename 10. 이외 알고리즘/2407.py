def factorial_iter(n):
    if n==1 or n==2:
        return n
    else:
        result=1
        while n>1:
            result*=n
            n-=1
        return result

n,m=map(int,input().split())
#nCm=n!/((n-m)!*m!)
print(factorial_iter(n)//(factorial_iter(n-m)*factorial_iter(m)))