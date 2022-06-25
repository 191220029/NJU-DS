#include"Graph.h"
#include<iostream>
using namespace std;

template <class T, class E>
void TopologicalSort(Graph<T, E>& G) {
    int i, j, w, v;
    int top = -1;              //���Ϊ��Ķ���ջ��ʼ��
    int n = G.NumberOfVertices();    //�����ж������
    int* count = new int[n];    					                            //�����������Ϊ��Ķ���ջ
    for (i = 0; i < n; i++) count[i] = 0;
    cin >> i >> j;   	       //����һ����(i, j)
    while (i > -1 && i < n && j > -1 && j < n) {
        G.insertEdge(i, j);  count[j]++;
        cin >> i >> j;
    }
    for (i = 0; i < n; i++)      	//����������ж���
        if (count[i] == 0)        	//���Ϊ��Ķ����ջ
        {
            count[i] = top;  top = i;
        }
    for (i = 0; i < n; i++)      	//�������n������
        if (top == -1) {           	//��;ջ��,ת��
            cout << "�������л�·��" << endl;
                return;
        }
        else {                               	//������������
            v = top;  top = count[top];   	//��ջv
            cout << G.getValue(v) << "  " << endl;   //���
            w = G.GetFirstNeighbor(v);
            while (w != -1) {    	 //ɨ�趥��v�ĳ��߱�
                count[w]--; 		 //�ڽӶ�����ȼ�һ
                if (count[w] == 0)               //��ȼ�����,��ջ
                {
                    count[w] = top;  top = w;
                }
                w = G.GetNextNeighbor(v, w);
            }     //һ����������󣬵������ڽӶ������
        }      //���һ�����㣬����forѭ��
};

template <class T, class E>
void CriticalPath(Graph<T, E>& G) {
    int i, j, k;   E Ae, Al, dur;
    int n = G.NumberOfVertices();
    E* Ve = new E[n];  E* Vl = new E[n];
    for (i = 0; i < n; i++) Ve[i] = 0;
    for (i = 0; i < n; i++) {  //�������Ve[]�������Ѿ������������0��n-1���
        j = G.getFirstNeighbor(i);
        while (j != -1) {
            dur = G.getWeight(i, j);
            if (Ve[i] + dur > Ve[j]) Ve[j] = Ve[i] + dur;
            j = G.getNextNeighbor(i, j);
        }
    }
    Vl[n - 1] = Ve[n - 1];
    for (j = n - 2; j > 0; j--) {       //�������Vl[]
        k = G.getFirstNeighbor(j);
        while (k != -1) {
            dur = G.getWeight(j, k);
            if (Vl[k] - dur < Vl[j]) Vl[j] = Vl[k] - dur;
            k = G.getNextNeighbor(j, k);
        }
    }
    for (i = 0; i < n; i++) {		//������Ae, Al
        j = G.getFirstNeighbor(i);
        while (j != -1) {
            Ae = Ve[i];  Al = Vl[j] - G.getWeight(i, j);
            if (Al == Ae)
                cout << "<" << G.getValue(i) << ","
                << G.getValue(j) << " > "
                << "�ǹؼ��" << endl;
            j = G.getNextNeighbor(i, j);
        }
    }
    delete[] Ve;  delete[] Vl;
};

