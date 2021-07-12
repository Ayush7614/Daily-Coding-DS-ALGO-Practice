// In this problem we have given 3 rod that is source,destination,temporary
// And we have given n disk, we have to move one disk at a time from source to destination using temporary rod such that the upper disk should placed on lower disk
// we have to Print the instructions to move the disks.

import java.util.*;

public class TowerOfHanoi
{
    public static void main(String[] args)
    {
        // taking input from user that is n disk
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
          
          // this are 3 rod
          char s = 's';
          char d = 'd';
          char t = 't';
          twh(n,s,d,t);
    }
    public static void twh(int n,char src,char dest,char temp)
    {
        if(n==0)
        {
            return ;
        }

        // we can move n-1 disk to temp
        twh(n-1,src,temp,dest);

        // moving nth disk source to dest
        System.out.println(n +" [" +src +"->" + dest + "]");

        // moving remaining disk from temp to destn
        twh(n-1,temp,dest,src);

    }
}