#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100//图中顶点数目的最大值
#define MAXWEIGHT 0   //最大权值
typedef int EdgeType;//邻接矩阵边类型
typedef char VertexType;//邻接矩阵顶点类型
// typedef struct {
//     int no;//顶点编号
//     char info;//顶点信息
// }VertexType;//邻接矩阵顶点类型

typedef struct ArcNode {//邻接表边类型
    int adjvex;//该边所指向的结点的位置,即编号
    struct ArcNode* next;//指向下一条边的指针
    //InfoType info;//网的边权值等信息
}ArcNode;

typedef struct VNode {//邻接表顶点结点类型
    VertexType data;//顶点信息
    ArcNode* first;//顶点结点的指针,指向边
}VNode;

typedef struct {
    VertexType vex[MaxVertexNum];//邻接矩阵顶点
    EdgeType edge[MaxVertexNum][MaxVertexNum];//邻接矩阵边
    int vexNum, arcNum;//图的顶点数和边数
}MGraph;//邻接矩阵存储的图类型

typedef struct {
    VNode adjlist[MaxVertexNum];//邻接表，每个顶点一个邻接表
    int vexNum, arcNum;//图的顶点数和边数
}AGraph;//邻接表存储的图类型


MGraph m;
AGraph* a = new AGraph;

/*创建邻接矩阵*/
void createGraph(MGraph& graph, int edge[][MaxVertexNum], VertexType vex[]) {
    int i = 0, j;
    graph.vexNum = 0;
    graph.arcNum = 0;
    while (vex[i++]) {
        graph.vexNum++;
    }
    for (i = 0; i < graph.vexNum; i++) {
        for (j = 0; j < graph.vexNum; j++) {
            if (graph.edge[i][j] == 1) {
                graph.arcNum++;
            }
        }
    }
    for (i = 0; i < graph.vexNum; i++) {
        graph.vex[i] = vex[i];
        for (j = 0; j < graph.vexNum; j++) {
            graph.edge[i][j] = edge[i][j];
        }
    }
}

void convertToAGraph(MGraph m, AGraph*& a) {
    for (int i = 0; i < m.vexNum; i++) {
        a->adjlist[i].data = m.vex[i];
        a->adjlist[i].first = NULL;
    }
    for (int i = 0; i < m.vexNum; i++) {
        for (int j = 0; j < m.vexNum; j++) {
            if (m.edge[i][j] == 1) {
                ArcNode* p = new ArcNode;
                p->adjvex = j;
                p->next = a->adjlist[i].first;
                a->adjlist[i].first = p;
            }
        }
    }
    a->vexNum = m.vexNum;
    a->arcNum = m.arcNum;
}

void convertToMGraph(MGraph& m, AGraph* a) {
    ArcNode* p;
    int i, j;
    for (i = 0; i < a->vexNum; i++) {
        m.vex[i] = a->adjlist[i].data;
        for (j = 0; j < a->vexNum; j++) {
            m.edge[i][j] = 0;
        }
    }
    for (i = 0; i < a->vexNum; i++) {
        p = a->adjlist[i].first;
        while (p != NULL) {
            m.edge[i][p->adjvex] = 1;
            p = p->next;
        }
    }
    m.vexNum = a->vexNum;
    m.arcNum = a->arcNum;
}

/*打印邻接表*/
void printAGraph(AGraph* a) {
    printf("邻接表如下所示\n");
    int i = 0;
    while (a->adjlist[i].data) {
        printf("%c", a->adjlist[i].data);
        ArcNode* p;
        p = a->adjlist[i].first;
        while (p != NULL) {
            printf("->%c", a->adjlist[p->adjvex].data);
            p = p->next;
        }
        i++;
        printf("\n");
    }
}

void visit(int v) {
    printf("%c->", a->adjlist[v].data);
}
void DFS(AGraph* a, int v, bool visited[]) {
    ArcNode* p;
    visit(v);
    visited[v] = true;
    p = a->adjlist[v].first;
    while (p != NULL) {
        if (visited[p->adjvex] == false) {
            DFS(a, p->adjvex, visited);
        }
        p = p->next;
    }
}
void DFSTraverse(AGraph* a) {
    bool visited[MaxVertexNum];
    for (int v = 0; v < a->vexNum; v++) {
        visited[v] = false;
    }
    for (int v = 0; v < a->vexNum; v++) {
        if (visited[v] == false) {
            DFS(a, v, visited);
        }
    }
}

void BFS(AGraph* a, int v, bool visited[]) {
    ArcNode* p;
    int queue[MaxVertexNum];
    int front, rear, j;
    front = rear = 0;
    visit(v);
    visited[v] = true;
    queue[rear++] = v;
    while (front != rear) {
        j = queue[front++];//取一个顶点
        p = a->adjlist[j].first;//邻接表结点
        while (p != NULL) {//一条邻接表全部入队
            if (visited[p->adjvex] == false) {
                visit(p->adjvex);
                visited[p->adjvex] = true;
                queue[rear++] = p->adjvex;
            }
            p = p->next;
        }
    }
}
void BFSTraverse(AGraph* a) {
    bool visited[MaxVertexNum];
    for (int v = 0; v < a->vexNum; v++) {
        visited[v] = false;
    }
    for (int v = 0; v < a->vexNum; v++) {
        if (visited[v] == false) {
            BFS(a, v, visited);
        }
    }
}

void prim(MGraph g,int v0,int &sum){
    int vset[MaxVertexNum], lowcost[MaxVertexNum];
}
int edge[][MaxVertexNum] = {
    {MAXWEIGHT, 1, 1, MAXWEIGHT, MAXWEIGHT, 1,MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT},
    {1, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT,MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT},
    {1, MAXWEIGHT, MAXWEIGHT, 1, 1, MAXWEIGHT,MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT},
    {MAXWEIGHT, MAXWEIGHT, 1, MAXWEIGHT, 1, MAXWEIGHT,MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT},
    {MAXWEIGHT, MAXWEIGHT, 1, 1, MAXWEIGHT, 1,MAXWEIGHT, 1, MAXWEIGHT, MAXWEIGHT},
    {1, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 1, MAXWEIGHT,1, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT},
    {MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT,1, MAXWEIGHT, 1, 1, 1},
    {MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, 1,MAXWEIGHT, 1, MAXWEIGHT, 1, 1},
    {MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT,MAXWEIGHT, 1, 1, MAXWEIGHT, 1},
    {MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT, MAXWEIGHT,MAXWEIGHT, 1, 1, 1, MAXWEIGHT}
};

VertexType vex[] = { 'A','B','C','D','E','F','G','H','I','J' };
int main() {
    createGraph(m, edge, vex);    //创建邻接矩阵
    for (int i = 0; i < m.vexNum; i++)
        printf("顶点编号：[%c]\n", m.vex[i]);
    convertToAGraph(m, a);
    printAGraph(a);
    convertToMGraph(m, a);
    convertToAGraph(m, a);
    printAGraph(a);
    printf("\n深度优先遍历序列为：");
    DFSTraverse(a);
    printf("\n广度优先遍历序列为：");
    BFSTraverse(a);
}