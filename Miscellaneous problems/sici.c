#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int simple(int,int,int);
int compound(int,int,int);
int main()
{   int t;
    printf("\nEnter the number of test cases :\t");
    scanf("%d",&t);
    while(t--)
    {   int choice,p,r,t;
        float amount;
        printf("Enter the Principal Amount :\t");
        scanf("%d",&p);
        printf("Enter the rate of interest :\t");
        scanf("%d",&r);
        printf("Enter the Time Period :\t");
        scanf("%d",&t);
        printf("\nEnter the choice :\t");
        scanf("%d",&choice);
        switch(choice)
        {   case 1: amount=(p*r*t)/100;break;
            case 2: amount= p*(pow((1+r/100),t));break;
            default: printf("Invalid Choice\n");break;
        }
        printf("\nThe Amount is :\t%.2f",amount);
    }
    return 0;
}