/* 
1. 创建堆栈
【问题描述】
  堆栈的基本操作
  从键盘读入n个整数，依次放入堆栈中，之后再将整数从堆栈弹出并打印。
 要求使用顺序栈
【输入形式】
 整数个数n
 n个整数（以空格分隔）
【输出形式】
  逆序输出堆栈的所有元素，输出元素的个数
【样例输入】
3 
1 2 3
【样例输出】
3 2 1
3
 */

#include "SqStack.cpp"

// 逆序输出堆栈的所有元素，并返回输出元素的个数
int reverseOutput(SqStack& S) {
    SElemType e;
    int count = 0;
    while (!StackEmpty(S)) {
        Pop(S, e);
        printf("%d ", e);
        count++;
    }
    printf("\n");
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    SqStack S;
    Status status;
    status = InitStack(S);
    if (status != OK) {
        printf("InitStack_S error\n");
        return status;
    }
    for (int i = 0; i < n; i++) {
        status = Push(S, arr[i]);
        if (status != OK) {
            printf("Push_S error\n");
            return status;
        }
    }
    int count = 0;
    count = reverseOutput(S);
    printf("%d\n", count);
    return 0;
}
