#include"MinSpanTree.h"

#include "heap.h"
#include "UFSets.h"
template <class T, class E>
void Kruskal(Graph<T, E>& G,
    MinSpanTree<T, E>& MST) {
    MSTEdgeNode<T, E> edge;           //�߽�㸨����Ԫ
    int u, v, count;
    int n = G.NumberOfVertices();   //������
    int m = G.NumberOfEdges();     //����
    MinHeap <MSTEdgeNode<T, E>> H(m);   //��С��  
    UFSets F(n);			     //���鼯
    for (u = 0; u < n; u++)
        for (v = u + 1; v < n; v++)
            if (G.getWeight(u, v) != maxValue) {//�����
                edge.tail = u;  edge.head = v;
                edge.cost = G.getWeight(u, v);
                H.Insert(edge);
            }
    count = 1;	               //��С��������������
    while (count < n) {	     //����ִ��, ȡn-1����
        H.Remove(edge);	     //�˳�����СȨֵ�ı�
        u = F.Find(edge.tail);  v = F.Find(edge.head);
        //ȡ���������ڼ��ϵĸ�u��v
        if (u != v) {          //����ͬһ����,����ͨ
            F.Union(u, v);	    //�ϲ�,��ͨ����  
            MST.Insert(edge);	    //�ñߴ���MST
            count++;
        }
    }
}


#include "heap.h"
template <class T, class E>
void Prim(Graph<T, E>& G, const T u0,
    MinSpanTree<T, E>& MST) {
    MSTEdgeNode<T, E> edge; //�߽�㸨����Ԫ
    int i, u, v, count;
    int n = G.NumberOfVertices();	  //������	
    int m = G.NumberOfEdges();	  //����
    int u = G.getVertexPos(u0);		  //��ʼ�����
    MinHeap <MSTEdgeNode<T, E>> H(m);  //��С��
    bool Vmst = new bool[n];   //��С���������㼯��
    for (i = 0; i < n; i++) Vmst[i] = false;
    Vmst[u] = true;		        //u ����������
    count = 1;
    do {			        //����
        v = G.getFirstNeighbor(u);
        while (v != -1) {	        //���u�����ڽӶ���
            if (!Vmst[v]) {	        //v����mst��
                edge.tail = u;  edge.head = v;
                edge.cost = G.getWeight(u, v);
                H.Insert(edge);	        //(u,v)�����
            }     //���д�����u��mst��, v����mst�еı�
            v = G.getNextNeighbor(u, v);
        }

        while (!H.IsEmpty() && count < n) {
            H.Remove(edge);	         //ѡ���о���СȨ�ı�
            if (!Vmst[edge.head]) {
                MST.Insert(edge);       //������С������
                u = edge.head;  Vmst[u] = true;
                //u�������������㼯��
                count++;
                break;
            }
        }
    } while (count < n);
};

