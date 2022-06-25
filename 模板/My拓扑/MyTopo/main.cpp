#pragma once
#include<iostream>
#include"Graphmtx.h"
using namespace std;

void TopologicalSort(Graphmtx& G) {
    int i, j, w, v;
    int worth;
    int top = -1;              //���Ϊ��Ķ���ջ��ʼ��
    int n = G.NumberOfVertices();    //�����ж������
    int* count = new int[n];    					                            //�����������Ϊ��Ķ���ջ
    for (i = 0; i < n; i++) count[i] = 0;
    cin >> i >> j >> worth;   	       //����һ����(i, j, w)
    while (i > -1 && i < n && j > -1 && j < n) {
        G.insertEdge(i, j, worth);  count[j]++;
        cin >> i >> j >> worth;
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
            //cout << G.getValue(v) << "  " << endl;   //���
            cout << v << "  " << endl;   //���
            w = G.getFirstNeighbor(v);
            while (w != -1) {    	 //ɨ�趥��v�ĳ��߱�
                count[w]--; 		 //�ڽӶ�����ȼ�һ
                if (count[w] == 0)               //��ȼ�����,��ջ
                {
                    count[w] = top;  top = w;
                }
                w = G.getNextNeighbor(v, w);
            }     //һ����������󣬵������ڽӶ������
        }      //���һ�����㣬����forѭ��
};

void CriticalPath(Graphmtx& G) {
    int i, j, k;   int Ae, Al, dur;
    int n = G.NumberOfVertices();
    int worth;
    cin >> i >> j >> worth;   	       //����һ����(i, j, w)
    while (i > -1 && i < n && j > -1 && j < n) {
        G.insertEdge(i, j, worth);  
        cin >> i >> j >> worth;
    }

    int* Ve = new int[n];  int* Vl = new int[n];
    for (i = 0; i < n; i++) Ve[i] = 0;
    for (i = 0; i < n; i++) Vl[i] = maxWeight;
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
                //cout << "<" << G.getValue(i) << ","
                //<< G.getValue(j) << " > "
                //<< "�ǹؼ��" << endl;
                cout << "<" << i << ","
                << j << "> "
                << "�ǹؼ��" << endl;
            j = G.getNextNeighbor(i, j);
        }
    }
    delete[] Ve;  delete[] Vl;
};


int main() {
    int n; //num of vertex
    cin >> n;
    Graphmtx G1(n);
    //TopologicalSort(G1);
    CriticalPath(G1);
	return 0;
}

/*
* test bench for TopologicalSort();
6
0 1 1
0 3 1
1 5 1
2 1 1
2 5 1
4 0 1
4 1 1
4 5 1
-1 -1 -1
* test bench for CriticalPath();
8
0 1 8
0 2 12
1 3 14
2 3 10
2 5 28
3 4 6
3 5 8
4 6 18
5 6 6
6 7 12
-1 -1 -1
*/