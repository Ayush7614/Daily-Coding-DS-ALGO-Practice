import math
from collections import defaultdict

def encryption(text):
    text = text.replace(" ","")
    root= math.sqrt(len(text))
    r = math.floor(root)
    c = math.ceil(root)
    d = defaultdict(str)
    for i in range(0,len(text),c):
        sub = text[i:i+c]
        for x in range(len(sub)):
            d[x]+=sub[x]
    return(list(d.values()))

print(*encryption(input()))
