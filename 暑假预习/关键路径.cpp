//关键路径
//AOE网：在一个表示工程的带权有向图中，顶点表示时间，有向边表示活动，边是那个的权值表示活动持续时间。
//AOE网中没有入边的顶点称为始点或源点，没有出边的顶点称为终点或汇点。



//边表结点声明
typedef struct edge{
	unsigned int begin;//边的起点
	unsigned int end;//边的终点
	unsigned int weight;//权重
}

typedef struct EdgeNode{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;

//顶点表结点声明
typedef struct VertexNode{
	int in;//入度
	int data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjlList;

//拓扑排序算法
//若GL无回路，则输出拓扑排序序列并返回OK，否则返回ERROR

int *etv, *ltv;
int *stack2; //存储拓扑排序的栈
int top2;	//用于stack2的栈顶指针

Status TopologicalSort(GraphAdjList GL){
	EdgeNode *e;
	int i, k, gettop;
	int top=0;//栈指针下标索引
	int count = 0;//统计输出顶点的个数
	int *stack;//存储入度为0的顶点
	
	stack = (int*)malloc(GL->numVertexes * sizeof(int));
	
	for(i=0;i<GL->numVertexes;i++){
		if(0==GL->adjList[i].in){
			stack[++top]=1;//将入度为0的顶点下标入栈
		}
	}
	
	//初始化etv都为0
	top2=0;
	etv=(int*)malloc(GL->numVertexes*sizeof(int));
	for(i=0;i<GL->numVertexes;i++){
		etv[i]=0;
	}
	stack2=(int*)malloc(GL->numVertexes*sizeof(int));
	
	while(0!=top){
		gettop=stack[top--];//出栈
		stack2[++top2]=gettop;//保存拓扑排序
		count++;
		
		for(e=GL->adjList[gettop].firstedge; e; e=e->next){
			k=e->adjvex;
			if(!(--GL->adjList[k].in){
				stack[++top]=k;
			}
			if((etv[gettop]+e->weight)>etv[k]){
				etv[k]=etv[gettop]+e->weight;
			}
		}
	}
	
	if(count<GL->numVertexes){//如果count小于顶点数，说明存在环
		return ERROR;
	}
	else{
		return OK;
	}
}

//求关键路径，GL为有向图，输出GL的各项关键活动
void CriticalPath(GraphAdjList GL){
	EdgeNode *e;
	int i, gettop, k, j;
	int ete, lte;
	
	//调用改进后的拓扑排序，求出etv和stack2的值
	TopologicalSort(GL);
	
	//初始化ltv都为汇点时间
	ltv=(int*)malloc(GL->numVertexes*sizeof(int));
	for(i=0;i<GL->numVertexes;i++){
		ltv[i]=etv[GL->numVertexes-1]);
	}
	
	//从汇点倒过来逐个计算ltv
	while(0!=top2){
		gettop=stack[top2--];//注意：第一个出栈点事汇点
		for(e=GL->adjList[gettop].firstedge;e;e=e->next){
			k=e->adjvex;
			if((ltv[k] - e->weight)<ltv[gettop]){
				ltv[gettop]=ltv[k] - e->weight;
			}
		}
	}
	
	//通过etv和ltv求ete和lte
	for(j=0;j<GL->numVertexes;j++){
		for(e=GL->adjList[j].firstedge;e;e->next){
			k=e->adjvex;
			ete=etv[j];
			lte=ltv[k]-e->weight;
			
			if(ete==lte){//关键路径打印：
				printf("<v%d, v%d> length: %d , ",GL->adjList[j].data, GL->adjList[k].data, e->weight);
			}
		}
	}
}