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

//打印没有头结点的单链表
void printLinkWithoutHead(LNode* L) {
    LNode* p = L;
    while (p != NULL) {
        int a = p->data;
        printf("%d->", a);
        p = p->next;
    }
    printf("\n");
}

//打印循环单链表
void printCLink(CLink* L, int length) {
    CLink* p = L;
    while (length--) {
        int a = p->data;
        printf("%d->", a);
        p = p->next;
    }
    printf("\n");
}

//尾插法创建循环单链表
void createCLink(CLink*& L, int arr[], int length) {
    CLink* node = NULL;
    CLink* r = L;
    int i;
    r->data = arr[0];
    for (i = 1; i < length; i++) {
        node = (CLink*)malloc(sizeof(CLink));
        node->data = arr[i];
        node->next = r->next;
        r->next = node;
        r = r->next;
    }
    r->next = L;
}

//删除循环链表前驱结点
void delPriorNode(CLink* s) {
    CLink* p = s;
    while (s->next->next != p)
        s = s->next;
    free(s->next);
    s->next = p;
    return;
}

//返回循环链表L上第n个节点（n可超过L的总节点个数)
CLink* creLNodePoint(CLink* L, int n) {
    CLink* s = L;
    while (--n) {
        s = s->next;
    }
    return s;
}

//尾插法创建没有头结点的单链表
void creatLinkWithoutHead(LNode*& L, int array[], int length) {
    LNode *s, *p;
    if (array[0]) {
        s = (LNode*)malloc(sizeof(LNode));  //第一个结点
        s->data = array[0];
        L = s;
        p = s;
        for (int j = 1; j < length; ++j) {
            s = (LNode*)malloc(sizeof(LNode));
            s->data = array[j];
            p->next = s;
            p = p->next;
        }
        p->next = NULL;  //关闭最后一个结点
    }
}

//逆置不带头结点
void reverseLinkWithoutHead(LinkList& L) {
    if (!L || !L->next)
        return;
    LNode* p = L->next;
    LNode* next;
    L->next = NULL;
    while (p != NULL) {
        next = p->next;
        p->next = L;
        L = p;
        p = next;
    }
}

//非递减插入，无头结点
void insertWithoutHead(LinkList& L, int e) {
    LNode* p = L;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    //插在首位
    if (p->data >= e) {
        s->next = p;
        L = s;
    }
    //插在中间或末位
    else {
        while (p != NULL) {
            if (p->next == NULL || p->next->data >= e) {
                s->next = p->next;
                p->next = s;
                break;
            }
            p = p->next;
        }
    }
}

/*将非递减有序的单链表LA和LB合并成一个非递减有序的单链表LC*/
LinkList mergeLinkList(LinkList LA, LinkList LB) {
    LNode *pa, *pb;
    LNode* r;
    LinkList LC;
    /*将LC初始置空表。pa和pb分别指向两个单链表LA和LB中的第一个结点,r初值为LC*/
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    LC->next = NULL;
    r = LC;
    /*当两个表中均未处理完时，比较选择将较小值结点插入到新表LC中。*/
    while (pa != NULL && pb != NULL) {
        if (pa->data <= pb->data) {
            r->next = pa;
            r = pa;
            pa = pa->next;
        } else {
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
    }
    if (pa) /*若表LA未完，将表LA中后续元素链到新表LC表尾*/
        r->next = pa;
    else /*否则将表LB中后续元素链到新表LC表尾*/
        r->next = pb;
    free(LB);
    return (LC);
}
