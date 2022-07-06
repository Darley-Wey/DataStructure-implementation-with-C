/* 
2. 十进制转八进制
【问题描述】
   写一个算法，将一个非负十进制数转为一个等价的八进制数
   要求使用堆栈，且堆栈的基本操作使用链栈实现
【输入形式】
   输入一个非负十进制整数
【输出形式】
   输出对应八进制数
【样例输入】
  10
【样例输出】
  12 
*/

#include "LinkStack.cpp"

int main() {
    int num;
    scanf("%d", &num);
    LinkStack S;
    Status status;
    status = InitStack(S);
    if (status != OK) {
        printf("InitStack_S error\n");
        return status;
    }
    while (num > 0) {
        status = Push(S, num % 8);
        if (status != OK) {
            printf("Push_S error\n");
            return status;
        }
        num /= 8;
    }
    while (!StackEmpty(S)) {
        SElemType e;
        status = Pop(S, e);
        if (status != OK) {
            printf("Pop_S error\n");
            return status;
        }
        printf("%d", e);
    }
    printf("\n");
    return 0;
}
