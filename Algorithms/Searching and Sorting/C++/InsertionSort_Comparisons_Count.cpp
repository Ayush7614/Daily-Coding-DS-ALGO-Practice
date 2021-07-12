#include <iostream>
#include <vector>
using namespace std;

int insert(int vec[],int size) //insertion sort function for automatic input
{
    int comp=0;
    for(int k=1;k<size;k++)
    {
        int key=vec[k];
        int l=k-1;
        while(l>=0 && vec[l]>key)
        {
            vec[l+1]=vec[l];
            l--;
            comp++;
        }
        if(vec[l]<key)
        {
            vec[l+1]=vec[l];
            comp++;
        }
        vec[l+1]=vec[l];
    }
    return comp;
}
int main(int argc, char const *argv[])
{
    int ch;
    do 
    {
    cout<<"\nHow do you want to proceed for insertion sort?"<<endl;
    cout<<"\n1.Automatic(1-100)\n2.Custom\n3.Exit"<<endl;
    cin>>ch;
    if(ch==1)
    {
      cout<<"\nNumber of Comprisons Table"<<endl<<endl;
      cout<<"Size"<<"\t"<<"Best Cases"<<"\t"<<"Worst Cases"<<"\t"<<"Average Case"<<endl<<endl;    for(int i=10;i<=100;i+=5)
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
            int ans=insert(vec,i);
            c[count]=ans;
            count++;
            n--;
        }
        for(int k=1;k<=i;k++) //giving input of a sorted array for best case
        {
            vec[c2++]=k;
        }
        int ans2=insert(vec,i); 
        c[count]=ans2;
        count++;
        for(int l=i;l>0;l--) //giving input of a reverse sorted array for worst case
        {
            vec[c3++]=l;
        }
        int ans3=insert(vec,i);
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

        cout<<i<<"\t"<<i-1<<"\t\t"<<worst<<"\t\t"<<avg<<endl;    
        }
    }
    else if(ch==2) // custom input
    {
        int size,comp=0,movement=0;
    int* arr;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    arr=new int[size];
    for(int i=0;i<size;i++)
    {
       cout<<"Enter the element "<<i+1<<" :"<<" ";
       cin>>arr[i];
    }
     for(int i=1;i<size;i++)
    {
        int key=arr[i];
        int j=i-1;
        
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
            movement++;
            comp++;
        }
        if(arr[j]<key)
        {
            comp++;
            arr[j+1]=key;
        }
        arr[j+1]=key;
    }
    cout<<"\nYour sorted array is:"<<" ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nNumber of comparisons :"<<" "<<comp<<endl;
    cout<<"Number of movements :"<<" "<<movement<<endl;
    }
    else if(ch==3)
    {
        break;
    }
    else
    {
        cout<<"Wrong choice";
    }
    
    }while(ch!=3);
    system("pause");
    return 0;
}
