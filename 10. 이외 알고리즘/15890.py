n=int(input())
if(n%10==0):
    print(n//300,n%300//60,n%60//10)
else:
    print(-1)