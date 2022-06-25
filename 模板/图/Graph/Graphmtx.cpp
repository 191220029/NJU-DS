#include"Graphmtx.h"

template <class T, class E>
Graphmtx<T, E>::Graphmtx(int sz) {      //���캯��
    maxVertices = sz;
    numVertices = 0;  numEdges = 0;
    int i, j;
    VerticesList = new T[maxVertices];  //���������
    Edge = (E**) new E * [maxVertices];
    for (i = 0; i < maxVertices; i++)
        Edge[i] = new E[maxVertices];   //�ڽӾ��� 
    for (i = 0; i < maxVertices; i++)        //�����ʼ��
        for (j = 0; j < maxVertices; j++)
            Edge[i][j] = (i == j) ? 0 : maxWeight;
};

template <class T, class E>
int Graphmtx<T, E>::getFirstNeighbor(int v) {
    //��������λ��Ϊv�ĵ�һ���ڽӶ����λ��, 
    //����Ҳ���, ��������-1
    if (v != -1) {
        for (int col = 0; col < numVertices; col++)
            if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
                return col;
    }
    return -1;
};

template <class T, class E>
int Graphmtx<T, E>::getNextNeighbor(int v, int w) {
    //�������� v ��ĳ�ڽӶ��� w ����һ���ڽӶ��� 
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
