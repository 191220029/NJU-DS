#pragma once
#include"Graph.h"
#include<iostream>
using namespace std;

//DFS
template<class T, class E>
void DFS(Graph<T, E>& G, int v, bool visited[]) {
    cout << G.getValue(v) << ' ';        //���ʶ���v
    visited[v] = true;	 	         //�����ʱ��
    int w = G.getFirstNeighbor(v);     //��һ���ڽӶ���
    while (w != -1) {	//���ڽӶ���w����
        if (!visited[w]) DFS(G, w, visited);
        //��wδ���ʹ�, �ݹ���ʶ���w
        w = G.getNextNeighbor(v, w); //��һ���ڽӶ���
    }
};

template<class T, class E>
void DFS(Graph<T, E>& G, const T& v) {
    //�Ӷ���v������ͼG�����������������������
    int i, loc, n = G.NumberOfVertices();    //�������
    bool* visited = new bool[n];          //������������
    for (i = 0; i < n; i++) visited[i] = false;
    //��������visited��ʼ��
    loc = G.getVertexPos(v);
    DFS(G, loc, visited); //�Ӷ���loc��ʼ�����������
    delete[] visited;			        //�ͷ�visited
};

//BFS
template <class T, class E>
void BFS(Graph<T, E>& G, const T& v) {
    int i, w, n = G.NumberOfVertices();
    //ͼ�ж������
    bool* visited = new bool[n];
    for (i = 0; i < n; i++) visited[i] = false;
    int loc = G.getVertexPos(v);		//ȡ�����
    cout << G.getValue(loc) << ' '; 	//���ʶ���v
    visited[loc] = true; 	                     //���ѷ��ʱ��       
    Queue<int> Q;  Q.EnQueue(loc); 					//���������, ʵ�ֲַ����
    while (!Q.IsEmpty()) {	//ѭ��, �������н��
        Q.DeQueue(loc);
        w = G.getFirstNeighbor(loc);  //��һ���ڽӶ���
        while (w != -1) {		//���ڽӶ���w����
            if (!visited[w]) {		//��δ���ʹ�
                cout << G.getValue(w) << ' ';	//����
                visited[w] = true;
                Q.EnQueue(w); 		//����w������
            }
            w = G.getNextNeighbor(loc, w); 			             //�Ҷ���loc����һ���ڽӶ���
        }
    }		   //���ѭ�����ж��пշ�
    delete[] visited;
};

//����ͨ����
void OutputNewComponent() {
    cout << " ***please implement me in Graph.cpp OutputNewComponent()***" << endl;
}

template <class T, class E>
void Components(Graph<T, E>& G) {
    //ͨ��DFS���ҳ�����ͼ��������ͨ����
    int i, n = G.NumberOfVertices(); 	//ͼ�ж������
    bool* visited = new bool[n]; 		//���ʱ������
    for (i = 0; i < n; i++) visited[i] = false;
    for (i = 0; i < n; i++) 			//ɨ�����ж���
        if (!visited[i]) {			//��û�з��ʹ�
            DFS(G, i, visited);		//����
            OutputNewComponent(); 	//�����ͨ����
        }
    delete[] visited;
}



