n=int(input())
alpha=[0]*26
for i in range(n):
    s=input()
    idx=0;
    for j in range(len(s)):
        c=int(s[j].lower())-int('a')
        if(alpha[c]==0):
            alpha[c]=1
            idx=j
    for j in range(len(s)):
        if(j==idx):
            print(f"[%s]"%s[j],end="")
            continue
        print(s[j],end="")