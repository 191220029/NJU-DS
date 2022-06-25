//查找

//静态查找：

//顺序查找
//a为要查找的数组，n为要查找的数组的长度,key为要查找的关键字
int Sq_Search(int *a, int n, int key){
	int i;
	for(i=1;i<=n;i++){
		if(a[i]==key){
			return i;
		}
	}
	return 0;
	
	//优化：效率提高一倍
	//设置哨兵
	a[0]=key;
	while(a[i]!=key){
		i--;
	}
	return i;
}

//插值查找
int bin_search(int str[], int n, int key){
	int low, high, mid;
	
	low=0;
	high=n-1;
	
	while(low<=high){
		mid=low+((key-a[low])/(a[high]-a[low]))*(high-low);//插值查找和二分查找的唯一不同点
		
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


//黄金比例
//斐波那契查找（查找斐波那契数），原理类似于折半查找

//线性索引查找

/***********************************************************************/
//动态查找

//二叉排序树
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//递归查找二叉树T中是否存在key
//指针f指向T的双亲，其初始值调用值为NULL
//若查找成功，指针p指向该数据元素结点，并返回TRUE
//否则指针p指向查找路径上访问的最后一个结点，并返回FALSE
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p){
	if(!T){//查找不成功
		*p=f;
		return FALSE;
	}
	else if(key == T->data){//查找成功
		*p=T;
		return TRUE;
	}
	else if(key < T->data){
		return SearchBST(T->lchild, key, T, p);//忘左子树继续查找
	}
	else{
		return SearchBST(T->rchild, key, T, p);//忘左子树继续查找
	}
}

//插入即在查找的最后一步添加结点

//删除结点
Status DeleteBST(BiTree *T, int key){
	if(!T){//找不到该元素
		return FALSE;
	}
	else{
		if(key==(*T->data){
			return Delete(T);
		}
		else if(key < T->data){
			return DeleteBST(&(*T)->lchild, key);//忘左子树继续查找
		}
		else{
			return SearchBST(&(*T)->rchild, key);//忘左子树继续查找
		}
	}
}

Status Delete(BiTree *p){//有bug
	BiTree q, s;//q:存储双亲结点 s:每次迭代用到的结点
	
	if((*p)->rchild == NULL){//右子树为空，把左子树接过去
		q=*p;
		//q->left = *p->left;
		*p=(*p)->lchild;
		free(q);
	}
	else if((*p)->lchild == NULL){//左子树为空，把右子树接过去
		q=*p;
		*p=(*p)->rchild;
		free(q);
	}
	else{//左子树、右子树均不空 这里选取直接前驱介入
		q=*p;
		s=(*p)->lchild;
		while(s->rchild){//找到p的左子树的最右子树的非叶节点，将将数据替换过去
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
//平衡二叉排序树
#define LH 1//表示左子树高了1
#define EH 0//表示左右子树等高
#define RH -1//表示右子树高了1
typedef struct BiTNode{
	int data;
	int bf;//平衡因子
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
	
	switch(L->bf){//T的左子树的根的平衡因子
		case LH://做右旋处理
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		case RH://新插入的结点在T左孩子的右子树上
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


//RightBalance 和 LeftBalance 类似，将对应的左右对象互换即可

int InsertAVL(BiTree *T, int e, int *taller){//taller:插入该结点后树的高度是否有变化
	if(!*T){//当树为空
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else{
		if(e == (*T)->data){//如果树中已经有相同data的结点，那么无法插入e
			*taller = FALSE;
			return FALSE;
		}
		if(e<(*T)->data){//向左子树插入
			if(!InsertAVL(&(*T)->lchild, e, taller)){
				return FALSE;
			}
			if(*taller){//如果插入成功后树的高度有变化
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
		else{//向右子树插入
			if(!InsertAVL(&(*T)->rchild, e, taller)){
				return FALSE;
			}
			if(*taller){//如果插入成功后树的高度有变化
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






