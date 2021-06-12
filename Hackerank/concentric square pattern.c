//Program to Concentric square Pattern in C Language:


#include<stdio.h>


//Defination Of printPattern Function: 
void printPattern(int num){
    
    //Finding The sizeOfArray
    int sizeOfArray=(2*num)-1;
    
    //initialize start to 0 and end to size-1:
    int start=0;
    int end=sizeOfArray-1;
    
    //Creating an array 
    int array[sizeOfArray][sizeOfArray];
    
    while(num!=0){
        for(int i=start; i<=end; i++){
            for(int j=start; j<=end; j++){
                
                //Checking Possibile Conditions & Assign in array :
                if(i==start||i==end||j==start||j==end){
                    array[i][j]=num;
                }
            }
        }
        
        //increment start & Decerement end & Decerement num:
        start++;
        end--;
        num--;
    }
    
    
    //Printing The 2D array:
    for(int i=0; i<=sizeOfArray-1; i++){
            for(int j=0; j<=sizeOfArray-1; j++){
                
                printf("%d",array[i][j]);
            }
            printf("\n");
    }
}


//Driver Code:
void main(){
    
    //Take Input From User & Assign to num:
    int num;
    printf("Enter The No: ");
    scanf("%d",&num);
    
    //Call printPattern Function with num Argument:
    printPattern(num);
    
            
}

// This Program is Contributed by Abhay Tiwari

