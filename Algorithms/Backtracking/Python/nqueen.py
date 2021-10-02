""" 
This code gives the coordinates to put "N" queens on a chess board, without blocking each other.
It is solved by backtracing.


Sample Input

4

Sample Output

(0, 1)

(1, 3)

(2, 0)

(3, 2)

Try any value of N in the code

"""


def add(i,j):
    board['queen'][i]=j
    board['col'][j]=1
    board['row'][i]=1
    board['d1'][j-i]=1
    board['d2'][j+i]=1 

def undo(i,j):
    board['queen'][i]=-1
    board['col'][j]=0
    board['row'][i]=0
    board['d1'][j-i]=0
    board['d2'][j+i]=0
    
def free(i,j):
    if board['row'][i]==0 and board['col'][j]==0 and board['d1'][j-i]==0 and board['d2'][j+i]==0:
        return True
    else:
        return False
    
def place(i):
    n=len(board['queen'].keys())
    for j in range(n):
        if free(i,j):
            add(i,j)
            if i==n-1:
                return True
            else:
                extend=place(i+1)
            if extend:
                return True
            else:
                undo(i,j)
    else:
        return False
        
n=int(input())
board={'queen':{},'row':{},'col':{},'d1':{},'d2':{}}
for i in range(n):
        board['row'][i]=0
        board['col'][i]=0
        board['queen'][i]=-1
        for i in range(-(n-1),n):
            board['d1'][i]=0
        for i in range((2*n)-1):
            board['d2'][i]=0

if place(0):
    x=sorted(board['queen'].keys())
    for cell in x:
        print((cell,board['queen'][cell]))


    