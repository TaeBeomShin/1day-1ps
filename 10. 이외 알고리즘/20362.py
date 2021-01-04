'''
당첨자 보다 정답을 빨리 외친 사람 찾기.
'''
n,name=input().split()
idx,l,chat=0,[],""

for i in range(int(n)):
    person,answer=input().split()
    l.append([person,answer])
    if(person==name):
        idx=i
        chat=answer

ans=0
for people in l:
    if(people[0]==name):break
    if(people[1]==chat): ans+=1

print(ans)