//Problem Link: https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

struct SinglyLinkedList
{
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;
};

SinglyLinkedListNode *create_singly_linked_list_node(int node_data)
{
    SinglyLinkedListNode *node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList **singly_linked_list, int node_data)
{
    SinglyLinkedListNode *node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head)
    {
        (*singly_linked_list)->head = node;
    }
    else
    {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode *node, char *sep, FILE *fptr)
{
    while (node)
    {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node)
        {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *head)
{
    struct SinglyLinkedListNode *p;
    p = head;
    while (p->next != NULL)
    {
        if (p->data == p->next->data)
        {
            if (p->next->next == NULL)
            {
                p->next = NULL;
            }
            else
                p->next = p->next->next;
        }
        else
            p = p->next;
    }
    return head;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char *t_endptr;
    char *t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        SinglyLinkedList *llist = malloc(sizeof(SinglyLinkedList));
        llist->head = NULL;
        llist->tail = NULL;

        char *llist_count_endptr;
        char *llist_count_str = readline();
        int llist_count = strtol(llist_count_str, &llist_count_endptr, 10);

        if (llist_count_endptr == llist_count_str || *llist_count_endptr != '\0')
        {
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < llist_count; i++)
        {
            char *llist_item_endptr;
            char *llist_item_str = readline();
            int llist_item = strtol(llist_item_str, &llist_item_endptr, 10);

            if (llist_item_endptr == llist_item_str || *llist_item_endptr != '\0')
            {
                exit(EXIT_FAILURE);
            }

            insert_node_into_singly_linked_list(&llist, llist_item);
        }

        SinglyLinkedListNode *llist1 = removeDuplicates(llist->head);

        char *sep = " ";

        print_singly_linked_list(llist1, sep, fptr);
        fprintf(fptr, "\n");

        free_singly_linked_list(llist1);
    }

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data)
        {
            break;
        }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
