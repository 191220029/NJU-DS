#pragma once
#include"Graph.h"
#include<iostream>
//邻接矩阵存储

template <class T, class E>
class Graph;

template <class T, class E>
class Graphmtx : public Graph<T, E> {

private:
    T* VerticesList; 			//顶点表
    E** Edge;				//邻接矩阵
    int maxVertices;
    int numVertices;
    int numEdges;
    int getVertexPos(T vertex) {
        //给出顶点vertex在图中的位置
        for (int i = 0; i < numVertices; i++)
            if (VerticesList[i] == vertex) return i;
        return -1;
    };
public:
    Graphmtx(int sz = DefaultVertices);    //构造函数
    ~Graphmtx()				      //析构函数
    {
        delete[]VerticesList;
        for (int i = 0; i < maxVertices; i++)
            delete[] Edge[i];
        delete[] Edge;
    }
    T getValue(int i) {
        //取顶点 i 的值, i 不合理返回0
        return i >= 0 && i < numVertices ?
            VerticesList[i] : NULL;
    }
    E getWeight(int v1, int v2) {  //取边(v1,v2)上权值
        return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
    }

    int getFirstNeighbor(int v);
    //取顶点 v 的第一个邻接顶点
    int getNextNeighbor(int v, int w);
    //取 v 的邻接顶点 w 的下一邻接顶点
    bool insertVertex(const T vertex);
    //插入顶点vertex
    bool insertEdge(int v1, int v2, E cost);
    //插入边(v1, v2),权值为cost
    bool removeVertex(int v);
    //删去顶点 v 和所有与它相关联的边
    bool removeEdge(int v1, int v2);
    //在图中删去边(v1,v2)
};





