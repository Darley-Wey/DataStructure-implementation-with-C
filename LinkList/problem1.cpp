/* 
1. 链表基本操作
【问题描述】
    按以下步骤对链表做基本操作，每一个问题输出一行
（1）创建一个链表，按顺序输入链表，并按顺序输出，以空格区分
（2）输出链表的第a个元素（从1开始计数）
（3）在上一步链表的基础上，在第b个元素之前插入元素c，并输出整个链表，以空格区分
（4）在上一步链表的基础上，删除第d个元素，并输出整个链表，以空格区分
（5）在上一步链表的基础上，返回元素m第一次出现的位置，（从1开始计数）
【输入】
    链表长度 n
    链表
    a
    b c
    d
    m
【输出】
    链表（以空格区分）
    第a个元素
    链表（以空格区分）
    链表（以空格区分）
    元素m所在位置
 【输入示例】
    5
    1 2 3 4 5
    1
    2 3
    3
    3   
 【输出示例】
    1 2 3 4 5
    1
    1 3 2 3 4 5
    1 3 3 4 5
    2 
*/
#include "LinkList.cpp"

int main() {
    int length, a, b, c, d, m;
    scanf("%d", &length);
    int arr[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &a);
    scanf("%d %d", &b, &c);
    scanf("%d", &d);
    scanf("%d", &m);
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
    LinkedListPrint(L);
    ElemType data;
    status = GetElem_L(L, a, data);
    if (status != OK) {
        printf("GetElem_L error\n");
        return status;
    }
    printf("%d\n", data);
    status = ListInsert_L(L, b, c);
    if (status != OK) {
        printf("ListInsert_L error\n");
        return status;
    }
    LinkedListPrint(L);
    status = ListDelete_L(L, d, data);
    if (status != OK) {
        printf("ListDelete_L error\n");
        return status;
    }
    LinkedListPrint(L);
    data = LocateElem_L(L, m);
    printf("%d\n", data);
    return 0;
}
