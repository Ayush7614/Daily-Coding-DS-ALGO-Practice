#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the camelcase function below.
int camelcase(char* s) {
    int i,n=1;
    int len = strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            n++;
        }
    }
    return n;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    char* s = readline();
    int result = camelcase(s);
    fprintf(fptr, "%d\n", result);
    fclose(fptr);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) { break; }
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }
        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);
        if (!data) { break; }
        alloc_length = new_length;
    }
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }
    data = realloc(data, data_length);
    return data;
}
