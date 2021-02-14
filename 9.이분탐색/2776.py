t=int(input())

for _ in range(t):
    dict={}
    n=int(input())
    num1=map(int,input().split())
    for num in num1:
        dict[num] = 1

    m=int(input())
    num2=map(int,input().split())
    for num in num2:
        if num in dict:
            print("1")
        else:
            print("0")