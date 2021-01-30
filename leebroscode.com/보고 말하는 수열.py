n=int(input())

num='1';

dict={}
if(n==1): print('1')
else:
    n-=1
    while(n>0):
        ans='';
        for i in range(1, 10): dict[i] = 0;
        for i in range(len(num)):
            number=int(num[i])
            if(dict[number]>0):#저장된 값과 동일한 경우.
                dict[number]+=1
            else:#저장된 값과 다른 경우.
                for j in range(1,10):
                    if(dict[j]>0):
                        ans+=str(j);ans+=str(dict[j]);
                        dict[j]=0
                        break
                dict[number] = 1
        for j in range(1, 10):
            if (dict[j] > 0):
                ans += str(j);
                ans += str(dict[j]);
        num=ans
        n-=1

    print(ans)