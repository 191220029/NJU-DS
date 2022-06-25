//��


/********************************************************/
//����˫�ױ�ʾ��

#define MAX_TREE_SIZE 100
typedef int ElemType;

typedef struct PTNode{
	ElemType data;// �������
	int parent;	  //˫��λ�� �ø��ڵ���Ptree�е�nodes������ʾ�����ڵ�Ϊ-1
}

typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r;	//����λ��
	int n;	//�����Ŀ
}Ptree;

/********************************************************/
//���ĺ��ӱ�ʾ��

//����˫�׺��ӱ�ʾ��
	//���ӽ��
typedef struct CTNode{
	int child;//���ӽ����±�
	struct CNnode *next;//ָ����һ�����ӽ���ָ��

}*ChildPtr;

	//��ͷ�ṹ
typedef struct{
	ElemType data;//��������н�������
	int parent;//���˫�׵��±�
	ChildPtr firstchild;//ָ���һ�����ӵ�ָ��
}CTBox;

	//���ṹ
typedef struct{
	CTBox nodes[MAX_TREE_SIZE];//�������
}


/********************************************************/



//��������(��)
typedef char ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


//������������Լ���û�����ǰ������ķ�ʽ��������
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
//�������ı���

void visit(char c, int level){	//���ʶ��������ľ������
	printf("%c λ�ڵ� %d ��\n",c, level);
}

//ǰ�����
void PreOrderTraverse(BiTree T, int level);{
	if(T){
		visit(T->data,level);
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}

//���򡢺�������ı������if����������˳�򼴿�

/********************************************************/
//����������

//�����洢��־λ��
//Link{0}:��ʾ*lchild,*rchild��ָ�����Һ���ָ��
//Thread{1}:��ʾ*lchild,*rchildָ��ǰ����̵�����
typedef enum{Link, Thread} PointerTag;
typedef struct BiThrNode{
	ElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode, *BiThrTree;

//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
BiThrTree pre;


//����������������Լ���û�����ǰ������ķ�ʽ��������
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

//�������������
InThreading(BiThrTree){
	if(T){
		InThreading(T->lchild);//�ݹ�����������
		
		if(!T->lchild){//����ýڵ�û�����ӣ�����ltagΪThread������lchildָ��ոշ��ʵĽ��
			T->ltag=Thread;
			T->lchild=pre;
		}
		
		if(!pre->rchild){
			pre->rtag=Thread;
			pre->rchild=T;
		}
		
		pre = T;
		
		InThreading(T->rchild);//�ݹ��Һ���������
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


//��������������������޵ݹ�
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
//huffman���루����

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
	char *code;		//��ű���
	struct _hlNode *next;
}hlNode;

typedef struct _hlTable{
	hlNode *first;
	hlNode *last;
}hlTable;

typedef struct _pQueueNode{
	TYPE val;
	unsigned int priority;//���ȼ�
	struct _pQueueNode *next;
}pQueueNode;

typedef struct _pQueue{
	unsigned int size;//���г���
	pQueueNode *first;//ͷָ��ָ�����ͷ���
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

TYPE getPQueue(pQueue **queue){	//ȡ��ͷ��㣨�����ͷ���Ȩֵ��С��
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
	
	//Ҷ�ӽڵ㴦��
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
	
	if(treeNode->left != NULL){ //�������������0
		code[k]='0';
		traverseTree(treeNode->left, table,k+1, code);
	}
	
	if(treeNode->right != NULL){ //�������������1
		code[k]='1';
		traverseTree(treeNode->right, table, k+1, code);
	}
	
}

//����codeTree->����codeTable->����->����
htTree* buildTree(char* inputString){
	int *probability = (int *)malloc(sizeof(int)*256);
	
	//��ʼ��
	for(int i=0;i<256;i++){
		probability[i]=0;
	}
	
	//ͳ�ƴ������ַ��������ַ����ֵĴ���
	for(int i=0; inputString[i]!='\0';i++){
		probability[(unsigned char)inputString[i]]++;
	}
	
	//pQueue���е�ͷָ��
	pQueue *huffmanQueue;
	initQueue(&huffmanQueue);
	//������
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
	
	//����huffman��
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
	
	//������...
}



/********************************************************/
//ͼ

