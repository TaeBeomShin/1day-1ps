n,w,h=map(int,input("").split())
m=w**2+h**2
for _ in range(n):
    if int(input())**2>m: print("NE")
    else : print("DA")