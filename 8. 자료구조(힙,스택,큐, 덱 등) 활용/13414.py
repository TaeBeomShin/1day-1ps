'''
1. 중복되는 목록 삭제(앞에 클릭한 걸 없앰.)-> map자료형 이용.
2. 맨앞에서부터 k명 선정.
3. 더 적은 인원이 수강신청 할 수 있음.
'''

k,l=map(int,input().split())
dict={}

for i in range(l):
    num=input()
    dict[num]=i

l=sorted(list(dict.items()),key=lambda k:(k[1]))

k=min(k,len(l))
for i in range(k):
    print(l[i][0])
