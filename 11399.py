n=int(input())
print(sum(x*(n-i) for i,x in enumerate(sorted(list(map(int,input().split()))))))

