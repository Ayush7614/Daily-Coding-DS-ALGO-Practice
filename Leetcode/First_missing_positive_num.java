/**
    Given an unsorted integer array nums, find the smallest missing positive integer.
    Implement an algorithm that runs in O(n) time and uses constant extra space. 
    Link to the problem :  https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/832/
    solution has time complexity : O(N)
                 space complexity : O(1)
         Input : [1,2,0]
         Output: 3

        Input: [3,4,-1,1]
        Output: 2 
    */
    import java.util.*;

    class solution
    {   
        //function to find the missing positive number
        static int findMissingPositive(int array[], int len)
        {
            int current,nextvalue=0;
            for(int index=0;index<len;index++)
            {   
                //skip all the values which are greater the size of array or negative or zero
                if(array[index]<=0 || array[index]>len)
                   continue;
                
                current=array[index];
                //iterate through array until we reach at an unvisited or already visited element
                while(array[current - 1] != current)
                {
                    nextvalue = array[current - 1];
                    array[current - 1] = current;
                    current = nextvalue;
                    if (current <= 0 || current > len)
                    break;
                }
            }    
            
            //when all the elements greater then 0 and less than length and
            //placed at correct index then length of array is returned
            for(int in=0;in<len;in++)
            {
                if (array[in] != (in + 1))
                 return (in + 1);
            }
            return len + 1;
            
        }
        public static void main(String args[]){
            Scanner sc=new Scanner(System.in);
            int lengthOfArray=sc.nextInt();
            int array[]=new int[lengthOfArray];
            for(int index=0;index<lengthOfArray;index++)
            {
                array[index]=sc.nextInt();
            }
            int result=findMissingPositive(array,lengthOfArray);
            System.out.println("the smallest missing positive integer is :"+result);
            sc.close();
        }
    
    }