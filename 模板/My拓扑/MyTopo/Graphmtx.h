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
		//ȡ���� i ��ֵ, i ��������0
		return i >= 0 && i < numVertices ?
			verticesList[i] : 0xffffffff;
	}
	int getWeight(int v1, int v2) {  //ȡ��(v1,v2)��Ȩֵ
		return v1 != -1 && v2 != -1 ? edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);
	//ȡ���� v �ĵ�һ���ڽӶ���
	int getNextNeighbor(int v, int w);
	//ȡ v ���ڽӶ��� w ����һ�ڽӶ���
	bool insertEdge(int v1, int v2, int cost);
	//�����(v1, v2),ȨֵΪcost
private:
	int* verticesList;
	int** edge;
	int maxVertices;
	int numVertices;
	int numEdges;
	int getVertexPos(int vertex) {
		//��������vertex��ͼ�е�λ��
		for (int i = 0; i < numVertices; i++)
			if (verticesList[i] == vertex) return i;
		return -1;
	}
};