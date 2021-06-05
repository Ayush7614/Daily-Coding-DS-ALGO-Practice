from functools import cmp_to_key
class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def comparator(a, b):
        if a.score<b.score:
            return 1
        elif a.score==b.score:
            if a.name>b.name:
                return 1
            else:
                return -1
        else:
            return -1

n = int(input())
data = []
for i in range(n):
    name, score = input().split()
    score = int(score)
    player = Player(name, score)
    data.append(player)
    
data = sorted(data, key=cmp_to_key(Player.comparator))
for i in data:
    print(i.name, i.score)
