/*
����һ�����������ж��Ƿ����һ�����ڵ㵽Ҷ�ڵ�·��֮�͵���n����
������������ͼ�ж������ı�ʾ��5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1��
��ô���дӸ��ڵ㵽Ҷ�ڵ�·��֮��Ϊ27,22,26,18

ʵ��5-1

�����ʽ

��һ��һ��n���ڶ�������һ�����ֱ�ʾ�������������-1��ʾ�սڵ㣬

�����ʽ

yes����no

��������
22
5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1
20
5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1
10
3 2 4 -1 -1 8 -1 -1 1 6 -1 -1 4 -1 -1
5
-1

�������
yes
no
yes
no

*/

/*
#include<iostream>
using namespace std;

const int MAX_SIZE = 10000;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode() { left = right = parent = NULL; }
	TreeNode(int x) {
		data = x; left = right = parent = NULL;
	}
}*THead;

int findRoot(TreeNode* head, TreeNode *cur) {
	int cnt = 0;
	TreeNode* p = cur;
	while (p != head && p->parent != NULL) {
		cnt += p->data;
		p = p->parent;
	}
	return cnt;
}

void setupTree() {
	//int* datas = new int[MAX_SIZE];
	int cnt_neg = 1;//��Ҫ������-1�����Ż���ֹ����

	int x;


	//int k = 0;//������Ҷ�ڵ����Ŀ
	//������������Ҷ�ڵ�����Ҷ�ڵ����������������ڵ��·������
	cin >> x;
	TreeNode* cur = NULL;
	if (x != -1) {
		cnt_neg++;
		cur = new TreeNode(x);
		THead = cur;
		cur->left = new TreeNode; cur->left->parent = cur;
		cur = cur->left;
	}
	else cnt_neg--;
	while (cnt_neg != 0) {
		cin >> x;
		if (x != -1) {
			cnt_neg++;
			cur->data = x;
			cur->left = new TreeNode; cur->left->parent = cur;
			cur = cur->left;
		}
		else {//x == -1
			cnt_neg--;
			TreeNode* p = cur;
			while (cur->parent->right != NULL && cur->parent != THead) {
				cur = cur->parent;
			}
			if (cnt_neg > 0) { //still have input to create new node
				cur->parent->right = new TreeNode;
				cur->parent->right->parent = cur->parent;
				cur = cur->parent->right;
			}


			if (p == p->parent->left)
				p->parent->left = NULL;
			else p->parent->right = NULL;
			delete p;
		}
	}



	return;
}

bool front_vist_Tree(TreeNode* cur, const int &target, int cnt) {//ǰ�������

	if (cur == NULL)return false;
	//cout << "cur->data = " << cur->data << ", cur->left->data = " << cur->left->data << "cur->right->data =" << cur->right->data << endl;
	cnt += cur->data;
	if (cur->left == NULL && cur->right == NULL) {// cur is leaf

		//cout << "cur->data = " << cur->data << ", cnt = " << cnt << endl;

		if (cnt == target)return true;
		else return false;
	}
	else {//way to the leaf
		return (front_vist_Tree(cur->left, target, cnt) |
			front_vist_Tree(cur->right, target, cnt));
	}


	return false;
}



void solution_1() {
	int N; cin >> N;
	setupTree();
	bool flag = front_vist_Tree(THead, N, 0);
	if (flag) cout << "yes" << endl;
	else cout << "no" << endl;
}
*/