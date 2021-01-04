n=int(input())
'''
주어진 팰린드롬으로 끝말잇기를 할 수 있는가?
팰린드롬만 사용하므로 입력받는 문자열의 첫 문자가 동일해야한다.
'''
s=input().split()
ans=1
char=""
for i in range(len(s)):
    if(i==0):
        char=s[0][0]
    if(char!=s[i][0]):
        ans=0
        break

print(ans)