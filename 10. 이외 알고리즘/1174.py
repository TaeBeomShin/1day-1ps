n=int(input())

if(n>1024):
    print(-1)
else:
    i,count=0,0
    while(True):
        if i<10: count+=1
        else:
            num=str(i)
            check=True
            for j in range(len(num)-1):
                if(num[j]<=num[j+1]):
                    check=False
                    break
            if(check):
                count+=1
        if(n==count):
            print(i)
            break
        i+=1