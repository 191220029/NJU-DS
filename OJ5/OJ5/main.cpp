#include<iostream>
using namespace std;

const int MAX_INT = 100;

template <class T> 
class Queue {
public:
	void deQueue(T& x);
	void enQueue(T x);
	bool isEmpty() {
		return rear == head;
	}
	int size() {
		return rear - head;
	}
	int getHead(){
		return head;
	}
	int getRear() {
		return rear;
	}
	Queue(){
		rear = 0; head = 0;
	}

	T q[MAX_INT];
private:
	int head;
	int rear;
};

template <class T>
void Queue<T>::deQueue(T& x) {
	x = q[head];
	head++;
}

template <class T>
void Queue<T>::enQueue(T x) {
	q[rear] = x;
	rear++;
}





struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode() { left = right = NULL; }
	TreeNode(int x) {
		data = x; left = right = NULL;
	}
}*Thead;
/*
TreeNode* buildBinaryTree(int inorder[], int inLeft, int inRight, int postorder[], int postLeft, int postRight) {
	if (inLeft > inRight) return NULL;
	TreeNode* root = new TreeNode(postorder[postRight]);
	//如果只有一个结点，返回root
	if (inLeft == inRight) return root;
	int rootNum = 0;
	for (int i = inLeft; i <= inRight; i++) {
		if (inorder[i] == postorder[postRight]) {
			rootNum = i;
			break;
		}
	}
	int LeftLength = rootNum - inLeft;
	//递归构造左子树、右子树
	root->left = buildBinaryTree(inorder, inLeft, inLeft + LeftLength - 1, postorder, postLeft, postLeft + LeftLength - 1);
	root->right = buildBinaryTree(inorder, inLeft + LeftLength - 1, inRight, postorder, postLeft + LeftLength, postRight - 1);
	return root;
}
*/

TreeNode* buildBinaryTree(int inorder[], int postorder[], int L_inorder, int R_inorder, int L_postorder, int R_postorder) {
	if (L_postorder > R_postorder) return NULL;
	TreeNode* root = new TreeNode;
	root->data = postorder[R_postorder]; 
	
	int pos;
	for (pos = L_inorder; pos <= R_inorder; pos++) { //find root in inorder
		if (inorder[pos] == postorder[R_postorder]) break;
	}

	root->left = buildBinaryTree(inorder, postorder, L_inorder, pos - 1, L_postorder, L_postorder + pos - L_inorder - 1);
	root->right = buildBinaryTree(inorder, postorder, pos + 1, R_inorder, L_postorder + pos - L_inorder, R_postorder - 1);
	return root;
}
/*
TreeNode* buildTree(int inorder[], int postorder[]) {
	if (sizeof(inorder) == 0)return NULL;
	return buildBinaryTree(inorder, 0, sizeof(inorder) / sizeof(int) - 1, postorder, 0, sizeof(postorder) / sizeof(int) - 1);
}
*/


//交叉层次遍历
void getGifts(TreeNode* head) {
	if (head == NULL)return;
	Queue<int> gifts;
	Queue<TreeNode*> treeQ;
	treeQ.enQueue(head);
	
	bool LRflag = false; //from left to right

	/*
	while (!treeQ.isEmpty()) {
		TreeNode* p = new TreeNode;
		treeQ.deQueue(p); cout << p->data << ' ';
		if (LRflag) {
			if (p->left != NULL)treeQ.enQueue(p->left);
			if (p->right != NULL)treeQ.enQueue(p->right);
			LRflag = false;
		}
		else {
			if (p->right != NULL)treeQ.enQueue(p->right);
			if (p->left != NULL)treeQ.enQueue(p->left);
			LRflag = true;
		}
	}
	*/
	while (!treeQ.isEmpty()) {
		int size = treeQ.size(); //number of nodes at current row
		Queue<int> temp;
		int i = 0;
		while (i < size) {
			TreeNode* p = treeQ.q[treeQ.getHead()];
			temp.enQueue(p->data);
			if (p->left != NULL) {
				treeQ.enQueue(p->left);
			}
			if (p->right != NULL) {
				treeQ.enQueue(p->right);
			}
			TreeNode* nouse;
			treeQ.deQueue(nouse);
			i++;
		}
		if (!LRflag) {
			Queue<int> res;
			/*for (int i = temp.getRear() - 1; i >= temp.getHead(); i--) {
				gifts.enQueue(temp.q[i]);
			}*/
			
			for (int i = temp.getRear() - 1; i >= temp.getHead(); i--) {
				res.enQueue(temp.q[i]);
			}
			for (int i = res.getHead(); i < res.getRear(); i++) {
				gifts.enQueue(res.q[i]);
			}
			LRflag = true;
		}
		else {
			for (int i = temp.getHead(); i < temp.getRear(); i++) {
				gifts.enQueue(temp.q[i]);
			}
			LRflag = false;
		}

	}
	

	//print gifts
	for (int i = gifts.getHead(); i < gifts.getRear(); i++) {
		cout << gifts.q[i] << ' ';
	}
	cout << endl;
	return;
}

void solution_3() {
	int N; cin >> N;
	int* inorder = new int[N];
	int* postorder = new int[N];
	//读入遍历
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	Thead = buildBinaryTree(inorder, postorder, 0, N - 1, 0, N - 1);
	
	getGifts(Thead);
	return;
}

int main() {
	solution_3();
	return 0;
}