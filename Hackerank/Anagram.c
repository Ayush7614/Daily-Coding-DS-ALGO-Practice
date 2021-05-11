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

// Complete the anagram function below.
int anagram(char* s) {
    int l=strlen(s),c=0;
    if(l%2!=0)
    {
        return -1;
    }
    int h1[26]={0},h2[26]={0},i;
    for(i=0;i<l/2;i++)
        h1[s[i]-'a']++;
    for(i=l/2;i<l;i++)
        h2[s[i]-'a']++;
    for(i=0;i<26;i++)
    {
        h1[i]=h1[i]-h2[i];
        if(h1[i]>0)
            c=c+abs(h1[i]);
    }
    return c;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);
    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }
    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* s = readline();
        int result = anagram(s);
        fprintf(fptr, "%d\n", result);
    }
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
