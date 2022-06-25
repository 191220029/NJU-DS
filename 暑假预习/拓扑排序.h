//��������
/*
�������У�
	��G=(V,E)��һ������n�����������ͼ��V�еĶ�����������Ӷ���Vi��Vj��һ��·����
�򶥵������ж���Vi������Vj֮ǰ�������ǳ������Ķ�������Ϊһ���������С�
��������
	��һ������ͼ�����������еĹ���
	
�����ڽӱ�ʵ��
*/

//�߱�������
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

//��������
//��GL�޻�·������������������в�����OK,���򷵻�ERROR
Status TopologicalSort(GraphAdjlList GL){
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;//����ջָ���±�����
	int count = 0;//����ͳ���������ĸ���
	int *stack;//���ڴ洢���Ϊ0�Ķ���
	
	stack = (int *)malloc(GL->numVertexes*sizeof(int));
	
	for(i=0;i<GL->numVertexes;i++){
		if(0==GL->adjList[i].in){//����Ϊ0�Ķ�����ջ
			stack[++top]=i;
		}
	}
	
	while(0!=top){
		gettop = stack[top--];//��ջ
		printf("%d -> ",GL->adjList[gettop].data);
		count++;
		
		for(e=GL->adjList[gettop].firstedge;e;e=e->next){
			k=e->adjvex;
			//ע�⣬�±ߵ�if�����Ƿ������������Ҫ��
			//��k�Ŷ����ڽӵ�����-1����Ϊ����ǰ���Ѿ�Ц��
			//�����ж�-1��������Ƿ�Ϊ0�����Ϊ0Ҳ��ջ
			if(!(--GL->adjList[k].in)){
				stack[++top]=k;
			}
		}
	}
	
	if(count < GL->numVertexes){//���countС�ڶ�������˵�����ڻ�
		return ERROR;
	}
	else{
		return OK;
	}
}