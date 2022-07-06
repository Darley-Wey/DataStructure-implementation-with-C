/*
4. 顺序表元素删除
【问题描述】
    删除顺序表的第i个元素
【输入形式】
    顺序表长度
    顺序表元素，空格区分，回车结束
    输入i (i<=线性表长度)
【输出形式】
    返回删除第i个元素之后的线性表（线性表从1开始编号）
【样例输入】
    5
    1 2 3 4 5
    3
【样例输出】
    1 2 4 5 
*/
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
    int i;
    status = CreateList_Sq(L, data, n);
    if (status != OK) {
        printf("创建失败！\n");
        return 0;
    }
    scanf("%d", &i);
    ElemType e;
    status = DeleteList_Sq(L, i, e);
    if (status != OK) {
        printf("删除失败！\n");
        return 0;
    }
    PrintList_Sq(L);
    return 0;
}
