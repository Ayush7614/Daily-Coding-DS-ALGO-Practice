<<<<<<< HEAD
/*
This is a program to calculate the factorial of large numbers whose digits can exceed the count of 40+.

*/

#include<bits/stdc++.h>

using namespace std;


#define MAX 500 //initialsing the size of multiplicative array to be 500

int multiply(int x,int res[],int res_size); 

void factorial(int n) { // functio to give the next number to multiplied to the multiplicative array

	int res[MAX];// initialising the multiplicative array

	res[0]=1; // initialising the first element to be 1 as n*1=n

	int res_size=1;//intially taking the array(to be used)size to be=1

	for(int x=2;x<=n;x++) {
		res_size=multiply(x,res,res_size); // calling the actual function which will multiply the multiplicative array with the next number in the series
	}

	cout<<"Factorial of given no is"<<endl;

	for(int i=res_size-1;i>=0;i--) {
		cout<<res[i]; // printing the result of the array in the reverse order
	}


}


int multiply(int x,int res[],int res_size) { // fucntion that uses the 
	int carry=0; //initialising the carry to be 0.

	for(int i=0;i<res_size;i++) {
		int prod=res[i]*x+carry; //multiplying the array elemnents by the number and adding the carry to it
		res[i]=prod%10; // storing just the unit's digit at that place;
		carry=prod/10;// taking the rest of the product's digits as carry
	}

	while(carry) { // while the carry remains, i.e. the last element case is being taken into consideration
		res[res_size]=carry%10; // allocating just the unit's digit to the last position
		carry=carry/10; // taking the other digits of the carry
		res_size++;// increasing the size(use part of the array) so as to store the rest of the digits
	}

	return res_size;//returning the remaining size
}

int main() {

factorial(100); // calculating the factorial 

	return 0;
=======
/*
This is a program to calculate the factorial of large numbers whose digits can exceed the count of 40+.

*/

#include<bits/stdc++.h>

using namespace std;


#define MAX 500 //initialsing the size of multiplicative array to be 500

int multiply(int x,int res[],int res_size); 

void factorial(int n) { // functio to give the next number to multiplied to the multiplicative array

	int res[MAX];// initialising the multiplicative array

	res[0]=1; // initialising the first element to be 1 as n*1=n

	int res_size=1;//intially taking the array(to be used)size to be=1

	for(int x=2;x<=n;x++) {
		res_size=multiply(x,res,res_size); // calling the actual function which will multiply the multiplicative array with the next number in the series
	}

	cout<<"Factorial of given no is"<<endl;

	for(int i=res_size-1;i>=0;i--) {
		cout<<res[i]; // printing the result of the array in the reverse order
	}


}


int multiply(int x,int res[],int res_size) { // fucntion that uses the 
	int carry=0; //initialising the carry to be 0.

	for(int i=0;i<res_size;i++) {
		int prod=res[i]*x+carry; //multiplying the array elemnents by the number and adding the carry to it
		res[i]=prod%10; // storing just the unit's digit at that place;
		carry=prod/10;// taking the rest of the product's digits as carry
	}

	while(carry) { // while the carry remains, i.e. the last element case is being taken into consideration
		res[res_size]=carry%10; // allocating just the unit's digit to the last position
		carry=carry/10; // taking the other digits of the carry
		res_size++;// increasing the size(use part of the array) so as to store the rest of the digits
	}

	return res_size;//returning the remaining size
}

int main() {

factorial(100); // calculating the factorial 

	return 0;
>>>>>>> 160b5fea7adaab7c4fc38384601c5d679a5c8d40
}