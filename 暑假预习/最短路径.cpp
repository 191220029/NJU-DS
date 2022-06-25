//���·��
//Dijkstra�㷨
typedef int Patharc[MAXVEX];	//�洢���·���±������
typedef int ShortPathTable[MAXVEX]//�洢���������·����Ȩֵ��

void ShortestPath_Dijkstra(MGraph G, int V0, Patharc *P, ShortPathTable *D){
	int v, w, k, min;
	int final[MAXVEX];	//final[w]=1 ��ʾ�Ѿ���õ�v0��vw�����·��
	
	//��ʼ��
	for(v=0;v<G.numVertexes; v++){
		final[v] = 0; //ȫ�������ʼ��Ϊδ�ҵ����·
		(*D)[V]=G.arc[V0][v]//����v0�������ߵĶ������Ȩֵ
		(*P)[V] = 0;//��ʼ��·������PΪ0
	}
	
	(*D)[V0] = 0;//v0��v0��·��Ϊ0
	final[V0]=1;//v0��v0����Ҫ·��
	
	//ÿ��ѭ�����v0��ĳ������v�����·��
	for(v=0;v<G.numVertexes;v++){
		min = INFINITY;
		for(w=0;w<G.numVertexes;w++){
			if(!final[w] && (*D)[w]<min ){
				k=w;
				min=(*D)[w];
			}
		}
		final[k]=1;//��Ŀǰ�ҵ�������Ķ�����1
		
		//�޸ĵ�ǰ���·��������
		for(w=0;w<G.numVertexes;w++){
			//�������v�����·������������·���ĳ��ȶ̵Ļ�������
			if(!final[w] && (min+G.ark[k][w] < (*D)[w])){
				(*D)[w] = min+G.arc[k][w];//�޸ĵ�ǰ·������
				(*P)[w]=k;//���ǰ�����
			}
		}
	}
}


//Floyd�㷨
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX]

//P[i][j]���飺�ӵ�i��j���·��i�ĺ��

void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D){
	int v, w, k;
	//��ʼ��D,P
	for(v=0; w < G.numVertexes; v++){
		for(w=0; w < G.numVertexes; w++){
			(*D)[v][w] = G.matrix[v][w];
			(*P)[v][w] = w;
		}
	}
	
	//�����ĸ��������㷨
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