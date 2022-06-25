#pragma once
#include"Graph.h"

#include<iostream>
using namespace std;

const int maxValue = 0x7fffffff;
static const int DefaultSize = 10000;
//机器可表示的、问题中不可能出现的大数
template <class T, class E>
struct MSTEdgeNode {		//树边结点的类定义
    int tail, head;			//两顶点位置
    E cost;				//边上的权值
    MSTEdgeNode() : tail(-1), head(-1), cost(0) { }						//构造函数		
};

template <class T, class E>
class MinSpanTree {	//树的类定义
protected:
    MSTEdgeNode<T, E>* edgevalue;//边值数组   int maxSize; //最大元素个数
    int currentSize; //当前元素个数
    int maxSize;
public:
    MinSpanTree(int sz = DefaultSize - 1) :
        maxSize(sz), currentSize(0) {
        edgevalue = new MSTEdgeNode<T, E>[sz];
    }
    int Insert(MSTEdgeNode<T, E>& item) { cout << "please implement me in MinSpanTree.h|.cpp MinSpanTree.Insert();" << endl; };
};

#include "heap.h"
template <class T, class E>
void Prim(Graph<T, E>& G, const T u0, MinSpanTree<T, E>& MST);