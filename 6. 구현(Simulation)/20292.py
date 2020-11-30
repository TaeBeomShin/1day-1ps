w,r,to=[],[],[]
while(True):
    sentence=input("")
    if (sentence == "EXIT"):
        print(sentence)
        break
    if("WRITE" in sentence):
        a,b=sentence[6:].split(" TO ")
        if(b in r or (a in to and b in w) or a in to or b in to or (a in w and b in to)):
            w, r, to = [], [], []
            print("WAIT")
        w.append(a)
        to.append(b)
    elif("READ" in sentence):
        c=sentence[5:]
        if(c in to):
            w,r,to=[],[],[]
            print("WAIT")
        r.append(c)
    print(sentence)