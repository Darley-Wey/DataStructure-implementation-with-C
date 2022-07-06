#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType* elem;
    int length;
    int listsize;
} SqList;

// Create an empty list
Status InitList_Sq(SqList& L) {
    L.elem = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        return ERROR;
    L.length = 0;
    L.listsize = INIT_SIZE;
    return OK;
}

//Create an array based list with n elements
Status CreateList_Sq(SqList& L, int a[], int n) {
    while (L.listsize < n) {
        L.elem = (ElemType*)realloc(
            L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!L.elem)
            return ERROR;
        L.listsize += LISTINCREMENT;
    }
    for (int i = 0; i < n; i++) {
        L.elem[i] = a[i];
    }
    L.length = n;
    return OK;
}

// Search an element in the list, if found, return the position of the element, otherwise return 0;
int LocateElem_Sq(SqList L, ElemType e) {
    for (int i = 1; i <= L.length; i++) {
        if (L.elem[i - 1] == e)
            return i;
    }
    return 0;
}

//print out all elements
void PrintList_Sq(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.elem[i - 1]);
    }
    printf("\n");
}

// Get the maximum element of sequential list L
Status MaxList_Sq(SqList L, ElemType& max_element, int& max_num) {
    max_element = L.elem[0];
    max_num = 1;
    for (int i = 1; i <= L.length; i++) {
        if (L.elem[i - 1] > max_element) {
            max_element = L.elem[i - 1];
            max_num = i;
        }
    }
    return OK;
}

// Insert the elements into the sequential list L at specific position
Status InsertList_Sq(SqList& L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length >= L.listsize) {
        L.elem = (ElemType*)realloc(
            L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!L.elem)
            return ERROR;
        L.listsize += LISTINCREMENT;
    }
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

// Delete the element of sequential list L
Status DeleteList_Sq(SqList& L, int i, ElemType& e) {
    ElemType *p, *q;
    if (i < 1 || i > L.length)
        return ERROR;
    q = L.elem + i - 1;
    e = *q;
    for (p = q; p < L.elem + L.length - 1; p++)
        *p = *(p + 1);
    L.length--;
    return OK;
}

// Insert the element into the sequential list L of ascending order,
// and keep the list in ascending order
Status InsertList_Sq(SqList& L, ElemType e) {
    int i;
    for (i = L.length; i >= 1 && L.elem[i - 1] > e; i--)
        L.elem[i] = L.elem[i - 1];
    L.elem[i] = e;
    L.length++;
    return OK;
}

// Sort the elements of sequential list L into ascending order
Status SortList_Sq(SqList& L) {
    int i, j;
    ElemType temp;
    for (i = 1; i < L.length; i++) {
        temp = L.elem[i];
        for (j = i; j > 0 && L.elem[j - 1] > temp; j--)
            L.elem[j] = L.elem[j - 1];
        L.elem[j] = temp;
    }
    return OK;
}

// Reverse the elements of sequential list L
Status ReverseList_Sq(SqList& L) {
    int i;
    ElemType temp;
    for (i = 0; i < L.length / 2; i++) {
        temp = L.elem[i];
        L.elem[i] = L.elem[L.length - i - 1];
        L.elem[L.length - i - 1] = temp;
    }
    return OK;
}

// Combine two sequential lists
Status MergeList_Sq(SqList L1, SqList L2, SqList& L3) {
    int i, j, k;
    i = j = k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.elem[i] < L2.elem[j]) {
            L3.elem[k] = L1.elem[i];
            i++;
        } else {
            L3.elem[k] = L2.elem[j];
            j++;
        }
        k++;
    }
    while (i < L1.length) {
        L3.elem[k] = L1.elem[i];
        i++;
        k++;
    }
    while (j < L2.length) {
        L3.elem[k] = L2.elem[j];
        j++;
        k++;
    }
    L3.length = L1.length + L2.length;
    return OK;
}
