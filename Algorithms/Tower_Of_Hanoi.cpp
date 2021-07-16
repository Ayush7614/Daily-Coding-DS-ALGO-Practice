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
