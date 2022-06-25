//骑士周游问题
#define X 8
#define Y 8


int chess[X][Y];

//找到基于(x,y)位置的下一个可走位置
int nextxy(int *x, int *y, int count){
	switch(count){
		case 0:
			if(*x+2<=X-1 && *y-1>=0 && chess[*x+2][*y-1]==0){
				*x+=2;
				*y-=1;
				return 1;
			}
			break;
		case 1:
			if(*x+2<=X-1 && *y+1<=Y-1 && chess[*x+2][*y+1]==0){
				*x+=2;
				*y+=1;
				return 1;
			}
			break;
		case 2:
			if(*x+1<=X-1 && *y-2>=0 && chess[*x+1][*y-2]==0){
				*x+=1;
				*y-=2;
				return 1;
			}
			break;
			
		case 3:
			if(*x+1<=X-1 && *y+2<=Y-1 && chess[*x+1][*y+2]==0){
				*x+=1;
				*y+=2;
				return 1;
			}
			break;
			
		case 4:
			if(*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1]==0){
				*x-=2;
				*y-=1;
				return 1;
			}
			break;
		case 5:
			if(*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1]==0){
				*x-=2;
				*y-=1;
				return 1;
			}
			break;
		
		case 6:
			if(*x-1>=0 && *y+1<=Y-1 && chess[*x-1][*y+1]==0){
				*x-=1;
				*y+=1;
				return 1;
			}
			break;
			
		case 7:
			if(*x-1>=0 && *y-2>=0 && chess[*x-1][*y+2]==0){
				*x-=1;
				*y+=2;
				return 1;
			}
			break;
		
	}
	return 0;
}

//打印棋盘
void print(){
	int i,j;
	for(i=0; i<X; i++){
		for(j=0; j<Y; j++){
			printf("%2d\t", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//深度优先遍历棋盘
//第一次调用的(x,y)表示起始位置
//tag是标记变量，每走一步，tag+1
int TravelChessBoard(int x, int y, int tag){
	chess[x][y]=tag;
	if(X*Y==tag){//走遍了所有格子，打印棋盘
		print();
		return 1;
	}
	
	int x1=x, y1=y, flag=0, count = 0;
	flag = nextxy(&x1, &x2, count);
	while(0==flag && count < 7){
		count++;
		flag = nextxy(&x1, &x2, count);
	}
	
	//找到马的下一个坐标(x1,y1)，如果找到flag=1,否则为0
	while(flag){
		if(TravelChessBoard(x1, y1, tag+1)){
			return 1;
		}
		//找到马的下一步可走坐标...
		x1 = x;
		y1 = y;
		count++;
		
		flag = nextxy(&x, &y, count);
		
	}
	
	if(0==flag){
		chess[x][y]=0;
	}
	
	return 0;
	//如果第一层的调用（即递归结束时）返回0，马踏棋盘失败，找不到遍历所有格子的方法
	
}