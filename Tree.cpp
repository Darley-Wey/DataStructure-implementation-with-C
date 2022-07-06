#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXSIZE = 50;
/*定义二叉树结点数据域类型*/
typedef char ElemType;
/*定义二叉树结点类型和二叉树结点指针类型*/
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//线索二叉树
typedef struct ThreadBiTNode {
    ElemType data;
    int lTag, rTag;
    struct ThreadBiTNode *lChild, *rChild;

} ThreadBiTNode, *ThreadBiTree;

/****下面是二叉树的基本运算****/
void visit(BiTNode* T) {
    cout << T->data << "  ";
}
// //先序遍历递归创建二叉树
// void Create (BiTree& T) {
//     if (!strcmp (s, "#")) {
//         // if (*s == "#") {
//         T = NULL;
//         s++;
//     }
//     else {
//         // T = new BiTNode;
//         T = (BiTNode*)malloc (sizeof (BiTNode));
//         T->data = *s;
//         s++;
//         Create (T->lchild);
//         Create (T->rchild);
//     }
// }

/* void Create(BiTree &T) {
    ElemType ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        Create(T->lchild);
        Create(T->rchild);
    }
} */
int LeafCount(BiTree T) {
    int lNum, rNum;
    if (!T)
        return 0;
    else if (!T->lchild && !T->lchild)
        return 1;
    else {
        lNum = LeafCount(T->lchild);
        rNum = LeafCount(T->rchild);
        return lNum + rNum;
    }
}

//求二叉树的深度
int getDepth(BiTree T) {
    int lDepth, rDepth;
    if (T == NULL)
        return 0;
    else {
        lDepth = getDepth(T->lchild);
        rDepth = getDepth(T->rchild);
        return (lDepth > rDepth ? lDepth : rDepth) + 1;
    }
}

//复制二叉树
BiTree copyBiTree(BiTree T) {
    if (T == NULL)
        return NULL;
    else {
        BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
        // BiTNode *root = new BiTNode;
        root->data = T->data;
        root->lchild = copyBiTree(T->lchild);
        root->rchild = copyBiTree(T->rchild);
        return root;
    }
}

//清空二叉树
void clearBiTree(BiTree& T) {
    if (T) {
        clearBiTree(T->lchild);
        clearBiTree(T->rchild);
        delete T;
        //  T = NULL;
    }
}
/*先序遍历二叉树递归操作*/
void PreOrder(BiTree T) {
    if (T) {
        cout << T->data << "  ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/*中序遍历二叉树递归操作*/
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        cout << T->data << "  ";
        InOrder(T->rchild);
    }
}

/*后序遍历二叉树递归操作*/
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data << "  ";
    }
}

/*层次遍历二叉树操作*/
void LevelOrder(BiTree T) {
    BiTNode *queue[MAXSIZE], *p = T;
    int front = 0, rear = 0;
    if (p != NULL) {
        queue[rear++] = p;
        while (front != rear) {
            p = queue[front++];
            visit(p);
            if (p->lchild != NULL)
                queue[rear++] = p->lchild;
            if (p->rchild != NULL)
                queue[rear++] = p->rchild;
        }
    }
}
void postOrderNoRec(BiTree T) {
    BiTNode *stack1[MAXSIZE], *stack2[MAXSIZE], *p = T;
    int top1 = -1, top2 = -1;
    if (p != NULL) {
        stack1[++top1] = p;
        while (top1 != -1) {
            p = stack1[top1--];
            stack2[++top2] = p;
            if (p->lchild != NULL) {
                stack1[++top1] = p->lchild;
            }
            if (p->rchild != NULL) {
                stack1[++top1] = p->rchild;
            }
        }
        while (top2 != -1) {
            p = stack2[top2--];
            visit(p);
        }
    }
}
/*层次遍历二叉树操作*/
int getMaxWidth(BiTree T) {
    if (T == NULL) {
        return 0;
    }  //空树
    BiTNode *queue[MAXSIZE], *p = T;
    int front, rear, last, width, maxWidth;
    front = rear = width = maxWidth = 0;
    queue[rear++] = p;       //入队
    last = rear;             //last指向第一层最后一个结点
    while (front != rear) {  //队不为空
        p = queue[front++];  //出队
        width++;             //宽度计数
        if (p->lchild != NULL)
            queue[rear++] = p->lchild;
        if (p->rchild != NULL)
            queue[rear++] = p->rchild;
        if (front == last) {  //当前层已全部出队
            last = rear;      //last指向下层最后一个结点
            if (width > maxWidth) {
                maxWidth = width;
            };
            width = 0;  //一层结束，计数清0
        }
    }
    return maxWidth;
}
/*层次遍历二叉树操作*/
int getHight(BiTree T) {
    BiTNode *queue[MAXSIZE], *p = T;
    int front, rear, last, level;
    front = rear = level = 0;
    queue[rear++] = p;
    last = rear;
    if (T == NULL) {
        return 0;
    }
    while (front != rear) {
        p = queue[front++];
        if (p->lchild != NULL)
            queue[rear++] = p->lchild;
        if (p->rchild != NULL)
            queue[rear++] = p->rchild;
        if (front == last) {
            last = rear;
            level++;
        }
    }
    return level;
}
int getWidth(BiTree T, int level) {
    if (T == NULL) {
        return 0;
    }
    BiTNode *queue[MAXSIZE], *p;
    int front, rear, last, width, levelNum;
    front = rear = width = levelNum = 0;
    queue[rear++] = T;
    last = rear;
    while (front != rear) {
        p = queue[front++];
        width++;
        if (p->lchild != NULL)
            queue[rear++] = p->lchild;
        if (p->rchild != NULL)
            queue[rear++] = p->rchild;
        if (front == last) {
            last = rear;
            levelNum++;
            printf("第%d层的结点数为%d\n", levelNum, width);
            if (level == levelNum) {
                return width;
            };
            width = 0;
        }
    }
    return 0;
}
//层次遍历寻找最后一个结点
BiTNode* searchLastNode(BiTree T) {
    BiTNode *queue[MAXSIZE], *p = T;
    int front = 0, rear = 0;
    if (p != NULL) {
        queue[rear++] = p;
        while (front != rear) {
            p = queue[front++];
            if (p->lchild != NULL)
                queue[rear++] = p->lchild;
            if (p->rchild != NULL)
                queue[rear++] = p->rchild;
        }
        return p;
    }
    return NULL;
}

//先序遍历二叉树非递归算法（根左右）：
void preOrderUnRec(BiTree T) {
    BiTNode *stack[MAXSIZE], *p = T;
    int top = -1;
    while (p != NULL || top != -1) {
        if (p != NULL) {
            stack[++top] = p;
            visit(p);  //入栈时访问
            p = p->lchild;  //左孩子依次全部入栈，栈顶为最底部左孩子结点
        } else {               //当前根结点左孩子已全部入栈
            p = stack[top--];  //栈顶出栈
            p = p->rchild;     //指向右孩子结点
        }
    }
}

//中序遍历二叉树非递归算法（左根右）：
void inOrderUnRec(BiTree T) {
    BiTNode *stack[MAXSIZE], *p = T;
    int top = -1;
    while (p != NULL || top != -1) {
        if (p != NULL) {
            stack[++top] = p;
            p = p->lchild;
        } else {
            p = stack[top--];
            visit(p);  //出栈时访问，左根右
            p = p->rchild;
        }
    }
}

//后序遍历非递归算法
void postOrderUnRec(BiTree T) {
    BiTNode *stack[MAXSIZE], *p = T, *r = NULL;
    int top = -1;
    while (p != NULL || top != -1) {
        if (p != NULL) {
            stack[++top] = p;
            p = p->lchild;  //左子树依次全部入栈
        } else {
            p = stack[top];  //取栈顶即最后一个左结点
            if (p->rchild != NULL &&
                p->rchild != r) {  //有右子树且未被访问，右子树入栈
                p = p->rchild;
                stack[++top] = p;
                p = p->lchild;  // p指向当前结点的左子树，不为空进入下一轮循环则其左子树全部进栈
            } else {  //没有右子树或右子树已访问，出栈访问上一层
                p = stack[top--];
                visit(p);
                r = p;  //标记已访问的结点
                p = NULL;
            }
        }
    }
}

//寻找指定结点的所有祖先结点
void searchParent(BiTree T, BiTNode* n) {
    BiTNode *stack[MAXSIZE], *p = T, *r = NULL;
    int top = -1;
    while (p != NULL || top != -1) {
        if (p) {
            stack[++top] = p;
            p = p->lchild;
        } else {
            p = stack[top];
            if (p->rchild != NULL && p->rchild != r) {
                p = p->rchild;
                stack[++top] = p;
                p = p->lchild;
            } else {
                p = stack[top--];
                if (p == n) {
                    for (int i = 0; i <= top; i++) {
                        cout << stack[i]->data << "  ";
                    }
                    return;
                }
                r = p;
                p = NULL;
            }
        }
    }
}

void insertBST(BiTree& T, char e) {
    if (T == NULL) {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = e;
        T->lchild = T->rchild = NULL;
    } else {
        if (e < T->data) {
            insertBST(T->lchild, e);
        } else {
            insertBST(T->rchild, e);
        }
    }
}

void creatBST(BiTree& T, char* str) {
    T = NULL;
    int i = 0;
    while (str[i] != '\0') {
        insertBST(T, str[i]);
        i++;
    }
}

int main() {
    /*创建二叉树操作*/
    // string elem[] = {"1", "2", "4", "#", "#",  "3", "#", "5", "#", "#"};
    // string *s = elem;
    char node[][10] = {"1", "2", "4", "#", "#", "6", "#", "#",
                       "3", "#", "5", "1", "#", "#", "#"};
    char(*s)[10] = node;
    BiTree T1, T2;
    // cout << "创建二叉树：\n";
    // Create (T1);
    // cout << "先序递归遍历二叉树：\n";
    // PreOrder (T1);
    // cout << endl;
    // cout << "中序递归遍历二叉树：\n";
    // InOrder (T1);
    // cout << endl;
    // cout << "后序递归遍历二叉树：\n";
    // PostOrder (T1);
    // cout << endl;
    // cout << "层次遍历二叉树：\n";
    // LevelOrder (T1);
    // cout << endl;
    // cout << "先序非递归遍历二叉树：\n";
    // preOrderUnRec (T1);
    // cout << endl;
    // cout << "中序非递归遍历二叉树：\n";
    // inOrderUnRec (T1);
    // cout << endl;
    // cout << "后序非递归遍历二叉树：\n";
    // postOrderUnRec (T1);
    // postOrderNoRec (T1);
    // cout << endl;
    // cout << "寻找祖先结点：\n";
    // searchParent (T1, searchLastNode (T1));
    // cout << endl;
    // cout << "二叉树叶子结点个数：\n";
    // cout << LeafCount (T1);
    // cout << endl;
    // cout << "二叉树的深度：\n";
    // cout << getDepth (T1);
    // cout << endl;
    // cout << getHight (T1);
    // cout << endl;
    // cout << "二叉树的宽度：\n";
    // cout << getMaxWidth (T1);
    // cout << endl;
    // getWidth (T1, 4);
    // T2 = copyBiTree (T1);
    // cout << "中序递归遍历复制二叉树：\n";
    // InOrder (T2);
    // cout << endl;
    // clearBiTree (T2);
    // creatBST(T1, "CBADEFGHIJKLMNOPQRSTUVWXYZ");
    // PreOrder(T1);
}
