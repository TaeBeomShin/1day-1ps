n,m=map(int,input().split())
dict={}
for i in range(n):
    site,password=input().split()
    dict[site]=password

for i in range(m):
    site=input()
    print(dict[site])