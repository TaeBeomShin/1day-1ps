s=input().split()
l=[]
for a in s:
    v=a.split("-")
    for b in v:
        l.append(b)
count=len(l)

word,word2='cjnmtsld','aeiouh'
for a in l:
    if a.find("'")>1:
        b=a.index("'")
        if(a.index("'")>2):continue
        if(a[b-1:b] in word or a[b-2:b]=='qu'):
            if(a[b+1:b+2] in word2):
                count+=1

print(count)