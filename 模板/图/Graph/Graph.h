#pragma once
#include"Graphmtx.h"
#include"Graphlnk.h"
#include"MinSpanTree.h"
#include"Queue.h"

const int maxWeight = 0x7fffffff;	    //无穷大的值(=)
const int DefaultVertices = 30;	    //最大顶点数(=n)
template <class T, class E>
class Graph {			    //图的类定义
protected:
    int maxVertices;		    //图中最大顶点数
    int numEdges;			    //当前边数
    int numVertices;		    //当前顶点数
    virtual int getVertexPos(T vertex);
    //给出顶点vertex在图中位置
public:
    Graph(int sz = DefaultVertices);  	//构造函数
    ~Graph();				//析构函数
    bool GraphEmpty() const 		//判图空否
    {
        return numEdges == 0;
    }
    int NumberOfVertices() { return numVertices; }
    //返回当前顶点数
    int NumberOfEdges() { return numEdges; }
    /*
    //返回当前边数
    virtual T getValue(int i);		//取顶点 i 的值
    virtual E getWeight(int v1, int v2);  //取边上权值
    virtual int getFirstNeighbor(int v);
    //取顶点 v 的第一个邻接顶点
    virtual int getNextNeighbor(int v, int w);
    //取邻接顶点 w 的下一邻接顶点
    virtual bool insertVertex(const T vertex);
    //插入一个顶点vertex
    virtual bool insertEdge(int v1, int v2, E cost);
    //插入边(v1,v2), 权为cost
    virtual bool removeVertex(int v);
    //删去顶点 v 和所有与相关联边
    virtual bool removeEdge(int v1, int v2);
    //在图中删去边(v1,v2)
    */
};

//DFS
template<class T, class E>
void DFS(Graph<T, E>& G, int v, bool visited[]);

template<class T, class E>
void DFS(Graph<T, E>& G, const T& v);

//BFS
template <class T, class E>
void BFS(Graph<T, E>& G, const T& v);

//求连通分量
template <class T, class E>
void Components(Graph<T, E>& G);


