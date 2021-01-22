while(True):
    n=int(input())
    if(n==0): break
    c=[0]*(n+1)
    pages=input().split(",")
    for page in pages:
        if "-" in page:#여러장에 대해.
            start,end=map(int,page.split("-"))
            if (end > n): end = n
            if(start>end):continue
            for i in range(start,end+1): c[i]=1
        else:#1장에대해
            page=int(page)
            if(page>n):continue
            c[page]=1
    print(sum(c))