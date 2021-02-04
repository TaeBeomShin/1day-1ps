t=int(input())
for _ in range(t):
    n=int(input())

    dict={}
    for _ in range(n):
        name, usage = input().split()
        if usage in dict:
            dict[usage]+=1
        else:
            dict[usage]=1
    clothes=list(dict.values())
    sum=1
    for cloth in clothes:
        sum*=(cloth+1)
    print(sum-1)
