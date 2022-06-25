#pragma once
#include"Graph.h"
#include<iostream>

//�ڽӱ�洢
template <class T, class E>
class Graph;

template <class T, class E>
struct Edge {			   //�߽��Ķ���
    int dest;				   //�ߵ���һ����λ��
    E cost;				   //���ϵ�Ȩֵ
    Edge<T, E>* link;		   //��һ������ָ��
    Edge() {}				   //���캯��
    Edge(int num, E c) 	   //���캯��
        : dest(num), cost(c), link(NULL) { }
    bool operator != (Edge<T, E>& R) const
    {
        return dest != R.dest ? true : false;
    }   //�бߵȷ�
};

template <class T, class E>
struct Vertex {			   //����Ķ���
    T data;				   //���������
    Edge<T, E>* adj;		   //�������ͷָ��
};

template <class T, class E>
class Graphlnk : public Graph<T, E> {   //ͼ���ඨ��
private:
    Vertex<T, E>* NodeTable;
    int maxVertices;
    int numVertices;
    int numEdges;
    //����� (���������ͷ���)
    int getVertexPos(const T vertex) {
        //��������vertex��ͼ�е�λ��
        for (int i = 0; i < numVertices; i++)
            if (NodeTable[i].data == vertex) return i;
        return -1;
    }
public:
    Graphlnk(int sz = DefaultVertices);  //���캯��
    ~Graphlnk();				   //��������
    T getValue(int i) {		     //ȡ���� i ��ֵ
        return (i >= 0 && i < numVertices) ?
            NodeTable[i].data : 0;
    }
    E getWeight(int v1, int v2);	     //ȡ��(v1,v2)Ȩֵ
    bool insertVertex(const T& vertex);
    bool removeVertex(int v);
    bool insertEdge(int v1, int v2, E cost);
    bool removeEdge(int v1, int v2);
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v, int w);
};
