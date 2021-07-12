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
typedef struct DoublyLinkedListNode DoublyLinkedListNode;
typedef struct DoublyLinkedList DoublyLinkedList;
struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};
struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
};
DoublyLinkedListNode* create_doubly_linked_list_node(int node_data) {
    DoublyLinkedListNode* node = malloc(sizeof(DoublyLinkedListNode));
    node->data = node_data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void insert_node_into_doubly_linked_list(DoublyLinkedList** doubly_linked_list, int node_data) {
    DoublyLinkedListNode* node = create_doubly_linked_list_node(node_data);
    if (!(*doubly_linked_list)->head) {
        (*doubly_linked_list)->head = node;
    } else {
        (*doubly_linked_list)->tail->next = node;
        node->prev = (*doubly_linked_list)->tail;
    }
    (*doubly_linked_list)->tail = node;
}
void print_doubly_linked_list(DoublyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);
        node = node->next;
        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}
void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}
// Complete the sortedInsert function below.
/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *p = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
DoublyLinkedListNode *q = head;
p->data= data;
if(q->data>data)
{
    q->prev = p;
    p->next = q;
    p->prev = NULL;
    head = p;
    return head;
}
while(q!=NULL)
{
    if (q->data >= data)
    {
        p->next = q;
        p->prev = q->prev;
        q->prev->next = p;
        return head;
    }
    else if (q->next==NULL)
    {
        q->next = p;
        p->prev = q;
        p->next = NULL;
        return head;
    }
    q = q->next;
}
return head;
}
