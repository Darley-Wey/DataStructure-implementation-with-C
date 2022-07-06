/* 3. 在顺序表的指定位置插入指定元素
【问题描述】
    将指定元素插入到顺序表指定位置
【输入形式】
    顺序表长度
    顺序表元素，空格区分，回车结束。
    待插入元素
    插入位置n(1<=n<=链表长度+1)（位置序号从1开始）
【输出形式】
    输出插入元素后的顺序表
【样例输入】
    5
    1 2 3 4 5
    10
    3
【样例输出】
     1 2 10 3 4 5 */

#include "SqList.cpp"
int main() {
    int n;
    scanf("%d", &n);
    SqList L;
    Status status;
    status = InitList_Sq(L);
    if (status != OK) {
        printf("初始化失败！\n");
        return 0;
    }
    int data[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    int e;
    int pos;
    status = CreateList_Sq(L, data, n);
    if (status != OK) {
        printf("创建失败！\n");
        return 0;
    }
    scanf("%d", &e);
    scanf("%d", &pos);
    status = InsertList_Sq(L, pos, e);
    if (status != OK) {
        printf("插入失败！\n");
        return 0;
    }
    PrintList_Sq(L);
    return 0;
}
