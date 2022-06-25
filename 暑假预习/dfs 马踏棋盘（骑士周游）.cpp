//��ʿ��������
#define X 8
#define Y 8


int chess[X][Y];

//�ҵ�����(x,y)λ�õ���һ������λ��
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

//��ӡ����
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

//������ȱ�������
//��һ�ε��õ�(x,y)��ʾ��ʼλ��
//tag�Ǳ�Ǳ�����ÿ��һ����tag+1
int TravelChessBoard(int x, int y, int tag){
	chess[x][y]=tag;
	if(X*Y==tag){//�߱������и��ӣ���ӡ����
		print();
		return 1;
	}
	
	int x1=x, y1=y, flag=0, count = 0;
	flag = nextxy(&x1, &x2, count);
	while(0==flag && count < 7){
		count++;
		flag = nextxy(&x1, &x2, count);
	}
	
	//�ҵ������һ������(x1,y1)������ҵ�flag=1,����Ϊ0
	while(flag){
		if(TravelChessBoard(x1, y1, tag+1)){
			return 1;
		}
		//�ҵ������һ����������...
		x1 = x;
		y1 = y;
		count++;
		
		flag = nextxy(&x, &y, count);
		
	}
	
	if(0==flag){
		chess[x][y]=0;
	}
	
	return 0;
	//�����һ��ĵ��ã����ݹ����ʱ������0����̤����ʧ�ܣ��Ҳ����������и��ӵķ���
	
}