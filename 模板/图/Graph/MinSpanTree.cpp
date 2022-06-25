#include"MinSpanTree.h"

#include "heap.h"
#include "UFSets.h"
template <class T, class E>
void Kruskal(Graph<T, E>& G,
    MinSpanTree<T, E>& MST) {
    MSTEdgeNode<T, E> edge;           //边结点辅助单元
    int u, v, count;
    int n = G.NumberOfVertices();   //顶点数
    int m = G.NumberOfEdges();     //边数
    MinHeap <MSTEdgeNode<T, E>> H(m);   //最小堆  
    UFSets F(n);			     //并查集
    for (u = 0; u < n; u++)
        for (v = u + 1; v < n; v++)
            if (G.getWeight(u, v) != maxValue) {//插入堆
                edge.tail = u;  edge.head = v;
                edge.cost = G.getWeight(u, v);
                H.Insert(edge);
            }
    count = 1;	               //最小生成树边数计数
    while (count < n) {	     //反复执行, 取n-1条边
        H.Remove(edge);	     //退出具最小权值的边
        u = F.Find(edge.tail);  v = F.Find(edge.head);
        //取两顶点所在集合的根u与v
        if (u != v) {          //不是同一集合,不连通
            F.Union(u, v);	    //合并,连通它们  
            MST.Insert(edge);	    //该边存入MST
            count++;
        }
    }
}


#include "heap.h"
template <class T, class E>
void Prim(Graph<T, E>& G, const T u0,
    MinSpanTree<T, E>& MST) {
    MSTEdgeNode<T, E> edge; //边结点辅助单元
    int i, u, v, count;
    int n = G.NumberOfVertices();	  //顶点数	
    int m = G.NumberOfEdges();	  //边数
    int u = G.getVertexPos(u0);		  //起始顶点号
    MinHeap <MSTEdgeNode<T, E>> H(m);  //最小堆
    bool Vmst = new bool[n];   //最小生成树顶点集合
    for (i = 0; i < n; i++) Vmst[i] = false;
    Vmst[u] = true;		        //u 加入生成树
    count = 1;
    do {			        //迭代
        v = G.getFirstNeighbor(u);
        while (v != -1) {	        //检测u所有邻接顶点
            if (!Vmst[v]) {	        //v不在mst中
                edge.tail = u;  edge.head = v;
                edge.cost = G.getWeight(u, v);
                H.Insert(edge);	        //(u,v)加入堆
            }     //堆中存所有u在mst中, v不在mst中的边
            v = G.getNextNeighbor(u, v);
        }

        while (!H.IsEmpty() && count < n) {
            H.Remove(edge);	         //选堆中具最小权的边
            if (!Vmst[edge.head]) {
                MST.Insert(edge);       //加入最小生成树
                u = edge.head;  Vmst[u] = true;
                //u加入生成树顶点集合
                count++;
                break;
            }
        }
    } while (count < n);
};

