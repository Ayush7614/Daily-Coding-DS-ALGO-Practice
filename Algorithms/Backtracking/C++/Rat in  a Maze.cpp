#include <iostream>
using namespace std;
bool isSafe(int** arr,int x,int y,int n)
{
    if(x<n && y<n && arr[x][y]==1)
    return true;
    return false;
}
bool ratInMaze(int** arr, int x,int y,int n,int** solnArr)
{
    if(x==n-1 && y==n-1)
    {
        solnArr[x][y]=1;
        return true;
    }
    if(isSafe(arr,x,y,n))
    {
        solnArr[x][y]=1;
        if(ratInMaze(arr,x+1,y,n,solnArr))
        return true;
        if(ratInMaze(arr,x,y+1,n,solnArr))
        return true;
        solnArr[x][y]=0;
        return false;
    }
    return false;
}
int main()
{
    cout<<"enter size";
    int n;
    cin>>n;
    int** arr =new int* [n];
    for(int i=0;i<n;i++)
    arr[i]=new int [n];

    int** solnArr=new int *[n];
    for(int i=0;i<n;i++)
    {
        solnArr[i]=new int [n];
        for(int j=0;j<n;j++)
        solnArr[i][j]=0;
    }
     cout<<"Input Maze"<<endl;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         cin>>arr[i][j];
     }
     cout<<endl<<endl;
     if(ratInMaze(arr,0,0,n,solnArr))
     {
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             cout<<solnArr[i][j]<<" ";
             cout<<endl;
         }
     }
}

// 1 0 1 0 1                  1 0 0 0 0
// 1 1 1 1 1                  1 1 1 1 0
// 0 1 0 1 0    output->      0 0 0 1 0
// 1 0 0 1 1                  0 0 0 1 1
