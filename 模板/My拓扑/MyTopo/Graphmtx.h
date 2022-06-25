#pragma once
struct Edge {
	int x;
	int y;
	int w;
	Edge() { x = y = w = 0xffffffff; }
	Edge(const int& a, const int& b, const int& W) {
		x = a, y = b, w = W;
	}
};

static const int DefaultVertices = 100000;
static const int maxWeight = 0x7fffffff;
class Graphmtx {
public:
	Graphmtx(int sz = DefaultVertices);
	~Graphmtx() {
		delete[]verticesList;
		for (int i = 0; i < maxVertices; i++)
			delete[] edge[i];
		delete[] edge;
	}
	int NumberOfVertices() { return numVertices; }
	int getValue(int i) {
		//取顶点 i 的值, i 不合理返回0
		return i >= 0 && i < numVertices ?
			verticesList[i] : 0xffffffff;
	}
	int getWeight(int v1, int v2) {  //取边(v1,v2)上权值
		return v1 != -1 && v2 != -1 ? edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);
	//取顶点 v 的第一个邻接顶点
	int getNextNeighbor(int v, int w);
	//取 v 的邻接顶点 w 的下一邻接顶点
	bool insertEdge(int v1, int v2, int cost);
	//插入边(v1, v2),权值为cost
private:
	int* verticesList;
	int** edge;
	int maxVertices;
	int numVertices;
	int numEdges;
	int getVertexPos(int vertex) {
		//给出顶点vertex在图中的位置
		for (int i = 0; i < numVertices; i++)
			if (verticesList[i] == vertex) return i;
		return -1;
	}
};