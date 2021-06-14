#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
   int count_0=0;
    int count_1=0;
    int count_2=0;
    int count_3=0;
    int count_4=0;
    int count_5=0;
    int count_6=0;
    int count_7=0;
    int count_8=0;
    int count_9=0;
    char num[1000];
    for (int i=0; i<strlen(num);i++) {
   
   scanf("%s",&num[i]);  
    }

    //for 0
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='0')
{
    // count=count+i;
    count_0++;
}
}
printf("%d",count_0);
printf(" ");

//for 1
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='1')
{
    // count=count+i;
    count_1++;
}
}
printf("%d",count_1);
printf(" ");

//for 2
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='2')
{
    // count=count+i;
    count_2++;
}
}
printf("%d",count_2);
printf(" ");
//for 3
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='3')
{
    // count=count+i;
    count_3++;
}
}
printf("%d",count_3);
printf(" ");
//for 4
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='4')
{
    // count=count+i;
    count_4++;
}
}
printf("%d",count_4);
printf(" ");
//for 5
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='5')
{
    // count=count+i;
    count_5++;
}
}
printf("%d",count_5);
printf(" ");

//for 6
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='6')
{
    // count=count+i;
    count_6++;
}
}
printf("%d",count_6);
printf(" ");

//for 7
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='7')
{
    // count=count+i;
    count_7++;
}
}
printf("%d",count_7);
printf(" ");

//for 8
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='8')
{
    // count=count+i;
    count_8++;
}
}
printf("%d",count_8);
printf(" ");

//for 9
for (int i = 0; i < strlen(num); i++)
{
if (num[i]=='9')
{
    // count=count+i;
    count_9++;
}
}
printf("%d",count_9);
printf(" ");


    return 0;
}

// All test will be succesfully passed when you run this code in Hackerrank 

// Input from Hackerrank -- a11472o5t6
// Expected Output --> 0 2 1 0 1 1 1 1 0 0 
// Our Output --> 0 2 1 0 1 1 1 1 0 0 
