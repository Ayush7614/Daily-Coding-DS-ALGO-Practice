#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
return strcmp(b, a);
}

int characters_count(const char *s)
{
    int n = 0;
    int count[128] = {0};
    if (NULL == s)
    {
        return -1;
    }
    while(*s != '\0')
    {
        if (!count[*s])
        {
            count[*s]++;
            n++;
        }
        s++;
    }
    return n;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int con = characters_count(a) - characters_count(b);
    return (con ? con : lexicographic_sort(a, b));
}

int sort_by_length(const char* a, const char* b) {
 int len = strlen(a) - strlen(b);
    return (len ? len : lexicographic_sort(a, b));
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
 int mid = len / 2;
    int con = 0;
    while(!con)
    {
        con = 1;
        for(int i = 0; i < len - 1; i++)
        {
            if(cmp_func(arr[i], arr[i + 1]) > 0) 
            {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                con = 0;
            }
        }
    }
}
