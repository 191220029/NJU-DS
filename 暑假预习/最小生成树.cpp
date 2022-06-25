//最小生成树
//Prim算法生成最小生成树
void MiniSpanTree_Prim(MGraph G){
	int min, i, j, k;
	int adjvex[MAXVEX];	//保存相邻顶点下标
	int lowcost[MAXVEX]; //保存相邻顶点间边的权值
	
	
	lowcost[0]=0;//v0作为最小生成树的根开始遍历，权值为0
	adjvex[0]=0;//v0第一个加入
	//初始化
	for(i=0;i<G.numVertexes;i++){
		lowcost[i]=G.arc[0][i];//将邻接矩阵第0行所有权值先加入数组
		adjvex[i]=0;//初始化全部先为v0下标
	}
	
	//构造最小生成树
	for(i=1;i<G.numVertexes;i++){
		min = INFINITY; //初始化最小权值为65535等不可能的数值
		j=1;k=0;
		
		//遍历全部顶点
		while(j<G.numVertexes){
			//找出lowcost数组中已存储的最小权值
			if(lowcost[j]!=0&&lowcost[j]<min){
				min=lowcost[j];
				k=j;//将发现的最小权值的下标存入k，以待使用
			}
			j++;
		}
		//打印当前顶点中权值最小的边
		printf("(%d,%d)",adjvex[k],k);
		lowcost[k]=0;//将当前顶点的权值设置为0，表示此顶点已经完成任务，开始下一个顶点的遍历
		
		//邻接矩阵k行逐个遍历全部顶点
		for(j=1;j<G.numVertexes;j++){
			if(lowcost[j]!=0 &&G.arc[k][j] < lowcost[j]){
				lowcost[j]=G.arc[k][j];
				adjvex[j]=k;
			}
		}
	}
}


//Kruskal算法
typedef struct edge{
	unsigned int begin;//边的起点
	unsigned int end;//边的终点
	unsigned int weight;//权重
}
int Find(int *parent, int f){
	while(parent[f] > 0){
		f=parent[f];
	}
	return f;
}
void MiniSpanTree_Kruskal(MGraph G){
	int i, n, m;
	Edge edges[MAGEDGE]//定义边集数组
	int parent[MAXVEX]//定义parent数组用来判断边与边是否形成环路
	
	for(i=0; i<G.numEdges; i++){
		n = Find(parent, edges[i].begin); //找到第i条边的起点顶点
		m = Find(parent, edges[i].end);   //找到第i条边的终止顶点
		
		if(n!=m){//如果n=m，则形成环路，不满足
			parent[n] = m; //将此边的结尾顶点放入下标为起点的parent数组中，表示此顶点已经在生成树集合中
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}