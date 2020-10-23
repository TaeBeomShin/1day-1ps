n,l,s,c=int(input()),[],0,0
for _ in range(n):l.append(list(map(int,input().split())))
l.sort(key= lambda l:[l[1],l[0]])
for i,j in l:
    if(i>=s):s=j;c+=1
print(c)