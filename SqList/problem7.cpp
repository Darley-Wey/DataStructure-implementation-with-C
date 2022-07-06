/* 
7. 就地逆置顺序表
【问题描述】
   给定一个顺序表A=（a1,a2,...an）, 将其进行就地逆置，得到A=（an, ...., a2, a1）
【输入形式】
   顺序表长度
   顺序表元素，以空格区分，以回车结束
【输出形式】
   输出反转后的线性表，以空格区分
【样例输入】
    5
    1 3 5 7 9
【样例输出】
    9 7 5 3 1 
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
    status = ReverseList_Sq(L1);
    if (status != OK) {
        printf("反转失败！\n");
        return 0;
    }
    PrintList_Sq(L1);
}
