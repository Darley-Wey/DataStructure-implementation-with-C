/* 
5. 在有序顺序表中插入元素
【问题描述】
    在一个升序排列的顺序表中插入一个元素，并保持顺序（从小到大），注意元素插入的时间复杂度
【输入形式】
   顺序表长度
   顺序表元素，空格分隔，回车结束
   待插入的元素x
【输出形式】
    插入x后的顺序表
【样例输入】
    5
    1 3 5 7 9
    4
【样例输出】
    1 3 4 5 7 9
 */
#include "SqList.cpp"
int main() {
    int length;
    SqList L1;
    ElemType target;
    int data[100];
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
    scanf("%d", &target);
    status = InsertList_Sq(L1, target);
    if (status != OK) {
        printf("插入失败！\n");
        return 0;
    }
    PrintList_Sq(L1); 
}
