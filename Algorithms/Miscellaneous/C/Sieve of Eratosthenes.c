// C program to print all primes smaller than or equal to n using Sieve of Eratosthenes

#include<stdio.h>
int main(){
	int arr[100];
	int num,i,j;
	printf("Enter the n value: ");
	scanf("%d",&num);
    /* Create a array arr[0..n] and initialize all 
	entries it as 1. A value in arr[i] will
    finally be 0 if i is Not a prime, else 1.*/
	for(i=1;i<num+1;i++)
		arr[i]=1;
	for(i=2;i<=num;i++){  			  	
	//If arr[p] is not changed, then it is a prime
		if(arr[i]==1){
	/* Update all multiples of p greater than or equal to the square of it numbers 
	which are multiple of p and are less than p^2 are already been marked. */
			for(j=i*i;j<=num;j+=i){
				arr[j]=0;
			}
		}
	}
	for(i=2;i<=num;i++){				//loop for printing the primes
		if(arr[i]==1)
			printf("%d ",i);
	}
	return 0;
}

/*
----------------------
Sample input:
5

Output:
2 3 5
----------------------
Sample input2:
20

Output:
2 3 5 7 11 13 17 19
----------------------
*/
