/* 
6. 删除字符串中的所有相邻重复项
【问题描述】
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
【输入形式】
【输出形式】
【样例输入】
"abbaca" 
【样例输出】
 "ca" 
*/

#include "SqStack.cpp"

int main() {
    char s[100];
    scanf("%s", s);
    SqStack S;
    Status status;
    status = InitStack(S);
    if (status != OK) {
        printf("InitStack_S error\n");
        return status;
    }
    int i = 0;
    while (s[i] != '\0') {
        if (StackEmpty(S)) {
            Push(S, s[i]);
        } else {
            SElemType e;
            Pop(S, e);
            if (e != s[i]) {
                Push(S, e);
                Push(S, s[i]);
            }
        }
        i++;
    }

    SqStack S1;
    status = InitStack(S1);
    if (status != OK) {
        printf("InitStack_S error\n");
        return status;
    }
    while (!StackEmpty(S)) {
        SElemType e;
        Pop(S, e);
        Push(S1, e);
    }
    while (!StackEmpty(S1)) {
        SElemType e;
        Pop(S1, e);
        printf("%c", e);
    }
    printf("\n");
    return 0;
}
