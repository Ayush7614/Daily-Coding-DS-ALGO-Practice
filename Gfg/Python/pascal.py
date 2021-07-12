'''

Pascal's Triangle


Implementation:

0C0
1C0   1C1
2C0   2C1   2C2
3C0   3C1   3C2    3C3

'''


def Pascal(n):
    row = [1]
    y = [0]
    for x in range(max(n, 0)):
        print(row)
        row = [l+r for l, r in zip (row+y, y+row)]
    return n>=1
                
#main() 
print(Pascal(6))
