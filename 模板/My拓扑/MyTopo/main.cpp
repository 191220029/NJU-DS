#pragma once
#include<iostream>
#include"Graphmtx.h"
using namespace std;

void TopologicalSort(Graphmtx& G) {
    int i, j, w, v;
    int worth;
    int top = -1;              //入度为零的顶点栈初始化
    int n = G.NumberOfVertices();    //网络中顶点个数
    int* count = new int[n];    					                            //入度数组兼入度为零的顶点栈
    for (i = 0; i < n; i++) count[i] = 0;
    cin >> i >> j >> worth;   	       //输入一条边(i, j, w)
    while (i > -1 && i < n && j > -1 && j < n) {
        G.insertEdge(i, j, worth);  count[j]++;
        cin >> i >> j >> worth;
    }
    for (i = 0; i < n; i++)      	//检查网络所有顶点
        if (count[i] == 0)        	//入度为零的顶点进栈
        {
            count[i] = top;  top = i;
        }
    for (i = 0; i < n; i++)      	//期望输出n个顶点
        if (top == -1) {           	//中途栈空,转出
            cout << "网络中有回路！" << endl;
            return;
        }
        else {                               	//继续拓扑排序
            v = top;  top = count[top];   	//退栈v
            //cout << G.getValue(v) << "  " << endl;   //输出
            cout << v << "  " << endl;   //输出
            w = G.getFirstNeighbor(v);
            while (w != -1) {    	 //扫描顶点v的出边表
                count[w]--; 		 //邻接顶点入度减一
                if (count[w] == 0)               //入度减至零,进栈
                {
                    count[w] = top;  top = w;
                }
                w = G.getNextNeighbor(v, w);
            }     //一个顶点输出后，调整其邻接顶点入度
        }      //输出一个顶点，继续for循环
};

void CriticalPath(Graphmtx& G) {
    int i, j, k;   int Ae, Al, dur;
    int n = G.NumberOfVertices();
    int worth;
    cin >> i >> j >> worth;   	       //输入一条边(i, j, w)
    while (i > -1 && i < n && j > -1 && j < n) {
        G.insertEdge(i, j, worth);  
        cin >> i >> j >> worth;
    }

    int* Ve = new int[n];  int* Vl = new int[n];
    for (i = 0; i < n; i++) Ve[i] = 0;
    for (i = 0; i < n; i++) Vl[i] = maxWeight;
    for (i = 0; i < n; i++) {  //正向计算Ve[]，假设已经按拓扑排序从0到n-1编号
        j = G.getFirstNeighbor(i);
        while (j != -1) {
            dur = G.getWeight(i, j);
            if (Ve[i] + dur > Ve[j]) Ve[j] = Ve[i] + dur;
            j = G.getNextNeighbor(i, j);
        }
    }
    Vl[n - 1] = Ve[n - 1];
    for (j = n - 2; j > 0; j--) {       //逆向计算Vl[]
        k = G.getFirstNeighbor(j);
        while (k != -1) {
            dur = G.getWeight(j, k);
            if (Vl[k] - dur < Vl[j]) Vl[j] = Vl[k] - dur;
            k = G.getNextNeighbor(j, k);
        }
    }
    for (i = 0; i < n; i++) {		//求各活动的Ae, Al
        j = G.getFirstNeighbor(i);
        while (j != -1) {
            Ae = Ve[i];  Al = Vl[j] - G.getWeight(i, j);
            if (Al == Ae)
                //cout << "<" << G.getValue(i) << ","
                //<< G.getValue(j) << " > "
                //<< "是关键活动" << endl;
                cout << "<" << i << ","
                << j << "> "
                << "是关键活动" << endl;
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