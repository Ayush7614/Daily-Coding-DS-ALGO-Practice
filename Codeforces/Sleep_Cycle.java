import java.util.*;
 class MyClass {
    //  forming array which contains the count of continuous zeros
    public static void clusters(String s,int h,int a[])
    {int c1=0;
    int c2=0;
        for(int x=0;x<h;x++)
        {
            char ch=s.charAt(x);
            if(ch=='0')
            {
                c1=c1+1;
            }
            else{
                if(c1!=0)
                    a[c2]=c1;
                c2=c2+1;
                c1=0;
            }
        }
        if(c1>0)
           a[c2]=c1;
        
    }
    public static void main(String args[]) {
    Scanner sc=new Scanner(System.in);
    int t=sc.nextInt();
    for(int x=1;x<=t;x++)
    {
         
        int n=sc.nextInt();
        int a[]=new int[n];
        int h=sc.nextInt();
        String s=sc.next();
        clusters(s,n,a);
        int flag=0;
        for(int x1=0;x1<n;x1++)
        {
            if(a[x1]!=0)
            {
                if(a[x1]>=h)
                {
                    flag=1;
                    break;
                }
                else if (a[x1]>h/2)
                {
                    h=2*(h-a[x1]);
                }
            }
        }
        String ans = flag == 1 ? "YES" : "NO";
        System.out.println(ans);
    }
    }
}

// Input
// 4
// 3 1
// 111
// 3 1
// 101
// 7 5
// 0000100
// 6 5
// 000010


// Output
// NO
// YES
// YES
// NO



