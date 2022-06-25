//广度优先遍历
//图的邻接矩阵的BFS
void BFSTraverse(MGraph G){
	int i,j;
	Queue Q;
	
	for(int i=0; i<G.numVertexse; i++){//遍历图G中的顶点
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
					if(G.art[i][j]==1 && !visited[j]){//顶点i,j之间有边
						printf("%c", G.vex[j]);
						visited[j]=true;
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}