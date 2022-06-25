//�ؼ�·��
//AOE������һ����ʾ���̵Ĵ�Ȩ����ͼ�У������ʾʱ�䣬����߱�ʾ��������Ǹ���Ȩֵ��ʾ�����ʱ�䡣
//AOE����û����ߵĶ����Ϊʼ���Դ�㣬û�г��ߵĶ����Ϊ�յ���㡣



//�߱�������
typedef struct edge{
	unsigned int begin;//�ߵ����
	unsigned int end;//�ߵ��յ�
	unsigned int weight;//Ȩ��
}

typedef struct EdgeNode{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;

//�����������
typedef struct VertexNode{
	int in;//���
	int data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjlList;

//���������㷨
//��GL�޻�·������������������в�����OK�����򷵻�ERROR

int *etv, *ltv;
int *stack2; //�洢���������ջ
int top2;	//����stack2��ջ��ָ��

Status TopologicalSort(GraphAdjList GL){
	EdgeNode *e;
	int i, k, gettop;
	int top=0;//ջָ���±�����
	int count = 0;//ͳ���������ĸ���
	int *stack;//�洢���Ϊ0�Ķ���
	
	stack = (int*)malloc(GL->numVertexes * sizeof(int));
	
	for(i=0;i<GL->numVertexes;i++){
		if(0==GL->adjList[i].in){
			stack[++top]=1;//�����Ϊ0�Ķ����±���ջ
		}
	}
	
	//��ʼ��etv��Ϊ0
	top2=0;
	etv=(int*)malloc(GL->numVertexes*sizeof(int));
	for(i=0;i<GL->numVertexes;i++){
		etv[i]=0;
	}
	stack2=(int*)malloc(GL->numVertexes*sizeof(int));
	
	while(0!=top){
		gettop=stack[top--];//��ջ
		stack2[++top2]=gettop;//������������
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
	
	if(count<GL->numVertexes){//���countС�ڶ�������˵�����ڻ�
		return ERROR;
	}
	else{
		return OK;
	}
}

//��ؼ�·����GLΪ����ͼ�����GL�ĸ���ؼ��
void CriticalPath(GraphAdjList GL){
	EdgeNode *e;
	int i, gettop, k, j;
	int ete, lte;
	
	//���øĽ���������������etv��stack2��ֵ
	TopologicalSort(GL);
	
	//��ʼ��ltv��Ϊ���ʱ��
	ltv=(int*)malloc(GL->numVertexes*sizeof(int));
	for(i=0;i<GL->numVertexes;i++){
		ltv[i]=etv[GL->numVertexes-1]);
	}
	
	//�ӻ�㵹�����������ltv
	while(0!=top2){
		gettop=stack[top2--];//ע�⣺��һ����ջ���»��
		for(e=GL->adjList[gettop].firstedge;e;e=e->next){
			k=e->adjvex;
			if((ltv[k] - e->weight)<ltv[gettop]){
				ltv[gettop]=ltv[k] - e->weight;
			}
		}
	}
	
	//ͨ��etv��ltv��ete��lte
	for(j=0;j<GL->numVertexes;j++){
		for(e=GL->adjList[j].firstedge;e;e->next){
			k=e->adjvex;
			ete=etv[j];
			lte=ltv[k]-e->weight;
			
			if(ete==lte){//�ؼ�·����ӡ��
				printf("<v%d, v%d> length: %d , ",GL->adjList[j].data, GL->adjList[k].data, e->weight);
			}
		}
	}
}