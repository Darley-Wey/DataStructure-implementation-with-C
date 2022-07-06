/* 
6. 顺序表排序
【问题描述】
    对顺序表按从小到大排序，可以采用冒泡，插入，选择等排序算法。
【输入形式】
    顺序表长度
    整数列表，空格分隔，回车结束
【输出形式】
    从小到大排序后的列表
【样例输入】
    4
    10 1 5 9
【样例输出】
    1 5 9 10 
*/
#include "SqList.cpp"
int main() {
    int length;
    SqList L1;
    ElemType data[100];
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }
    Status status = InitList_Sq(L1);
    if (status != OK) {
        printf("初始化失败！\n");
        return 0;
    }
    status = CreateList_Sq(L1, data, length);
    if (status != OK) {
        printf("创建失败！\n");
        return 0;
    }
    status = SortList_Sq(L1);
    if (status != OK) {
        printf("排序失败！\n");
        return 0;
    }
    PrintList_Sq(L1);
}
