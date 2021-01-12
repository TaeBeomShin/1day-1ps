N = int(input())
cards = [i for i in range(1, N+1)]
move = False
while cards:
    if not move:
        print(cards.pop(0), end=" ")
        move = True
    else:
        cards.append(cards.pop(0))
        move = False