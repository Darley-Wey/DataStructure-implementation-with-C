#include <stdio.h>
const int MaxSize = 100;
typedef struct {
    int base[MaxSize];
    int rear, front;
    int tag;
} SqQueue;

int enQueue(SqQueue& Q, int x) {
    if (Q.tag == 1 && Q.rear == Q.front)
        return 0;
    Q.base[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return 1;
}

int deQueue(SqQueue& Q, int& x) {
    if (Q.tag == 0 && Q.rear == Q.front)
        return 0;
    x = Q.base[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return 1;
}

int main() {
    SqQueue Q;
    int ret;
    ret = enQueue(Q, 1);
    ret = enQueue(Q, 2);
    int x;
    ret = deQueue(Q, x);
    printf("%d\n", x);
    ret = deQueue(Q, x);
    printf("%d\n", x);
}
