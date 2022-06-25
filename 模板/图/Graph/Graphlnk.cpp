#include"Graphlnk.h"
#include<iostream>
using namespace std;
template <class T, class E>
Graphlnk<T, E>::Graphlnk(int sz) {
    //构造函数：建立一个空的邻接表
    maxVertices = sz;
    numVertices = 0;  numEdges = 0;
    NodeTable = new Vertex<T, E>[maxVertices];		//创建顶点表数组
    if (NodeTable == NULL)
    {
        cout << "存储分配错！" << endl;  exit(1);
    }
    for (int i = 0; i < maxVertices; i++)
        NodeTable[i].adj = NULL;
};

template <class T, class E>
Graphlnk<T, E>::~Graphlnk() {
    //析构函数：删除一个邻接表
    for (int i = 0; i < maxVertices; i++) {
        Edge<T, E>* p = NodeTable[i].adj;
        while (p != NULL) {
            NodeTable[i].adj = p->link;
            delete p;  p = NodeTable[i].adj;
        }
    }
    delete[]NodeTable;  		     //删除顶点表数组
};

template <class T, class E>
int Graphlnk<T, E>::getFirstNeighbor(int v) {
    //给出顶点位置为 v 的第一个邻接顶点的位置, 
    //如果找不到, 则函数返回-1
    if (v != -1) {			//顶点v存在
        Edge<T, E>* p = NodeTable[v].adj;			//对应边链表第一个边结点
        if (p != NULL) return p->dest;				//存在, 返回第一个邻接顶点
    }
    return -1;		//第一个邻接顶点不存在
};

template <class T, class E>
int Graphlnk<T, E>::getNextNeighbor(int v, int w) {
    //给出顶点v的邻接顶点w的下一个邻接顶点的位置,
    //若没有下一个邻接顶点, 则函数返回-1
    if (v != -1) {				//顶点v存在
        Edge<T, E>* p = NodeTable[v].adj;
        while (p != NULL && p->dest != w)
            p = p->link;
        if (p != NULL && p->link != NULL)
            return p->link->dest; 	//返回下一个邻接顶点
    }
    return -1; 			//下一邻接顶点不存在
};
