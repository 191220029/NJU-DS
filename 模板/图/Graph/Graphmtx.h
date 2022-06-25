#pragma once
#include"Graph.h"
#include<iostream>
//�ڽӾ���洢

template <class T, class E>
class Graph;

template <class T, class E>
class Graphmtx : public Graph<T, E> {

private:
    T* VerticesList; 			//�����
    E** Edge;				//�ڽӾ���
    int maxVertices;
    int numVertices;
    int numEdges;
    int getVertexPos(T vertex) {
        //��������vertex��ͼ�е�λ��
        for (int i = 0; i < numVertices; i++)
            if (VerticesList[i] == vertex) return i;
        return -1;
    };
public:
    Graphmtx(int sz = DefaultVertices);    //���캯��
    ~Graphmtx()				      //��������
    {
        delete[]VerticesList;
        for (int i = 0; i < maxVertices; i++)
            delete[] Edge[i];
        delete[] Edge;
    }
    T getValue(int i) {
        //ȡ���� i ��ֵ, i ��������0
        return i >= 0 && i < numVertices ?
            VerticesList[i] : NULL;
    }
    E getWeight(int v1, int v2) {  //ȡ��(v1,v2)��Ȩֵ
        return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
    }

    int getFirstNeighbor(int v);
    //ȡ���� v �ĵ�һ���ڽӶ���
    int getNextNeighbor(int v, int w);
    //ȡ v ���ڽӶ��� w ����һ�ڽӶ���
    bool insertVertex(const T vertex);
    //���붥��vertex
    bool insertEdge(int v1, int v2, E cost);
    //�����(v1, v2),ȨֵΪcost
    bool removeVertex(int v);
    //ɾȥ���� v ����������������ı�
    bool removeEdge(int v1, int v2);
    //��ͼ��ɾȥ��(v1,v2)
};





