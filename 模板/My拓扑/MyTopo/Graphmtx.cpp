#include"Graphmtx.h"

Graphmtx::Graphmtx(int sz) {      //构造函数
    maxVertices = sz;
    //numVertices = 0;  
    numVertices = maxVertices;
    numEdges = 0;
    int i, j;
    verticesList = new int[maxVertices];  //创建顶点表

    for (int i = 0; i < maxVertices; i++) {
        verticesList[i] = i;
    }

    edge = (int**) new int* [maxVertices];
    for (i = 0; i < maxVertices; i++)
        edge[i] = new int[maxVertices];   //邻接矩阵 
    for (i = 0; i < maxVertices; i++)        //矩阵初始化
        for (j = 0; j < maxVertices; j++)
            edge[i][j] = (i == j) ? 0 : maxWeight;
};


int Graphmtx::getFirstNeighbor(int v) {
    //给出顶点位置为v的第一个邻接顶点的位置, 
    //如果找不到, 则函数返回-1
    if (v != -1) {
        for (int col = 0; col < numVertices; col++)
            if (edge[v][col] > 0 && edge[v][col] < maxWeight)
                return col;
    }
    return -1;
};

int Graphmtx::getNextNeighbor(int v, int w) {
    //给出顶点 v 的某邻接顶点 w 的下一个邻接顶点 
    if (v != -1 && w != -1) {
        for (int col = w + 1; col < numVertices; col++)
            if (edge[v][col] > 0 && edge[v][col] < maxWeight)
                return col;
    }
    return -1;
};

bool Graphmtx::insertEdge(int v1, int v2, int cost) {
    if (v1 < maxVertices && v2 < maxVertices) {
        edge[v1][v2] = cost;
        return true;
    }
    else return false;
}
