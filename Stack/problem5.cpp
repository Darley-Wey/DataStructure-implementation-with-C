/* 
5. 括号匹配检查
【问题描述】
   编写程序从键盘接收字符串（最大长度为100），测试字符串中的括号（）、[ ]、{}是否匹配。 
   要求使用堆栈，且堆栈的基本操作使用链栈实现
【输入形式】
   输入字符串
【输出形式】
   括号全部匹配，则输出True, 否则输出False
【样例输入】
  123(4[56{89)]}
【样例输出】
  False
 */

#include "LinkStack.cpp"

// 判断字符串中括号是否匹配，如果是返回1，否则返回0
int isMatch(char* s) {
    LinkStack S;
    Status status;
    status = InitStack(S);
    if (status != OK) {
        return 0;
    }
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            Push(S, s[i]);
        } else if (s[i] == ')') {
            if (StackEmpty(S)) {
                return 0;
            } else {
                SElemType e;
                Pop(S, e);
                if (e != '(') {
                    return 0;
                }
            }
        } else if (s[i] == ']') {
            if (StackEmpty(S)) {
                return 0;
            } else {
                SElemType e;
                Pop(S, e);
                if (e != '[') {
                    return 0;
                }
            }
        } else if (s[i] == '}') {
            if (StackEmpty(S)) {
                return 0;
            } else {
                SElemType e;
                Pop(S, e);
                if (e != '{') {
                    return 0;
                }
            }
        }
        i++;
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
    if (isMatch(s)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}
