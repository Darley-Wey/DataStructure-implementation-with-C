/* 
3. 堆栈删除元素
【问题描述】
  从键盘读入n个整数，依次放入堆栈中，从堆栈中删除值为x的元素（可能有多个），
打印最终的堆栈中的所有元素，并返回堆栈的元素个数。
要求采用链栈实现堆栈的基本操作
【输入形式】
    元素个数n
    n个整数（以空格分隔）
    待删除的元素
【输出形式】
    打印堆栈的元素（空格分隔）
    堆栈的长度
【样例输入】
3
1 2 3
2
【样例输出】
3 1
2
 */

#include "LinkStack.cpp"

// 删除堆栈中值为x的元素（可能有多个），返回堆栈的长度
int DeleteElem(LinkStack& S, SElemType x) {
    SElemType e;
    LinkList p = S.Head, q;
    int count = 0;
    while (p->next) {
        if (p->next->data == x) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    LinkStack S;
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
    int x;
    scanf("%d", &x);
    int count = DeleteElem(S, x);
    PrintStack(S);
    printf("%d\n", count);
    return 0;
}
