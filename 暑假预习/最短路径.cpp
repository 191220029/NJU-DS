//最短路径
//Dijkstra算法
typedef int Patharc[MAXVEX];	//存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX]//存储到各点最短路径的权值和

void ShortestPath_Dijkstra(MGraph G, int V0, Patharc *P, ShortPathTable *D){
	int v, w, k, min;
	int final[MAXVEX];	//final[w]=1 表示已经求得点v0到vw的最短路径
	
	//初始化
	for(v=0;v<G.numVertexes; v++){
		final[v] = 0; //全部定点初始化为未找到最短路
		(*D)[V]=G.arc[V0][v]//将与v0点有连线的顶点加上权值
		(*P)[V] = 0;//初始化路径数组P为0
	}
	
	(*D)[V0] = 0;//v0至v0的路径为0
	final[V0]=1;//v0到v0不需要路径
	
	//每次循环求得v0到某个顶点v的最短路径
	for(v=0;v<G.numVertexes;v++){
		min = INFINITY;
		for(w=0;w<G.numVertexes;w++){
			if(!final[w] && (*D)[w]<min ){
				k=w;
				min=(*D)[w];
			}
		}
		final[k]=1;//将目前找到的最近的顶点置1
		
		//修改当前最短路径及距离
		for(w=0;w<G.numVertexes;w++){
			//如果经过v顶点的路径比现在这条路径的长度短的话，更新
			if(!final[w] && (min+G.ark[k][w] < (*D)[w])){
				(*D)[w] = min+G.arc[k][w];//修改当前路径长度
				(*P)[w]=k;//存放前驱结点
			}
		}
	}
}


//Floyd算法
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX]

//P[i][j]数组：从点i到j最短路，i的后继

void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D){
	int v, w, k;
	//初始化D,P
	for(v=0; w < G.numVertexes; v++){
		for(w=0; w < G.numVertexes; w++){
			(*D)[v][w] = G.matrix[v][w];
			(*P)[v][w] = w;
		}
	}
	
	//优美的弗洛伊德算法
	for(k=0; k < G.numVertexes; k++){
		for(v=0; v < G.numVertexes; v++){
			for(w=0; w < G.numVertexes; w++){
				if((*D)[v][w] > (*D)[v][k] + (*D[k][w])){
					(*D)[v][w]=(*D)[v][k] + (*D)[k][w];
					(*P)[v][w]=(*P)[v][k];
				}
			}
		}
	}
}