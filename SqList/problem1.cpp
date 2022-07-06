/* 
1. 顺序表元素查询
【问题描述】
    查询顺序表是否存在指定元素，若存在，返回元素位置，若不存在，返回0
【输入形式】
    顺序表长度
    顺序表元素，空格分隔，回车结束
    待查找元素x
【输出形式】
    若存在，返回元素位置，若不存在，返回0
【样例输入】
    5
    1 3 5 7 9
    5
【样例输出】
    3
【样例输入2】
    5
    1 3 5 7 9
    10
【样例输出2】
    0 
*/
#include "SqList.cpp"
int main(void) {
    int length, target;
    scanf("%d", &length);
    int arr[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);
    SqList L1;
    Status status;
    status = InitList_Sq(L1);
    if (status != OK) {
        printf("InitList_Sq error\n");
        return status;
    }
    status = CreateList_Sq(L1, arr, length);
    if (status != OK) {
        printf("CreateList_Sq error\n");
        return status;
    }
    printf("%d", LocateElem_Sq(L1, target));
}
