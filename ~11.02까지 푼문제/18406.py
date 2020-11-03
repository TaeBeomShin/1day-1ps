n=input()
x=len(n)//2
print("READY"if sum(map(int,n[:x]))-sum(map(int,n[x:]))else"LUCKY")


