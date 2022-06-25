#pragma once
#include"Graph.h"
#include<iostream>

//邻接表存储
template <class T, class E>
class Graph;

template <class T, class E>
struct Edge {			   //边结点的定义
    int dest;				   //边的另一顶点位置
    E cost;				   //边上的权值
    Edge<T, E>* link;		   //下一条边链指针
    Edge() {}				   //构造函数
    Edge(int num, E c) 	   //构造函数
        : dest(num), cost(c), link(NULL) { }
    bool operator != (Edge<T, E>& R) const
    {
        return dest != R.dest ? true : false;
    }   //判边等否
};

template <class T, class E>
struct Vertex {			   //顶点的定义
    T data;				   //顶点的名字
    Edge<T, E>* adj;		   //边链表的头指针
};

template <class T, class E>
class Graphlnk : public Graph<T, E> {   //图的类定义
private:
    Vertex<T, E>* NodeTable;
    int maxVertices;
    int numVertices;
    int numEdges;
    //顶点表 (各边链表的头结点)
    int getVertexPos(const T vertex) {
        //给出顶点vertex在图中的位置
        for (int i = 0; i < numVertices; i++)
            if (NodeTable[i].data == vertex) return i;
        return -1;
    }
public:
    Graphlnk(int sz = DefaultVertices);  //构造函数
    ~Graphlnk();				   //析构函数
    T getValue(int i) {		     //取顶点 i 的值
        return (i >= 0 && i < numVertices) ?
            NodeTable[i].data : 0;
    }
    E getWeight(int v1, int v2);	     //取边(v1,v2)权值
    bool insertVertex(const T& vertex);
    bool removeVertex(int v);
    bool insertEdge(int v1, int v2, E cost);
    bool removeEdge(int v1, int v2);
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v, int w);
};
