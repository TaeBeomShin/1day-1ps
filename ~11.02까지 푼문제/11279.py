import heapq,sys
h=[]
for _ in range(int(input())):
    x=int(sys.stdin.readline())
    if x:heapq.heappush(h, x)
    elif h: print(heapq.heappop(h))
    else: print(0)


