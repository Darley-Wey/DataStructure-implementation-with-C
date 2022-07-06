/* 4. 二进制链表转整数
【问题描述】
    给定一个带头结点的单链表，链表中每个结点的值不是 0 就是 1。已知此链表是一个正整数的二进制表示形式。
请返回该链表所表示数字的十进制值数 。在链表中，从前往后，依次存放二进制数的各位数字。
"     链表不为空。
"     链表的结点总数不超过 30。
"     每个结点的值不是 0 就是 1。
【输入形式】
    链表长度
    链表的数值（各个二进制位）
【输出形式】
    十进制数字
【样例输入1】
    3
    1 0 1
【样例输出1】
    5
【样例输入2】
    1
    1 
【样例输出2】
    1
【样例输入3】
    3
    1 0 0
【样例输出3】
    4
 */

#include "LinkList.cpp"

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

int main() {
    int length;
    scanf("%d", &length);
    int arr[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
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
    int result;
    result = Bin2Dec_L(L);
    printf("%d\n", result);
    return 0;
}
