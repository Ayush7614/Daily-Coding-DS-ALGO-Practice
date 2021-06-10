//**************************  ROTATION OF ARRAY BY K ELEMENT ***********************//
/*
INPUT: 
7
3 5 8 4 13 9 10
2
OUTPUT: 8 4 13 9 10 3 5 
*/
#include <iostream>
using namespace std;

void rotate(int *input, int k, int n)   {
	
    int arr[n],j=0,p=0; // MAKING A TEMPORARY ARRAY OF SIZE n STORE ROTATED ELEMNTS (arr[n]),j (IT WILL TRACK THE INDICES OF TEMP ARRAY),p(IT WILL TRACK THE INDICES OF INPUT ARRAY )
    
    for(int i=k;i<n;i++){
        arr[j]=input[i]; //TAKING THE ELEMENTS OF INPUT ARRAY FROM (k to (n-1)) TO THE TEMPORARY ARRAY FOR TAKING THE ALL RIGHT ELEMNTS OF THE ELEMENT k
        j++;            //j=INDICES OF TEMPORARY ARRAY(array[n])
    }
   for(int i=j;i<n;i++){
       
       arr[i]=input[p]; // TAKING THE REST ELEMNTS OF INDICES 0 TO K-1 OF INPUT ARRAY TO THE TEMPORARY ARRAY (array[n]) WHICH WILL STORE FROM INDICES (j) 
      p++;          //p=INDICES OF INPUT ARRAY
   } 
   for(int i=0;i<n;i++){
       input[i]=arr[i]; //REPLACING ALL ELEMNT OF TEMPORARY ARRAY TO INPUT ARRAY
   } 
    
    
}
int main()
{
	
	
		int size;
		cin >> size; // TAKING INPUT OF ARRAY SIZE

		int input[size]; // MAKING ARRAY OF SIZE (size) 

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];          //TAKING INPUT OF ARRAY
		}

		int K;
		cin >> K;   // TAKING INPUT OF  K 

		rotate(input, K, size); // CALLING ROTATE FUNCTION

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";  //PRINTING THE ROTATED ARRAY
		}
		
		 
		cout << endl;
	

	return 0;
}








