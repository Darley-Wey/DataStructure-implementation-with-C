/* 
4. 判断操作序列是否合法
【问题描述】
  使用字母I和O分别表示PUSH和POP操作。堆栈的初始状态和结束状态都应为空，一个PUSH和POP操作序列仅由I和O组成的序列表示。
   这种序列只有在具有可操作性时才是合法的，否则就是非法的。写一个算法来判断下列序列是否合法。
   要求使用堆栈，且堆栈的基本操作使用顺序栈实现
【输入形式】
   字符串
【输出形式】
    如果合法，输出true,  否则 输出 false
【样例输入】
   I O O I I O I O O
【样例输出】
  False 
*/

#include "SqStack.cpp"

// 检查操作序列是否合法, 如果合法，返回1，否则返回0
int isLegal(char* s) {
    SqStack S;
    Status status;
    status = InitStack(S);
    if (status != OK) {
        printf("InitStack_S error\n");
        return status;
    }
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'I') {
            Push(S, 'I');
        } else if (s[i] == 'O') {
            if (StackEmpty(S)) {
                return 0;
            } else {
                SElemType e;
                Pop(S, e);
            }
        }
        i += 2;
    }
    if (StackEmpty(S)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char s[100];
    gets(s);
    if (isLegal(s)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}
