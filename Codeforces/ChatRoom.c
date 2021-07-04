#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool SearchString(char* str);

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%s",str);

    if(strlen(str) < 5)
      printf("NO");
    else {
    if(SearchString(str) == true)
       printf("YES");
    else
       printf("NO");
    }

    return 0;
}

bool SearchString(char* str)
{
    char word_string[5] = "hello";
    int i = 0;
    int j = 0;

    while(word_string[i] != '\0')
    {
        while(str[j] != '\0')
        {
            if(str[j] == word_string[i])
            {
                str[j] = '0';
                break;
            }
            j++;
        }
        if(str[j] == '\0')
           return false;
        i++;
    }
    return true;
}

/* Chat Room
input: ahhellllloou
output: YES
input: hlelo
output: NO
*/