#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
// definition of array based stack
#define STACK_INIT_SIZE 100  //Initial size for memory allocation
#define STACKINCREMENT 10    //incremental size

typedef int SElemType;
typedef int Status;
typedef struct {
    SElemType* base;  //base pointer
    SElemType* top;   //top pointer
    int stacksize;    //current size
} SqStack;

// initialization of array-based stack
Status InitStack(SqStack& S) {
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

//Test empty stack
Status StackEmpty(SqStack S) {
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

// Get the length of a stack
int StackLength(SqStack S) {
    return (S.top - S.base);
}

// Get top item of a stack
Status GetTop(SqStack S, SElemType& e) {
    if (S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}

// Delete an item from the stack
Status Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base)
        return ERROR;
    e = *(--S.top);
    return OK;
}

// Insert an item into the stack
Status Push(SqStack& S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType*)realloc(
            S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base)
            return ERROR;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

// Print the elements in a stack
void PrintStack(SqStack S) {
    SElemType e;
    while (!StackEmpty(S)) {
        Pop(S, e);
        printf("%d ", e);
    }
    printf("\n");
}
