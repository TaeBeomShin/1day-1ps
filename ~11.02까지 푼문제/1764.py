n,m=map(int,input("").split())
unheard=set();unknown=set()
for _ in range(n):unheard.add(input())
for _ in range(m):unknown.add(input())
answer=list(unheard.intersection(unknown))

print(len(answer))
for name in sorted(answer):print(name)