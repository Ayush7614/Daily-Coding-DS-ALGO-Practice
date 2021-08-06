/*      PRINT SUPER DIGIT OF A NUMBER
    Author : MOHIT KUMAR KUSHWAHA
    Github : KimtVak8143


PRE-REQ: SUPERDIGIT : ADDITION OF DIGITS OF A NUMBER,
    RECURSIVELY TO OBTAIN A SINGLE DIGIT RESULT

EXAMPLE TEST CASE :
    INPUT:
    Enter the number :  9875
    Enter the no of times of occurrence of that number  : 4


    OUTPUT :
    The Super Digit of 9875 is : 8


*/

#include<stdio.h>
int sumd(int);
int superd(int);

int main()
{   int num;
    printf("Enter the number :\t");
    scanf("%d",&num);
    int xnum=sumd(num); //sum of digits of number
    printf("The Super Digit of %d :\t ",num);
    printf("%d",superd(xnum));
    return 0;
}

int superd(int num)
{   int n=0;
    return (num%9==0)? n=9:num%9; // calculate superdigit of num*k
}

int sumd(int n)
{   int k,sum=0;
    printf("Enter the no of times of occurence of that number :\t");
    scanf("%d",&k);
    while(n)
    {   sum+=n%10;
        n/=10;
    }
    return sum*k;
}
