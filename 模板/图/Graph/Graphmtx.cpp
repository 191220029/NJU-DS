#include"Graphmtx.h"

template <class T, class E>
Graphmtx<T, E>::Graphmtx(int sz) {      //构造函数
    maxVertices = sz;
    numVertices = 0;  numEdges = 0;
    int i, j;
    VerticesList = new T[maxVertices];  //创建顶点表
    Edge = (E**) new E * [maxVertices];
    for (i = 0; i < maxVertices; i++)
        Edge[i] = new E[maxVertices];   //邻接矩阵 
    for (i = 0; i < maxVertices; i++)        //矩阵初始化
        for (j = 0; j < maxVertices; j++)
            Edge[i][j] = (i == j) ? 0 : maxWeight;
};

template <class T, class E>
int Graphmtx<T, E>::getFirstNeighbor(int v) {
    //给出顶点位置为v的第一个邻接顶点的位置, 
    //如果找不到, 则函数返回-1
    if (v != -1) {
        for (int col = 0; col < numVertices; col++)
            if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
                return col;
    }
    return -1;
};

template <class T, class E>
int Graphmtx<T, E>::getNextNeighbor(int v, int w) {
    //给出顶点 v 的某邻接顶点 w 的下一个邻接顶点 
    if (v != -1 && w != -1) {
        for (int col = w + 1; col < numVertices; col++)
            if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
                return col;
    }
    return -1;
};

template <class T, class E>
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost) {
    if (v1 < maxVertices && v2 < maxVertices) {
        Edge[v1][v2] = cost;
        return true;
    }
    else return false;
}
