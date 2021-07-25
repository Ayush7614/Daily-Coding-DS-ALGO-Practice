//C++ program for solving problem of tower of Hanoi using recursion.
//Firstly n-1 discs from A(source) to B(helper).
//Then nth disc from A to C(destination).
//Lastly n-1 discs from B to C.

#include <iostream>
using namespace std;

void towerOfHanoi(int n,char src, char dest, char helper){
	if(n==0){
		return;//Base case
	}
	//moving n-1 discs from A to B
	towerOfHanoi(n-1,src,helper,dest);
	//moving last disc from A to C
	cout<<" Move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<endl;
	//moving n-1 discs from B to c
	towerOfHanoi(n-1,helper,dest,src);
}

int main(){
	int n;
	cout<<"Enter the number of disks"<<endl;
	cin>>n;
	towerOfHanoi(n,'A','C','B');
	return 0;
}
//TEST CASES
//1. n=3
//output: Move disk 1 from rod A to rod C
//Move disk 2 from rod A to rod B
//Move disk 1 from rod C to rod B
//Move disk 3 from rod A to rod C
//Move disk 1 from rod B to rod A
//Move disk 2 from rod B to rod C
//Move disk 1 from rod A to rod C
//2. n=5
//output:  Move disk 1 from rod A to rod C
// Move disk 2 from rod A to rod B
// Move disk 1 from rod C to rod B
// Move disk 3 from rod A to rod C
// Move disk 1 from rod B to rod A
// Move disk 2 from rod B to rod C
// Move disk 1 from rod A to rod C
// Move disk 4 from rod A to rod B
// Move disk 1 from rod C to rod B
// Move disk 2 from rod C to rod A
// Move disk 1 from rod B to rod A
// Move disk 3 from rod C to rod B
// Move disk 1 from rod A to rod C
// Move disk 2 from rod A to rod B
// Move disk 1 from rod C to rod B
// Move disk 5 from rod A to rod C
// Move disk 1 from rod B to rod A
// Move disk 2 from rod B to rod C
// Move disk 1 from rod A to rod C
// Move disk 3 from rod B to rod A
// Move disk 1 from rod C to rod B
// Move disk 2 from rod C to rod A
// Move disk 1 from rod B to rod A
// Move disk 4 from rod B to rod C
// Move disk 1 from rod A to rod C
// Move disk 2 from rod A to rod B
// Move disk 1 from rod C to rod B
// Move disk 3 from rod A to rod C
// Move disk 1 from rod B to rod A
// Move disk 2 from rod B to rod C
// Move disk 1 from rod A to rod C
