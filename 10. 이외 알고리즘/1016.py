import math
minn,maxn=map(int,input().split())
valid=[1 for _ in range(minn,maxn+1)]
slist=[v**2 for v in range(2,int(math.sqrt(maxn))+1)]

for s in slist:
    idx=math.ceil(minn/s)*s-minn
    while idx<=maxn-minn:
        valid[idx]=0
        idx+=s

print(sum(valid))