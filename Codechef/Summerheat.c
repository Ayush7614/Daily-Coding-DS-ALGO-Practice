/*
Problem statement: Given Chefland has 2 different types of coconut, type A and type B. Type A contains only xa milliliters of coconut water 
and type B contains only xb grams of coconut pulp. Chef's nutritionist has advised him to consume Xa milliliters of coconut water and Xb grams 
of coconut pulp every week in the summer. Find the total number of coconuts (type A + type B) that Chef should buy each week to keep himself active
in the hot weather. */
//Solution:

#include<stdio.h>
#include<conio.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
int xa,xb,Xa,Xb;
scanf("%d%d%d%d",&xa,&xb,&Xa,&Xb);
int p=Xa/xa; //No.of coconuts of typeA required
int q=Xb/xb; //No.of coconuts of typeB required
printf("%d\n",p+q); //Total no.of cocnuts required
}
return 0;
}