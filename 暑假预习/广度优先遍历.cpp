//������ȱ���
//ͼ���ڽӾ����BFS
void BFSTraverse(MGraph G){
	int i,j;
	Queue Q;
	
	for(int i=0; i<G.numVertexse; i++){//����ͼG�еĶ���
		visited[i]=false;
	}
	
	initQueue(&Q);
	
	for(=0; i<G.numVertexse; i++){
		if(!visited[i]){
			printf("%c", G.vex[i]);
			visited[i]=true;
			EnQueue(&Q, i);
			
			while(!QueueEmpty(Q)){
				DeQueue(&Q, &i);
				for(j=0;j<G.numVertexse;j++){
					if(G.art[i][j]==1 && !visited[j]){//����i,j֮���б�
						printf("%c", G.vex[j]);
						visited[j]=true;
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}