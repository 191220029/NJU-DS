//树


/********************************************************/
//树的双亲表示法

#define MAX_TREE_SIZE 100
typedef int ElemType;

typedef struct PTNode{
	ElemType data;// 结点数据
	int parent;	  //双亲位置 用父节点在Ptree中的nodes索引表示，根节点为-1
}

typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r;	//根的位置
	int n;	//结点数目
}Ptree;

/********************************************************/
//树的孩子表示法

//树的双亲孩子表示法
	//孩子结点
typedef struct CTNode{
	int child;//孩子结点的下标
	struct CNnode *next;//指向下一个孩子结点的指针

}*ChildPtr;

	//表头结构
typedef struct{
	ElemType data;//存放在树中结点的数据
	int parent;//存放双亲的下标
	ChildPtr firstchild;//指向第一个孩子的指针
}CTBox;

	//树结构
typedef struct{
	CTBox nodes[MAX_TREE_SIZE];//结点数据
}


/********************************************************/



//二叉链表(树)
typedef char ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


//创建二叉树，约定用户遵照前序遍历的方式输入数据
void CreateBiTree(BiTree *T){
	char c;
	scanf("%c",&c);
	if(' '==c){
		*T=NULL;
	}
	else{
		*T = (BiTNode *)malloc(sizeof(BiTNode);
		(*T)->data=c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

/********************************************************/
//二叉树的遍历

void visit(char c, int level){	//访问二叉树结点的具体操作
	printf("%c 位于第 %d 层\n",c, level);
}

//前序遍历
void PreOrderTraverse(BiTree T, int level);{
	if(T){
		visit(T->data,level);
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}

//中序、后序遍历改变上面的if中三个语句的顺序即可

/********************************************************/
//线索二叉树

//线索存储标志位：
//Link{0}:表示*lchild,*rchild是指向左右孩子指针
//Thread{1}:表示*lchild,*rchild指向前驱后继的线索
typedef enum{Link, Thread} PointerTag;
typedef struct BiThrNode{
	ElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode, *BiThrTree;

//全局变量，始终指向刚刚访问过的结点
BiThrTree pre;


//创建线索二叉树，约定用户遵照前序遍历的方式输入数据
void CreateBiThrTree(){
	char c;
	scanf("%c",&c);
	if(' '==c){
		*T=NULL;
	}
	else{
		*T= (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data=c;
		(*T)->ltag=Link;
		(*T)->rtag=Link;
		
		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

//中序遍历线索化
InThreading(BiThrTree){
	if(T){
		InThreading(T->lchild);//递归左孩子线索化
		
		if(!T->lchild){//如果该节点没有左孩子，设置ltag为Thread，并把lchild指向刚刚访问的结点
			T->ltag=Thread;
			T->lchild=pre;
		}
		
		if(!pre->rchild){
			pre->rtag=Thread;
			pre->rchild=T;
		}
		
		pre = T;
		
		InThreading(T->rchild);//递归右孩子线索化
	}
}

void InOrderThreading(BiThrTree *p BiThrTree T){
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag=Link;
	(*p)->rtag=Thread;
	(*p)->rchild=*p;
	if(!T){
		(*p)->lchild=*p;
	}
	else{
		(*p)->lchild=T;
		pre=*p;
		InThreading(T);
		pre->rchild =*p;
		pre->rtag=Thread;
		(*p)->rchild=pre;
	}
}

void visit(char c){
	printf("%c", c);
}


//中序遍历线索二叉树，无递归
void InOrderTraverse(BiThrTree T){
	BiThrTree p;
	p = T->lchild;
	while(p!=T){
		while(p->ltag==Link){
			p=p->lchild;
		}
		visit(p->data);
		
		while(p->rtag==Thread && p->rchild !=T){
			p=p->rchild;
			visit(p->data);
		}
		p=p->rchild;
	}
}





/********************************************************/
//huffman编码（树）

#define TYPE htNode *
#define MAX_SZ 256

typedef struct _htNode{
	char symbol;
	struct _htNode *left, *right;
}htNode;

typedef struct _htTree{
	htNode *root;
}htTree;

typedef struct _hlNode{
	char symbol;	//
	char *code;		//存放编码
	struct _hlNode *next;
}hlNode;

typedef struct _hlTable{
	hlNode *first;
	hlNode *last;
}hlTable;

typedef struct _pQueueNode{
	TYPE val;
	unsigned int priority;//优先级
	struct _pQueueNode *next;
}pQueueNode;

typedef struct _pQueue{
	unsigned int size;//队列长度
	pQueueNode *first;//头指针指向队列头结点
}pQueue;

void initQueue(pQueue **queue){
	(*queue) = (pQueue *)malloc(sizeof(pQueue));
	(*queue)->first=NULL;
	(*queue)->size=0;
	return;
}

void addPQueue(pQueue **queue, TYPE val, unsigned int priority){
	if((*queue)->size == MAX_SZ){
		printf("\nQueue is full.\n");
		return;
	}
	
	pQueueNode *aux = (pQueueNode *)malloc(sizeof(pQueueNode));
	aux->priority = priority;
	aux->val = val
	
	if((*queue)->size == 0 || (*queue)->first == NULL){
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}
	else{
		if(priority<=(*queue)->first->priority){
			aux->next = (*queue)->first;
			(*queue)->first=aux;
			(*queue)->size++;
			return;
		}
		else{
			pQueueNode *iterator = (*queue)->first;
			while(iterator->next!=NULL){
				if(priority<=iterator->next->priority){
					aux->next=iterator->next;
					iterator->next=aux;
					(*queue)->size++;
					return;
				}
				iterator = iterator->next;
			}
			
			if(iterator->next=NULL){
				aux->next=NULL;
				iterator->next=aux;
				(*queue)->size++;
				return;
			}
		}
	}

}

TYPE getPQueue(pQueue **queue){	//取出头结点（排序后头结点权值最小）
	TYPE returValue;
	
	if((*queue)->size > 0){
		returValue = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		(*queue)->size--;
	}
	else{
		printf("\nQueue is empty.\n");
	}
	return returValue;
}

void traverseTree(htNode* treeNode,hlTable **table, int k, char code[256]){
	
	//叶子节点处理
	if(treeNode->left==NULL && treeNode->right == NULL){
		code[k] = '\0';
		hlNode *aux = (hlNode*)malloc(sizeof(hlNode));
		aux->code = (char*)malloc(sizeof(char)*(strlen(code)+1));
		strcpy(aux->code, code);
		aux->symbol = treeNode->symbol;
		aux->next=NULL;
		
		if((*table)->first==NULL){
			(*table)->first=aux;
			(*table)->last=aux;
		}
		else{
			(*table)->last->next=aux;
			(*table)->last = aux;
		}
	}
	
	if(treeNode->left != NULL){ //往左走码后面连0
		code[k]='0';
		traverseTree(treeNode->left, table,k+1, code);
	}
	
	if(treeNode->right != NULL){ //往右走码后面连1
		code[k]='1';
		traverseTree(treeNode->right, table, k+1, code);
	}
	
}

//创建codeTree->创建codeTable->编码->解码
htTree* buildTree(char* inputString){
	int *probability = (int *)malloc(sizeof(int)*256);
	
	//初始化
	for(int i=0;i<256;i++){
		probability[i]=0;
	}
	
	//统计待编码字符串各个字符出现的次数
	for(int i=0; inputString[i]!='\0';i++){
		probability[(unsigned char)inputString[i]]++;
	}
	
	//pQueue队列的头指针
	pQueue *huffmanQueue;
	initQueue(&huffmanQueue);
	//填充队列
	for(int i=0;i<256;i++){
		if(probability[i]!=0){
			htNode *aux = (htNode *)malloc(sizeof(htNode));
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)i;
			
			addPQueue(&huffmanQueue, aux, probability[i]);
		}
	}
	
	free(probability);
	
	//生成huffman树
	while(huffmanQueue->size!=1){
		int priority = huffmanQueue->first->priority;
		priority+=huffmanQueue->first->next->priority;
		
		htNode *left = getQueue(&huffmanQueue);
		htNode *right = getQueue(&huffmanQueue);
		
		htNode *newNode = (htNode *)malloc(sizeof(htNode));
		newNode->left = left;
		newNode->right = right;
		
		addPQueue(&huffmanQueue, newNode, priority);
		
		htTree *tree = (htTree *)malloc(sizeof(htTree));
		
		tree->root = getPQueue(&huffmanQueue);
		
		return tree;
	}
}

hlTable* buildTable(htTree* huffmanTree){
	hlTable* table = (hlTable*)malloc(sizeof(hlTable));
	table->first = NULL;
	table->last = NULL;
	
	char code[256];
	int k=0;
	
	traverseTree(huffmanTree->root, &table, k, code);
	return table;
}

void encode(hlTable *table, char* stringToEncode){
	hlNode *traversal;
	
	printf("Encoding......\n\nInput string: \n%s\n\nEncoded string: \n", stringToEncode);
	
	for(int i=0; stringToEncode[i]!='\0'; i++){
		traversal = table->first;
		while(traversal->symbol != stringToEncode[i])
			traversal = traversal->next;
		printf("%s", traversal->code);
	}
}

void decode(htTree *tree, char *stringToDecode){
	htNode *traversal = tree->root;
	
	printf("\n\mDecoding......\n\nInput string: \n%s\n\nDecode string: \n", stringToDecode)
	
	//待完善...
}



/********************************************************/
//图

