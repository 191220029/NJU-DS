/*
什么堆

给一棵完全二叉树的层序遍历，打印出从根节点到所有叶节点的路径，打印顺序先右后左，然后判断该树是大顶堆、小顶堆或者不是堆

输入格式

第一行给出一个正整数N (1<N≤1000)，即树中的节点数。然后下一行包含N个不同的整数(都在int范围内)，是完全二叉树的层序遍历序列。

输出格式

对于每个给定的树，首先打印从根到叶的所有路径。每条路径占用一行，所有数字之间用一个空格隔开，行首和行尾都没有额外的空格。路径必须按以下顺序打印:对于树中的每个节点，其右子树中的所有路径必须在左子树中的所有路径之前打印。最后，如果它是一个最大堆，则输出“Max Heap”，如果是一个最小堆，则输出“Min Heap”，如果根本不是堆，则输出"Not Heap"。

输入样例1
8
98 72 86 60 65 12 23 50

输出样例1
98 86 23
98 86 12
98 72 65
98 72 60 50
Max Heap

输入样例2
8
8 38 25 58 52 82 70 60

输出样例2
8 25 70
8 25 82
8 38 52
8 38 58 60
Min Heap

*/
/*

#include<iostream>
#include<string>
using namespace std;

bool max_heap_flag = true;
bool min_heap_flag = true;
bool not_heap_flag = true;

int* a;

string paths[1000];
int paths_cnt;

struct TreeNode {
	int data;
	TreeNode* left, * right;
	TreeNode() {
		left = NULL; right = NULL;
	}
}*head;

TreeNode* setup_tree(int index, const int& length) {
	if (index >= length)return NULL;
	TreeNode* root = new TreeNode;
	root->data = a[index];
	root->left = setup_tree(index * 2 + 1, length);
	root->right = setup_tree(index * 2 + 2, length);
	return root;
}

void find_path(TreeNode* p, string path) {
	if (p == NULL) return;
	path = path + to_string(p->data) + " ";
	if (p->left == NULL && p->right == NULL) {
		paths[paths_cnt] = path;
		paths_cnt++;
		return;
	}
	if (p->left) find_path(p->left, path);
	if (p->right) find_path(p->right, path);
	return;
}

void check_heap(TreeNode* p){
	if (p == NULL)return;
	if (p->left) {
		if (p->data > p->left->data) {
			min_heap_flag = false;
		}
		if (p->data < p->left->data)
			max_heap_flag = false;
		check_heap(p->left);
	}
	if (p->right) {
		if (p->data > p->right->data) {
			min_heap_flag = false;
		}
		if (p->data < p->right->data)
			max_heap_flag = false;
		check_heap(p->right);
	}
	return;
}

void solution_2() {
	int N; cin >> N;
	a = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	head = setup_tree(0, N);

	find_path(head, "");
	for (int i = paths_cnt; i >= 0; i--) {
		cout << paths[i] << endl;
	}

	check_heap(head);
	if (min_heap_flag) cout << "Min Heap\n";
	else if (max_heap_flag) cout << "Max Heap\n";
	else cout << "Not Heap\n";
	return;
}

int main() {
	solution_2();
	return 0;
}
*/