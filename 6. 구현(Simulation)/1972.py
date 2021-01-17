def check_word(w):
    # i : 두문자 사이의 거리, j : 첫문자의 인덱스
    for i in range(1,len(w)):
        dict={}
        for j in range(len(w)-i):
            new_word=w[j]+w[j+i]
            if(new_word in dict):
                return False
            dict[new_word]=1
    return True

while(True):
    word=input()
    if(word=='*'): break
    if(len(word)<=2 or check_word(word)):
        print(word,"is surprising.")
    else:
        print(word,"is NOT surprising.")
