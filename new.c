#include <stdio.h>
int convert(int days)
{
    int w,y;
    y=days/365;
    days-=y*365;
    w=days/7;
    days-=w*7;
    printf("Years : %d\nWeeks : %d\nDays : %d",&y,&w,&days);
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    convert(n);
    return 0;
}

