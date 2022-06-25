#include"Graphlnk.h"
#include<iostream>
using namespace std;
template <class T, class E>
Graphlnk<T, E>::Graphlnk(int sz) {
    //���캯��������һ���յ��ڽӱ�
    maxVertices = sz;
    numVertices = 0;  numEdges = 0;
    NodeTable = new Vertex<T, E>[maxVertices];		//�������������
    if (NodeTable == NULL)
    {
        cout << "�洢�����" << endl;  exit(1);
    }
    for (int i = 0; i < maxVertices; i++)
        NodeTable[i].adj = NULL;
};

template <class T, class E>
Graphlnk<T, E>::~Graphlnk() {
    //����������ɾ��һ���ڽӱ�
    for (int i = 0; i < maxVertices; i++) {
        Edge<T, E>* p = NodeTable[i].adj;
        while (p != NULL) {
            NodeTable[i].adj = p->link;
            delete p;  p = NodeTable[i].adj;
        }
    }
    delete[]NodeTable;  		     //ɾ�����������
};

template <class T, class E>
int Graphlnk<T, E>::getFirstNeighbor(int v) {
    //��������λ��Ϊ v �ĵ�һ���ڽӶ����λ��, 
    //����Ҳ���, ��������-1
    if (v != -1) {			//����v����
        Edge<T, E>* p = NodeTable[v].adj;			//��Ӧ�������һ���߽��
        if (p != NULL) return p->dest;				//����, ���ص�һ���ڽӶ���
    }
    return -1;		//��һ���ڽӶ��㲻����
};

template <class T, class E>
int Graphlnk<T, E>::getNextNeighbor(int v, int w) {
    //��������v���ڽӶ���w����һ���ڽӶ����λ��,
    //��û����һ���ڽӶ���, ��������-1
    if (v != -1) {				//����v����
        Edge<T, E>* p = NodeTable[v].adj;
        while (p != NULL && p->dest != w)
            p = p->link;
        if (p != NULL && p->link != NULL)
            return p->link->dest; 	//������һ���ڽӶ���
    }
    return -1; 			//��һ�ڽӶ��㲻����
};
