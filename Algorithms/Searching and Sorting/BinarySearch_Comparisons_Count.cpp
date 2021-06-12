#include <iostream>
using namespace std;

int comparison=0;  //for keeping count of comparisons
int binary(int arr[],int first,int last,int key) //binary search function
{
	if(last>=first)
	{
	int mid=(first+last)/2;
	comparison++;
	if(arr[mid]==key)
	{
		return mid;
	}
	else if(arr[mid]>key)
	{
		return binary(arr,first,mid-1,key);
	}
	else if(arr[mid]<key)
	{
		return binary(arr,mid+1,last,key);
	}
	}
	return -1;
}
float avg(int arr[],int size) //function which returns average
{
	int sum=0;
	float a;
	for(int i=0;i<size;i++)
	{
       sum+=arr[i];
	}
     a=(float)sum/size;
	 return a;
}
int main(int argc, char const *argv[])
{
	int ch;
	do 
	{
	cout<<"\nHow do you want to proceed with binary search?"<<endl;
	cout<<"1.Automatic(1-100)\n2.Custom input\n3.Exit"<<endl;
    cin>>ch;
	if(ch==1)
	{
		cout<<"\nNumber of Comprisons Table"<<endl<<endl;
       cout<<"Size"<<"\t"<<"Best Cases"<<"\t"<<"Worst Cases"<<"\t"<<"Average Case"<<endl<<endl;
	for(int i=10;i<=100;i+=5)
	{
		int count=0;
		int comp[i+1],k=0;
		int arr[i];
		for(int j=1;j<=i;j++)
		{
            arr[count++]=j; //filling values in array
		}
		int n=i+1;
		while(n!=0)
		{
		int key=n; //assigning an element to search ranging 1 to i+1
        int res=binary(arr,0,i-1,key);
        comp[k++]=comparison;
		comparison=0;
		n--;
		}
		int max=comp[0];
	    for(int l=0;l<k;l++)
	      {
		     if(comp[l]>max)
		    {
			    max=comp[l];
		    }
	      }
		  float a=avg(comp,k);
		  cout<<i<<"\t"<<max<<"\t\t"<<"1"<<"\t\t"<<a<<endl;
	}
	}
	else if(ch==2)
	{
	int size,key,n,k=0,worst,sum=0;
	float avg;
	int *arr,*comp;
	cout<<"Enter the size of array(please enter the sorted array)"<<endl; //or you can take input in any form and sort it yourself
	cin>>size;
	n=size+1;
	comp=new int[n];
	arr=new int[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element "<<i<<" :"<<" ";
		cin>>arr[i];
	}
	while(n!=0)
	{
    cout<<"Enter the element to be searched"<<endl;
	cin>>key;
	int pos=binary(arr,0,size-1,key); //position of element
	if(pos==-1)
	{
		cout<<"Element not found"<<endl;
		cout<<"No. of comparisons :"<<" "<<comparison<<endl;
	}
	else 
	{
            cout<<"Element is at position :"<<" "<<pos<<endl;
	        cout<<"No. of comparisons :"<<" "<<comparison<<endl;
	}
	comp[k++]=comparison;
	comparison=0;
	n--;
	}
	int max=comp[0];
	for(int i=0;i<k;i++)
	{
		if(comp[i]>max)
		{
			max=comp[i]; //finding worst case in comparisons array 
		}
	}
	for(int i=0;i<k;i++)
	{
      sum+=comp[i];
	}
	avg=(float)sum/k; //calculating average
	cout<<endl;
	cout<<"Comparisons in best case"<<" :"<<" "<<1<<endl;
	cout<<"Comparisons in worst case"<<" :"<<" "<<max<<endl;
	cout<<"Comparisons in avg case"<<" :"<<" "<<avg<<endl;
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

	
