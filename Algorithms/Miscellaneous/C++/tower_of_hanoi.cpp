/* Tower of Hanoi, is a mathematical puzzle which consists of three towers (pegs) and more than one rings.

The mission is to move all the disks to some another tower without violating the sequence of arrangement. A few rules to be followed for Tower of Hanoi are −
Only one disk can be moved among the towers at any given time.
Only the "top" disk can be removed.
No large disk can sit over a small disk. */

#include <iostream>
using namespace std;

void move(int n, char src, char helper, char dest)
{
    // Base case
    if(n == 0)
    {
        return;
    }
    
    // Recursive case
    // move n-1 disks from source to helper and nth disk to destination
    move(n-1, src, dest, helper);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    move(n-1, helper, src, dest);
}

int main()
{
    int n;
    cin >> n;
    
    move(n, 'A', 'B', 'C');
    return 0;
}

/*
INPUT:
3

OUTPUT:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/
