/*
ʲô��

��һ����ȫ�������Ĳ����������ӡ���Ӹ��ڵ㵽����Ҷ�ڵ��·������ӡ˳�����Һ���Ȼ���жϸ����Ǵ󶥶ѡ�С���ѻ��߲��Ƕ�

�����ʽ

��һ�и���һ��������N (1<N��1000)�������еĽڵ�����Ȼ����һ�а���N����ͬ������(����int��Χ��)������ȫ�������Ĳ���������С�

�����ʽ

����ÿ���������������ȴ�ӡ�Ӹ���Ҷ������·����ÿ��·��ռ��һ�У���������֮����һ���ո���������׺���β��û�ж���Ŀո�·�����밴����˳���ӡ:�������е�ÿ���ڵ㣬���������е�����·���������������е�����·��֮ǰ��ӡ������������һ�����ѣ��������Max Heap���������һ����С�ѣ��������Min Heap��������������Ƕѣ������"Not Heap"��

��������1
8
98 72 86 60 65 12 23 50

�������1
98 86 23
98 86 12
98 72 65
98 72 60 50
Max Heap

��������2
8
8 38 25 58 52 82 70 60

�������2
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