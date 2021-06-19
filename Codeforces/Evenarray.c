/*Problemstatement: ou are given an array a[0…n−1] of length n which consists of non-negative integers. Note that array indices start from zero.
An array is called good if the parity of each index matches the parity of the element at that index.An array is good if for all i (0≤i≤n−1)
the equality imod2 = a[i]mod2 holds, where xmod2 is the remainder of dividing x by 2.Find the minimum number of moves in which you can make
the array a good, or say that this is not possible. */

//Solution:

#include<stdio.h>
#include<conio.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
int n;
scanf("%d",&n);
int arr[n],a=0,b=0;
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
for(int i=0;i<n;i++){
if(arr[i]%2 !=i%2){ // checking equality holds or not.
if(i%2 ==0){
a++;
}
else{
b++;
}
}
}
if(a!=b){
printf("-1\n");
}
else{
printf("%d\n",a);
}
}
return 0;
}


