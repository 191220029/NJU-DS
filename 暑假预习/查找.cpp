//����

//��̬���ң�

//˳�����
//aΪҪ���ҵ����飬nΪҪ���ҵ�����ĳ���,keyΪҪ���ҵĹؼ���
int Sq_Search(int *a, int n, int key){
	int i;
	for(i=1;i<=n;i++){
		if(a[i]==key){
			return i;
		}
	}
	return 0;
	
	//�Ż���Ч�����һ��
	//�����ڱ�
	a[0]=key;
	while(a[i]!=key){
		i--;
	}
	return i;
}

//��ֵ����
int bin_search(int str[], int n, int key){
	int low, high, mid;
	
	low=0;
	high=n-1;
	
	while(low<=high){
		mid=low+((key-a[low])/(a[high]-a[low]))*(high-low);//��ֵ���ҺͶ��ֲ��ҵ�Ψһ��ͬ��
		
		if(str[mid]==key){
			return mid;
		}
		if(str[mid]<key){
			low=mid+1;
		}
		if(str[mid]>key){
			high=mid-1;
		}
	}
	
	return -1;
}


//�ƽ����
//쳲��������ң�����쳲�����������ԭ���������۰����

//������������

/***********************************************************************/
//��̬����

//����������
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//�ݹ���Ҷ�����T���Ƿ����key
//ָ��fָ��T��˫�ף����ʼֵ����ֵΪNULL
//�����ҳɹ���ָ��pָ�������Ԫ�ؽ�㣬������TRUE
//����ָ��pָ�����·���Ϸ��ʵ����һ����㣬������FALSE
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p){
	if(!T){//���Ҳ��ɹ�
		*p=f;
		return FALSE;
	}
	else if(key == T->data){//���ҳɹ�
		*p=T;
		return TRUE;
	}
	else if(key < T->data){
		return SearchBST(T->lchild, key, T, p);//����������������
	}
	else{
		return SearchBST(T->rchild, key, T, p);//����������������
	}
}

//���뼴�ڲ��ҵ����һ����ӽ��

//ɾ�����
Status DeleteBST(BiTree *T, int key){
	if(!T){//�Ҳ�����Ԫ��
		return FALSE;
	}
	else{
		if(key==(*T->data){
			return Delete(T);
		}
		else if(key < T->data){
			return DeleteBST(&(*T)->lchild, key);//����������������
		}
		else{
			return SearchBST(&(*T)->rchild, key);//����������������
		}
	}
}

Status Delete(BiTree *p){//��bug
	BiTree q, s;//q:�洢˫�׽�� s:ÿ�ε����õ��Ľ��
	
	if((*p)->rchild == NULL){//������Ϊ�գ����������ӹ�ȥ
		q=*p;
		//q->left = *p->left;
		*p=(*p)->lchild;
		free(q);
	}
	else if((*p)->lchild == NULL){//������Ϊ�գ����������ӹ�ȥ
		q=*p;
		*p=(*p)->rchild;
		free(q);
	}
	else{//�������������������� ����ѡȡֱ��ǰ������
		q=*p;
		s=(*p)->lchild;
		while(s->rchild){//�ҵ�p�������������������ķ�Ҷ�ڵ㣬���������滻��ȥ
			q=s;
			s=s->rchild;
		}
		
		(*p)->data = s->data;
		if(q!=p){
			q->rchild = s->lchild;
		}
		else{
			q->lchild = s->lchild;
		}
		free(s);
		
	}
	return TRUE;
}


/***********************************************************************/
//ƽ�����������
#define LH 1//��ʾ����������1
#define EH 0//��ʾ���������ȸ�
#define RH -1//��ʾ����������1
typedef struct BiTNode{
	int data;
	int bf;//ƽ������
	struct BiTNode* lchild, *rchild;
}BiTNode, *BiTree;

void L_Rotate(BiTree *p){
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
}

void R_Rotate(BiTree *p){
	BiTree L;
	L = (*p)->rchild;
	(*p)->rchild = L->lchild;
	L->lchild = (*p);
	*p = L;
}


void LeftBalance(BiTree *T){
	BiTree L, Lr;
	L = (*T)->lchild;
	
	switch(L->bf){//T���������ĸ���ƽ������
		case LH://����������
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		case RH://�²���Ľ����T���ӵ���������
			Lr = L->rchild
			switch(Lr->bf){
				case LH:
					(*T)->bf = RH;
					L->bf = EH;
					break;
				case EH:
					(*T)->bf = L->bf = EH;
					break;
				case RH:
					(*T)->bf = RH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
			
	}
}


//RightBalance �� LeftBalance ���ƣ�����Ӧ�����Ҷ��󻥻�����

int InsertAVL(BiTree *T, int e, int *taller){//taller:����ý������ĸ߶��Ƿ��б仯
	if(!*T){//����Ϊ��
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else{
		if(e == (*T)->data){//��������Ѿ�����ͬdata�Ľ�㣬��ô�޷�����e
			*taller = FALSE;
			return FALSE;
		}
		if(e<(*T)->data){//������������
			if(!InsertAVL(&(*T)->lchild, e, taller)){
				return FALSE;
			}
			if(*taller){//�������ɹ������ĸ߶��б仯
				switch((*T)->bf){
					case LH:
						LeftBalance(T);
						*taller=FALSE;
						break;
					case EH:
						(*T)->bf = LH;
						*taller = TRUE;
						break;
					case RH:
						(*T)->bf = EH;
						*taller = FALSE;
						break;
				}
			}
		}
		else{//������������
			if(!InsertAVL(&(*T)->rchild, e, taller)){
				return FALSE;
			}
			if(*taller){//�������ɹ������ĸ߶��б仯
				switch((*T)->bf){
					case LH:
						(*T)->bf = EH;
						*taller=FALSE;
						break;
					case EH:
						(*T)->bf = RH;
						*taller = TRUE;
						break;
					case RH:
						RightBalance(T);
						*taller = FALSE;
						break;
				}
			}
		}
	}
	
}






