/* 5. 删除单链表的倒数第k个节点
【问题描述】
    给定一个带头结点的单链表，删除单链表的倒数第k个节点。你可以假设测试数据保证k在合法的范围内。
【输入形式】
    链表长度
    链表（以空格区分）
    k
【输出形式】
    链表（以空格区分）
【样例输入】
    5
    1 2 3 4 5
    2
【样例输出】
    1 2 3 5
 */

#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
// definition of node structure of singly linked list
typedef struct LNode {
    ElemType data;       // data field
    struct LNode* next;  // pointer field
} LNode, *LinkedList, *LinkList;
typedef struct CLink {
    int data;
    struct CLink* next;
} CLink;  //循环链表

// initialization of singly linked list L with head node
Status InitList_L(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        return ERROR;
    L->next = NULL;
    return OK;
}

// Create a singly linked list L with head node, and with n elements
Status CreateList_L(LinkList& L, int a[], int n) {
    for (int i = 0; i < n; i++) {
        LNode* p = (LinkList)malloc(sizeof(LNode));
        if (!p)
            return ERROR;
        p->data = a[n - i - 1];
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

// Get the length of a singly linked list with head node
int ListLength_L(LinkList L) {
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

// Get the ith element of a singly linked list
Status GetElem_L(LinkList L, int i, ElemType& e) {
    int j = 1;
    LinkList p = L->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

// search for an element in a singly linked list and return its position starting from 1
int LocateElem_L(LinkList L, ElemType e) {
    int i = 1;
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;
        i++;
    }
    if (!p)
        return 0;
    return i;
}

// Insert element e at the ith position of a singly linked list
Status ListInsert_L(LinkList& L, int i, ElemType e) {
    int j = 1;
    LinkList p = L;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    LNode* s = (LinkList)malloc(sizeof(LNode));
    if (!s)
        return ERROR;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// Delete the ith element from the list
Status ListDelete_L(LinkList& L, int i, ElemType& e) {
    int j = 1;
    LinkList p = L;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    LNode* s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return OK;
}

void Delete_L(LinkList& L, ElemType low, ElemType high) {
    LinkList p = L->next;
    LinkList q = L;
    while (p) {
        if (p->data >= low && p->data <= high) {
            q->next = p->next;
            free(p);
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
    }
}

// Print the elements in a list
void LinkedListPrint(LinkedList L) {
    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Get the maximum of  a singly linked list with head node
int GetMax(LinkList L) {
    int max = L->next->data;
    LinkList p = L->next;
    while (p) {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

// test whether the singly linked list is in ascending order, return 1 if it is, otherwise return 0
int isAscendingOrder(LinkList L) {
    LinkList p = L->next;
    while (p->next) {
        if (p->data > p->next->data)
            return 0;
        p = p->next;
    }
    return 1;
}

// Insert element e into an ordered singly linked list, and keep the list in ascending order
Status ListInsert_L(LinkList& L, ElemType e) {
    LinkList p = L;
    while (p->next && p->next->data < e) {
        p = p->next;
    }
    LNode* s = (LinkList)malloc(sizeof(LNode));
    if (!s)
        return ERROR;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//  将单链表中存放的二进制数转换成一个十进制数，并返回得到的结果
int Bin2Dec_L(LinkList L) {
    int sum = 0;
    LinkList p = L->next;
    int i = ListLength_L(L);
    while (p) {
        sum += p->data * pow(2, --i);
        p = p->next;
    }
    return sum;
}

//  delete the kth element from the end
void Delete_K(LinkList& L, int k) {
    LinkList p = L, q = L;
    while (p && k--) {
        p = p->next;
    }
    if (!p)
        return;
    while (p->next) {
        p = p->next;
        q = q->next;
    }
    LNode* s = q->next;
    q->next = q->next->next;
    free(s);
}

void ReverseLinkList_L(LinkList& L) {
    LinkList cur = L->next, next;
    L->next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = L->next;
        L->next = cur;
        cur = next;
    }
}

int main() {
    int length, k;
    scanf("%d", &length);
    int arr[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    LinkList L;
    Status status;
    status = InitList_L(L);
    if (status != OK) {
        printf("InitList_L error\n");
        return status;
    }
    status = CreateList_L(L, arr, length);
    if (status != OK) {
        printf("CreateList_L error\n");
        return status;
    }
    Delete_K(L, k);
    LinkedListPrint(L);
}
