/* 
2. 获取顺序表的最大元素
【问题描述】
    获取顺序表的最大元素，并输出最大元的位置。
    顺序表的创建、打印、求最大值等操作应以函数方式实现。
【输入形式】
    顺序表长度
    顺序表元素，空格分隔，回车换行
【输出形式】
    最大元素值  最大元素位置
【样例输入】
    4
    10 90 50 1
【样例输出】
    90 2 
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
    int max_data, max_pos;
    status = CreateList_Sq(L, data, n);
    if (status != OK) {
        printf("创建失败！\n");
        return 0;
    }
    MaxList_Sq(L, max_data, max_pos);
    printf("%d %d\n", max_data, max_pos);
    return 0;
}
