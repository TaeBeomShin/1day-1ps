n,k=map(int,input().split())

for i in range(n):
    pixels=input().split()
    for j in range(k):
        for pixel in pixels:
            for s in range(k):
                print(pixel,end=" ")
        print()