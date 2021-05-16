#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
 return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
 return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
return document[k - 1];
}

char**** get_document(char* text) {
char ****doc = NULL;
    int i_paragraph = 0;
    int i_sentence = 0;
    int i_word = 0;

    doc = (char ****) malloc(sizeof(char ***));
    doc[0] = (char ***) malloc(sizeof(char **));
    doc[0][0] = (char **) malloc(sizeof(char *));

    char *word = NULL;

    for (char *s = text; *s; ++s)
    {
        if (*s == ' ' || *s == '.')
        {
            fprintf(stderr, "add word p%d s%d w%d: %.*s\n", i_paragraph, i_sentence, i_word, (int)(s - word), word);
            doc[i_paragraph][i_sentence][i_word] = word;

            i_word++;
            doc[i_paragraph][i_sentence] = (char **) realloc(doc[i_paragraph][i_sentence], sizeof(char *) * (i_word + 1));

            if (*s == '.' && s[1] != '\n')
            {
                i_word = 0;
                i_sentence++;

                doc[i_paragraph] = (char ***) realloc(doc[i_paragraph], sizeof(char **) * (i_sentence + 1));
                doc[i_paragraph][i_sentence] = (char **) malloc(sizeof(char *));
            }

            *s = 0;
            word = NULL;
        }

        else if (*s == '\n')
        {
            *s = 0;
            word = NULL;

            i_word = 0;
            i_sentence = 0;
            i_paragraph++;

            doc = (char ****) realloc(doc, sizeof(char ***) * (i_paragraph + 1));
            doc[i_paragraph] = (char ***) malloc(sizeof(char **));
            doc[i_paragraph][0] = (char **) malloc(sizeof(char *));
        }
        else
        {
            if (word == NULL)
            {
                word = s;
                //printf("new word: %s\n", word);
            }
        }
    }
    return doc;
}
