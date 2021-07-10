#include <iostream>
using namespace std;

//function to swap elements
void swap(int* a, int* b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void bubbleSort(int arr[],int size)
{
int comp=0,check,swaps=0;
for(int i=0;i<size-1;i++)
{
    check=-1;
    for(int j=0;j<size-1;j++)
    {
        if(arr[j]>arr[j+1]) //everytime the current element is greater than next element
        {
           swap(&arr[j], &arr[j+1]); //swap occurs
           comp++;                   //comparison count increments
           swaps++;                  // swaps count increments
           check=0;
        }   
       else 
       {
        comp++;
       }

    }
   
      if(check==-1)
        {
            break;
        }
}
cout<<"\nYour sorted array is: ";
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";
}
 cout<<"\nNo. of comparisons: "<<comp<<endl;
  cout<<"\nNo. of swaps: "<<swaps<<endl;
    cout<<endl;
}
int bubbleAuto(int arr[],int size)
{
int comp=0,check,swaps=0;
for(int i=0;i<size-1;i++)
{
    check=-1;
    for(int j=0;j<size-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           comp++;
           swaps++;
           check=0;
        }   
       else 
       {
        comp++;
       }

    }
   
      if(check==-1)
        {
            break;
        }
}
return comp;
}
int main(int argc, char const *argv[])
{
    int ch;
    do 
    {
    cout<<"\nHow do you want to proceed for Bubble sort?"<<endl;
    cout<<"\n1.Automatic(1-100)\n2.Custom\n3.Exit"<<endl;
    cin>>ch;
    if(ch==1)
    {
      cout<<"\nNumber of Comprisons Table"<<endl<<endl;
      cout<<"Input"<<"\t"<<"Best Cases"<<"\t"<<"Worst Cases"<<"\t"<<"Average Case"<<endl<<endl;
    for(int i=10;i<=100;i+=5)
    {
        int count=0,c2=0,c3=0;
        int vec[i],c[i+1];
        int n=i-1;
        while(n!=0)
        {
            for(int j=0;j<i;j++)
            {
                vec[j]=rand()%200; //filling random values in array
            }
            int ans=bubbleAuto(vec,i);
            c[count]=ans;
            count++;
            n--;
        }
        for(int k=1;k<=i;k++) //giving input of a sorted array for best case
        {
            vec[c2++]=k;
        }
        int ans2=bubbleAuto(vec,i); 
        c[count]=ans2;
        count++;
        for(int l=i;l>0;l--) //giving input of a reverse sorted array for worst case
        {
            vec[c3++]=l;
        }
        int ans3=bubbleAuto(vec,i);
        c[count]=ans3;
        int worst=ans3;
        count++;
        int sum=0;
        for(int m=0;m<count;m++)
        {
            sum+=c[m];
        }
        float avg;
        avg=(float)sum/count; //calculating average of all i+1 cases

        cout<<i<<"\t"<<ans2<<"\t\t"<<worst<<"\t\t"<<avg<<endl;
    }
    }
    else if(ch==2)
    {
    int size;
    int* arr;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    arr=new int[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the element :"<<i+1<<" ";
        cin>>arr[i];
    }
    bubbleSort(arr,size);
    cout<<endl;
    }
    else if(ch==3)
    {
        break;
    }
    else 
    {
        cout<<"Wrong choice"<<endl;
    }
    }while(ch!=3);

    system("pause");
    return 0;
}
