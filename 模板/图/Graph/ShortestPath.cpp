#include"Graph.h"

template <class T, class E>
void Dijkstra(Graph<T, E>& G, T v,
    E dist[], int path[]) {
    //Graph是一个带权有向图。dist[j], 0≤j<n, 是当前
    //求到的从顶点v到顶点j的最短路径长度, path[j],
    //0≤j<n, 存放求到的最短路径。
    int n = G.NumberOfVertices();
    bool* S = new bool[n]; 	   //最短路径顶点集
    int i, j, k;  E w, min;
    for (i = 0; i < n; i++) {
        dist[i] = G.getWeight(v, i);
        S[i] = false;
        if (i != v && dist[i] < maxValue) path[i] = v;
        else path[i] = -1;
    }
    S[v] = true;  dist[v] = 0;     	//顶点v加入顶点集合
    for (i = 0; i < n - 1; i++) {       //求解各顶点最短路径
        min = maxValue;  int u = v; 		//选不在S中具有最短路径的顶点u
        for (j = 0; j < n; j++)
            if (!S[j] && dist[j] < min)
            {
                u = j; min = dist[j];
            }
        S[u] = true;	               	//将顶点u加入集合S
        for (k = 0; k < n; k++) {       	//修改
            w = G.GetWeight(u, k);
            if (!S[k] && w < maxValue &&
                dist[u] + w < dist[k]) {       //顶点k未加入S                
                dist[k] = dist[u] + w;
                path[k] = u;     		//修改到k的最短路径
            }
        }
    }
};

template <class T, class E>
void Floyd(Graph<T, E>& G, E** a, int** path) {
    //a[i][j]是顶点i和j之间的最短路径长度。path[i][j]
    //是相应路径上顶点j的前一顶点的顶点号。
    int n = G.numVertices();
    for (int i = 0; i < n; i++)    	//矩阵a与path初始化
        for (int j = 0; j < n; j++) {
            a[i][j] = G.getWeight(i, j);
            if (i != j && a[i][j] < maxValue) path[i][j] = i;
            else path[i][j] = 0;
        }
    for (int k = 0; k < n; k++)
        //针对每一个k, 产生a(k)及path(k)        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = path[k][j];
                    //缩短路径长度, 绕过 k 到 j
                }
};
