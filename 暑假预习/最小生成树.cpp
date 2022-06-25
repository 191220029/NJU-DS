//��С������
//Prim�㷨������С������
void MiniSpanTree_Prim(MGraph G){
	int min, i, j, k;
	int adjvex[MAXVEX];	//�������ڶ����±�
	int lowcost[MAXVEX]; //�������ڶ����ߵ�Ȩֵ
	
	
	lowcost[0]=0;//v0��Ϊ��С�������ĸ���ʼ������ȨֵΪ0
	adjvex[0]=0;//v0��һ������
	//��ʼ��
	for(i=0;i<G.numVertexes;i++){
		lowcost[i]=G.arc[0][i];//���ڽӾ����0������Ȩֵ�ȼ�������
		adjvex[i]=0;//��ʼ��ȫ����Ϊv0�±�
	}
	
	//������С������
	for(i=1;i<G.numVertexes;i++){
		min = INFINITY; //��ʼ����СȨֵΪ65535�Ȳ����ܵ���ֵ
		j=1;k=0;
		
		//����ȫ������
		while(j<G.numVertexes){
			//�ҳ�lowcost�������Ѵ洢����СȨֵ
			if(lowcost[j]!=0&&lowcost[j]<min){
				min=lowcost[j];
				k=j;//�����ֵ���СȨֵ���±����k���Դ�ʹ��
			}
			j++;
		}
		//��ӡ��ǰ������Ȩֵ��С�ı�
		printf("(%d,%d)",adjvex[k],k);
		lowcost[k]=0;//����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ�������񣬿�ʼ��һ������ı���
		
		//�ڽӾ���k���������ȫ������
		for(j=1;j<G.numVertexes;j++){
			if(lowcost[j]!=0 &&G.arc[k][j] < lowcost[j]){
				lowcost[j]=G.arc[k][j];
				adjvex[j]=k;
			}
		}
	}
}


//Kruskal�㷨
typedef struct edge{
	unsigned int begin;//�ߵ����
	unsigned int end;//�ߵ��յ�
	unsigned int weight;//Ȩ��
}
int Find(int *parent, int f){
	while(parent[f] > 0){
		f=parent[f];
	}
	return f;
}
void MiniSpanTree_Kruskal(MGraph G){
	int i, n, m;
	Edge edges[MAGEDGE]//����߼�����
	int parent[MAXVEX]//����parent���������жϱ�����Ƿ��γɻ�·
	
	for(i=0; i<G.numEdges; i++){
		n = Find(parent, edges[i].begin); //�ҵ���i���ߵ���㶥��
		m = Find(parent, edges[i].end);   //�ҵ���i���ߵ���ֹ����
		
		if(n!=m){//���n=m�����γɻ�·��������
			parent[n] = m; //���˱ߵĽ�β��������±�Ϊ����parent�����У���ʾ�˶����Ѿ���������������
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}