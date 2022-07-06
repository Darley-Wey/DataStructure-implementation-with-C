/* 
2. 链表基本操作（2）
问题描述】
给出链表长度，输入一个链表，中间以空格区分。
（1）输出链表中最大值
（2）判断该链表是否为升序，升序返回1，否则0
【输入形式】
    链表长度
    链表元素，空格分隔，回车结束
【输出形式】
    最大值
    1或者0
【样例输入】
    5
    1 3 5 7 9
【样例输出】
    9
    1
【样例输入2】
    5
    1 3 10 7 9
【样例输出2】
    10
    0
 */

#include "LinkList.cpp"

int main() {
    int length;
    scanf("%d", &length);
    int arr[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    LinkList L1;
    Status status;
    status = InitList_L(L1);
    if (status != OK) {
        printf("InitList_L error\n");
        return status;
    }
    status = CreateList_L(L1, arr, length);
    if (status != OK) {
        printf("CreateList_L error\n");
        return status;
    }
    printf("%d\n", GetMax(L1));
    printf("%d\n", isAscendingOrder(L1));
}
