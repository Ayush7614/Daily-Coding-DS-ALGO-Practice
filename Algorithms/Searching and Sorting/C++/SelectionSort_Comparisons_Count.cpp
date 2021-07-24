#include <iostream>
using namespace std;

void selection(int arr[],int size) //selecttion sort function
{
    int comp=0,swaps=0;
  for(int i=0;i<=size-1;i++)
  {
      int temp=arr[i],min=9999,count,j;
      for( j=i;j<size;j++)
      {
           if(arr[j]<min)
           {
               min=arr[j];
               count=j;
               comp++;
           }
           else 
           {
               comp++;
           }
 
      }
      if(count!=j)
      {
      arr[i]=arr[count];
      arr[count]=temp;
      swaps++;
      }
      else 
      {
      arr[i]=arr[count];
      arr[count]=temp;
      }
  }
  cout<<"\nYour sorted array is: ";
  for(int i=0;i<size;i++)
  {
      cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"No. of comparisons: "<<comp<<endl;
  cout<<"No. of swaps: "<<swaps<<endl;

}
int selectionAuto(int arr[],int size) //selection sort function for automatic table
{
    int comp=0;
  for(int i=0;i<=size-1;i++)
  {
      int temp=arr[i],min=9999,count;
      for(int j=i;j<size;j++)
      {
           if(arr[j]<min)
           {
               min=arr[j];
               count=j;
               comp++;   
           }
           else 
           {
               comp++;
           }
      }
      arr[i]=arr[count];
      arr[count]=temp;
  }
  return comp;
}
int main(int argc, char const *argv[])
{
    int ch;
    do 
    {
    cout<<"\nNumber of Comprisons Table"<<endl<<endl;
    cout<<"\nHow do you want to proceed for Bubble sort?"<<endl;
    cout<<"\n1.Automatic(1-100)\n2.Custom\n3.Exit"<<endl;
    cin>>ch;
    if(ch==1)
    {
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
                vec[j]=rand()%i+2; //filling random values in array
            }
            int ans=selectionAuto(vec,i);
            c[count]=ans;
            count++;
            n--;
        }
        for(int k=1;k<=i;k++) //giving input of a sorted array 
        {
            vec[c2++]=k;
        }
        int ans2=selectionAuto(vec,i); 
        c[count]=ans2;
        count++;
        for(int l=i;l>0;l--) //giving input of a reverse sorted array 
        {
            vec[c3++]=l;
        }
        int ans3=selectionAuto(vec,i);
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

       // cout<<i<<"              "<<ans2<<"              "<<worst<<"              "<<avg<<endl;
       cout<<i<<"\t"<<ans2<<"\t\t"<<worst<<"\t\t"<<avg<<endl;
    }
    }
     else if(ch==2)
     {
    int size;
    int* arr;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    arr= new int[size];
    for(int i=0;i<size;i++)
    {
     cout<<"Enter element "<<i+1<<" ";
     cin>>arr[i];
    }
    cout<<"\nYour array is: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selection(arr,size);
     }
     else if(ch==3)
     {
         break;
     }
     else 
     {
         cout<<"wrong choice"<<endl;
     }
    }while(ch!=3);
    system("pause");
    return 0;
}
