n=int(input()); l=list(map(int,input().split()));
s=sorted(list(set(l)));d={}
for i in range(len(s)): d[s[i]]=i
for i in l:print(d[i],end=" ")