#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s, int i, int j){
    char * tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void reverse(char **s, int start, int end){
    while(start<end){
        swap(s,start++,end--);
    }
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
     for(int i=n-2;i>-1;i--)
     {
        if(strcmp(s[i+1],s[i])>0)
        {
            for(int j=n-1;j>i;j--)
            {
                if(strcmp(s[j],s[i])>0)
                {
                    swap(s,i,j);
                    reverse(s,i+1,n-1);
                    return 1;
                }
            }
        }
    }
    return 0;
}
