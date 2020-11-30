n=int(input())
dic={}
for _ in range(n):
    name,tp=input("").split(".")
    if tp in dic:
        dic[tp]+=1
    else:
        dic[tp]=1

for k,v in sorted(dic.items()):
    print(k,v)