#include<stdio.h>

void convert(int n,int x)
{   switch(n)
    {   case 1: printf("%d Years = %d Minutes",x,x*525600);break;
        case 2: printf("%d Years = %d Hours",x,x*8760);break;
        case 3: printf("%d Years = %d Days",x,x*365);break;
        case 4: printf("%d Years = %d Months",x,x*12);break;
        case 5: printf("%d Years = %ld Seconds",x,x*31536000);break;
        default: printf("\nInvalid Input");
    }
}

int main()
{   int year,choice;
    printf("Welcome\nThe Menu\n");
    printf("1- Into Minutes\n");
    printf("2- Into Hours\n");
    printf("3- Into Days\n");
    printf("4- Into Months\n");
    printf("5- Into Seconds");
    printf("\nEnter Choice :\t");
    scanf("%d",&choice);
    printf("\nEnter the year :\t");
    scanf("%d",&year);
    convert(choice,year);
    return 0;
}
