#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;
typedef struct LNode {
    SElemType data;      //data field
    struct LNode* next;  //pointer field
} LNode, *LinkList;
typedef struct {
    LinkList Head;  //head pointer
    int length;     //length
} LinkStack;

// initialization of linked list based stack
Status InitStack(LinkStack& S) {
    S.Head = (LinkList)malloc(sizeof(LNode));
    if (!S.Head)
        return ERROR;
    S.Head->next = NULL;
    S.length = 0;
    return OK;
}

//Test empty stack
Status StackEmpty(LinkStack S) {
    if (S.length == 0)
        return TRUE;
    else
        return FALSE;
}

// Get the length of a stack
int StackLength(LinkStack S) {
    return S.length;
}

// Get top item of a stack
Status GetTop(LinkStack S, SElemType& e) {
    if (S.length == 0)
        return ERROR;
    e = S.Head->next->data;
    return OK;
}

// Delete an item from the stack
Status Pop(LinkStack& S, SElemType& e) {
    if (S.length == 0)
        return ERROR;
    e = S.Head->next->data;
    LinkList p = S.Head->next;
    S.Head->next = p->next;
    free(p);
    S.length--;
    return OK;
}

// Insert an item into the stack
Status Push(LinkStack& S, SElemType e) {
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if (!p)
        return ERROR;
    p->data = e;
    p->next = S.Head->next;
    S.Head->next = p;
    S.length++;
    return OK;
}

// Print the elements in a stack
void PrintStack(LinkStack S) {
    LinkList p = S.Head->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
