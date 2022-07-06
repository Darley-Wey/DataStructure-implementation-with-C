/* 
8. 合并两有序表
【问题描述】
    将两个有序表合并后按顺序输出，其中两个有序表中元素均为整数且互不相同。
【输入形式】
    有序表A长度 n1
    有序表A元素
    有序表B长度 n2
    有序表B元素
【输出形式】
    有序表
【样例输入】
    3
    1 2 3
    4 
    0 5 6 7 
【样例输出】
    0 1 2 3 5 6 7
 */
#include "SqList.cpp"
int main() {
    int n1, n2;
    scanf("%d", &n1);
    SqList L1;
    Status status;
    status = InitList_Sq(L1);
    if (status != OK) {
        printf("初始化失败！\n");
        return 0;
    }
    int data1[100];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data1[i]);
    }
    status = CreateList_Sq(L1, data1, n1);
    if (status != OK) {
        printf("创建失败！\n");
        return 0;
    }
    scanf("%d", &n2);
    SqList L2;
    status = InitList_Sq(L2);
    if (status != OK) {
        printf("初始化失败！\n");
        return 0;
    }
    int data2[100];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data2[i]);
    }
    status = CreateList_Sq(L2, data2, n2);
    if (status != OK) {
        printf("创建失败！\n");
        return 0;
    }
    SqList L3;
    status = InitList_Sq(L3);
    if (status != OK) {
        printf("初始化失败！\n");
        return 0;
    }
    status = MergeList_Sq(L1, L2, L3);
    if (status != OK) {
        printf("合并失败！\n");
        return 0;
    }
    PrintList_Sq(L3);
    return 0;
}
