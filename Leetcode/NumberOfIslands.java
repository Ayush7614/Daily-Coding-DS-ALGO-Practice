class Solution {
    public int numIslands(char[][] arr) {
     int ans=0 ;
     int m=arr.length ;
     int n=arr[0].length ;
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             if(arr[i][j]=='1'){
             countIs(arr,i,j) ;
             ans++ ;
             }
         }
     }
        
     return ans ;
    }
    
     public static void countIs(char [][]arr,int row,int col){
       // boundary conditions
       if(row<0||col<0||row==arr.length||col==arr[0].length||arr[row][col]=='0')
       return ;
       
       // mark the island once you have visited it
       arr[row][col]='0' ;
       
       countIs(arr,row-1,col);
       
       countIs(arr,row,col-1);
       
       countIs(arr,row+1,col);
       
       countIs(arr,row,col+1);
       
       
   }

}