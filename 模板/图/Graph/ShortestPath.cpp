#include"Graph.h"

template <class T, class E>
void Dijkstra(Graph<T, E>& G, T v,
    E dist[], int path[]) {
    //Graph��һ����Ȩ����ͼ��dist[j], 0��j<n, �ǵ�ǰ
    //�󵽵ĴӶ���v������j�����·������, path[j],
    //0��j<n, ����󵽵����·����
    int n = G.NumberOfVertices();
    bool* S = new bool[n]; 	   //���·�����㼯
    int i, j, k;  E w, min;
    for (i = 0; i < n; i++) {
        dist[i] = G.getWeight(v, i);
        S[i] = false;
        if (i != v && dist[i] < maxValue) path[i] = v;
        else path[i] = -1;
    }
    S[v] = true;  dist[v] = 0;     	//����v���붥�㼯��
    for (i = 0; i < n - 1; i++) {       //�����������·��
        min = maxValue;  int u = v; 		//ѡ����S�о������·���Ķ���u
        for (j = 0; j < n; j++)
            if (!S[j] && dist[j] < min)
            {
                u = j; min = dist[j];
            }
        S[u] = true;	               	//������u���뼯��S
        for (k = 0; k < n; k++) {       	//�޸�
            w = G.GetWeight(u, k);
            if (!S[k] && w < maxValue &&
                dist[u] + w < dist[k]) {       //����kδ����S                
                dist[k] = dist[u] + w;
                path[k] = u;     		//�޸ĵ�k�����·��
            }
        }
    }
};

template <class T, class E>
void Floyd(Graph<T, E>& G, E** a, int** path) {
    //a[i][j]�Ƕ���i��j֮������·�����ȡ�path[i][j]
    //����Ӧ·���϶���j��ǰһ����Ķ���š�
    int n = G.numVertices();
    for (int i = 0; i < n; i++)    	//����a��path��ʼ��
        for (int j = 0; j < n; j++) {
            a[i][j] = G.getWeight(i, j);
            if (i != j && a[i][j] < maxValue) path[i][j] = i;
            else path[i][j] = 0;
        }
    for (int k = 0; k < n; k++)
        //���ÿһ��k, ����a(k)��path(k)        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = path[k][j];
                    //����·������, �ƹ� k �� j
                }
};
