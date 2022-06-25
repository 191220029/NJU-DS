#pragma once
#include"Graph.h"

#include<iostream>
using namespace std;

const int maxValue = 0x7fffffff;
static const int DefaultSize = 10000;
//�����ɱ�ʾ�ġ������в����ܳ��ֵĴ���
template <class T, class E>
struct MSTEdgeNode {		//���߽����ඨ��
    int tail, head;			//������λ��
    E cost;				//���ϵ�Ȩֵ
    MSTEdgeNode() : tail(-1), head(-1), cost(0) { }						//���캯��		
};

template <class T, class E>
class MinSpanTree {	//�����ඨ��
protected:
    MSTEdgeNode<T, E>* edgevalue;//��ֵ����   int maxSize; //���Ԫ�ظ���
    int currentSize; //��ǰԪ�ظ���
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