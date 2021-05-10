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

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
void InsBeg(struct SinglyLinkedListNode** list,int x)
{
    struct SinglyLinkedListNode* p;
    p=(struct SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    p->data = x;
    p->next = (*list);
    (*list) = p;
}

void InsEnd(struct SinglyLinkedListNode **list,int x)
{
    if((*list)==NULL)
    {
        InsBeg(&(*list),x);
    }
    else
    {
        struct SinglyLinkedListNode *p,*q;
        p=(*list);
        while(p->next!=NULL)
        {
            p=p->next;
        }
        q=(struct SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
        q->data=x;
        q->next=NULL;
        p->next=q;
    }
}
 
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    struct SinglyLinkedListNode *p,*q,*START;
    p=head1;
    q=head2;
    START = NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            InsEnd(&START,p->data);
            p=p->next;
        }
        else
        {
            InsEnd(&START,q->data);
            q=q->next;
        }
    }
    while (p!=NULL)
    {
        InsEnd(&START,p->data);
        p=p->next;
    }
    while (q!=NULL)
    {
        InsEnd(&START,q->data);
        q=q->next;
    }
    return START;

}
