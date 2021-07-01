#include <stdio.h>

int main(void)
{
    int t;//t is the number of test cases provided
    scanf("%d",&t);

    while(t--)//this loops t times since it is postdecrement
    {
        int n;//n is the length of the String
	      int k;//k is the number of consecutive * needed for the string to be Strong
        scanf("%d%d",&n,&k);

        char str[n+1];//String

	/* String declaration must contain atleast one more than the maximum number of characters you want it to be able to hold since strings are terminated with a NULL character.*/

        scanf("%s",str);

        int flag=0;//flag helps us evaluate if we were able to find k consecutive '*'.
        int count=0;

        for(int i=0;i<n;i++)//looping through the string
        {
            if(str[i]=='*')
            {
                count++;
                if(count>=k)//this if helps us determine if our condition of consecutive * is met
                {
                    flag=1;
                    break;//break because finding one such consecutive pair is enough and so we can save some time
                }
            }
            else//if theres any non * in between,then count resets to 0
            {
                count=0;
            }
        }
        if(flag==1)//cheking if we were successful
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    /*thus the meat of the program takes o(n) time*/

	return 0;
}
