#pragma once
#include"Graph.h"
#include<iostream>
using namespace std;

//DFS
template<class T, class E>
void DFS(Graph<T, E>& G, int v, bool visited[]) {
    cout << G.getValue(v) << ' ';        //访问顶点v
    visited[v] = true;	 	         //作访问标记
    int w = G.getFirstNeighbor(v);     //第一个邻接顶点
    while (w != -1) {	//若邻接顶点w存在
        if (!visited[w]) DFS(G, w, visited);
        //若w未访问过, 递归访问顶点w
        w = G.getNextNeighbor(v, w); //下一个邻接顶点
    }
};

template<class T, class E>
void DFS(Graph<T, E>& G, const T& v) {
    //从顶点v出发对图G进行深度优先搜索的主过程
    int i, loc, n = G.NumberOfVertices();    //顶点个数
    bool* visited = new bool[n];          //创建辅助数组
    for (i = 0; i < n; i++) visited[i] = false;
    //辅助数组visited初始化
    loc = G.getVertexPos(v);
    DFS(G, loc, visited); //从顶点loc开始深度优先搜索
    delete[] visited;			        //释放visited
};

//BFS
template <class T, class E>
void BFS(Graph<T, E>& G, const T& v) {
    int i, w, n = G.NumberOfVertices();
    //图中顶点个数
    bool* visited = new bool[n];
    for (i = 0; i < n; i++) visited[i] = false;
    int loc = G.getVertexPos(v);		//取顶点号
    cout << G.getValue(loc) << ' '; 	//访问顶点v
    visited[loc] = true; 	                     //做已访问标记       
    Queue<int> Q;  Q.EnQueue(loc); 					//顶点进队列, 实现分层访问
    while (!Q.IsEmpty()) {	//循环, 访问所有结点
        Q.DeQueue(loc);
        w = G.getFirstNeighbor(loc);  //第一个邻接顶点
        while (w != -1) {		//若邻接顶点w存在
            if (!visited[w]) {		//若未访问过
                cout << G.getValue(w) << ' ';	//访问
                visited[w] = true;
                Q.EnQueue(w); 		//顶点w进队列
            }
            w = G.getNextNeighbor(loc, w); 			             //找顶点loc的下一个邻接顶点
        }
    }		   //外层循环，判队列空否
    delete[] visited;
};

//求连通分量
void OutputNewComponent() {
    cout << " ***please implement me in Graph.cpp OutputNewComponent()***" << endl;
}

template <class T, class E>
void Components(Graph<T, E>& G) {
    //通过DFS，找出无向图的所有连通分量
    int i, n = G.NumberOfVertices(); 	//图中顶点个数
    bool* visited = new bool[n]; 		//访问标记数组
    for (i = 0; i < n; i++) visited[i] = false;
    for (i = 0; i < n; i++) 			//扫描所有顶点
        if (!visited[i]) {			//若没有访问过
            DFS(G, i, visited);		//访问
            OutputNewComponent(); 	//输出连通分量
        }
    delete[] visited;
}



