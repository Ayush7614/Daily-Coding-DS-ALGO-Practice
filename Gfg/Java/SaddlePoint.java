import java.util.Scanner;
class Saddle_DA
{
    public static void main(String args [])
    {
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter no. of rows ");
        int n = sc.nextInt();
        
        int ar[][] = new int[n][n];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                System.out.println("Enter a number ");
                ar[i][j] =  sc.nextInt();
                
            }
        }
        boolean found=false;
        for(int x=0;x<n;x++)
        {
            int i=0;
            for(int y=0;y<n;y++)
            {
                if(ar[x][y] < ar[x][i])
                {
                    i=y;
                }
            }
            
            boolean saddle=false;
            
            for(int r=0;r<n;r++)
            {
                if(ar[r][i] < ar[x][i])
                {
                    saddle=true;
                    break;
                }
            }
            
            if(saddle == true)
            {
                System.out.println("Saddle Point "+ar[x][i]);
                found = true;
                break;
            }
            
        }
        if(found==false)
        {
            System.out.println("No");
        }
    }
}