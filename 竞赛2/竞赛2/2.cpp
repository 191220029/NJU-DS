/*
��ת�ȼ۶�����

��������

���ǿ���Ϊ������ T ����һ����ת������������ʾ��ѡ������ڵ㣬Ȼ�󽻻���������������������

ֻҪ����һ�������ķ�ת��������ʹ X ���� Y�����Ǿͳƶ����� X ��ת�ȼ��ڶ����� Y��

��дһ���ж������������Ƿ��Ƿ�ת�ȼ۵ĺ�����

�����ʽ

��һ�������һ�����Ľ����� n1

�ڶ��а��ղ�������ķ�ʽ���� n1 ��������ͬ������ t_i, ( -2 < t_i < 1024; i=1,2,��,n )������ -1 ����ýڵ�Ϊ��

��һ������ڶ������Ľ����� n2

�ڶ��а��ղ�������ķ�ʽ���� n2 ��������ͬ������ t_i, ( -2 < t_i < 1024; i=1,2,��,n )������ -1 ����ýڵ�Ϊ��

�����ʽ

�����������ö�������ת�ȼ������ True�� ������� False ��

��������

����
11
1 2 3 4 5 -1 -1 -1 -1 -1 6
10
1 3 2 -1 -1 4 5 -1 -1 6

���
True

���ͣ�

���ö�����ͼ�λ���ʾ���£����Ϊ����ĵ�һ�ö��������ұ�Ϊ����ĵڶ��ö�������

*/

/*
#include <iostream>
using namespace std;

int nodes1[2000];
int nodes2[2000];

struct TreeNode {
	int data;
	TreeNode* left, * right;
	TreeNode() {
		left = NULL; right = NULL;
	}
};

TreeNode* setupTree(int index, int nodes[], const int& rear) {
	TreeNode* root = NULL;
	if (index >= rear)return root;
	if (nodes[index] != -1) {
		root = new TreeNode; root->data = nodes[index];

		int cnt = 0;
		for (int i = 0; i < index; i++) {
			if (nodes[i] == -1) cnt++;
		}

		root->left = setupTree((index - cnt) * 2 + 1, nodes, rear);
		root->right = setupTree((index - cnt) * 2 + 2, nodes, rear);
	}
	return root;
}

void treverse_child(TreeNode* &p) {
	TreeNode* temp = p->left;
	p->left = p->right;
	p->right = temp;
}

bool judge_te(TreeNode* root1, TreeNode* root2) {
	TreeNode* p = root1, * q = root2;
	if (p == NULL && q == NULL) return true;
	if (p->data != q->data) return false;
	if (p->left == NULL && q->left == NULL && p->right == NULL && q->right == NULL) return true;
	if ((int)(p->left == NULL + p->right == NULL) != (int)(q->left == NULL + q->right == NULL)) return false;
	if (p->left == NULL && q->left == NULL) {
		if (p->right->data == q->right->data) return judge_te(p->right, q->right);
		return false;
	}
	if (p->right == NULL && q->right == NULL) {
		if (p->left->data == q->left->data) return judge_te(p->left, q->left);
		return false;
	}
	if (p->left == NULL && q->right == NULL) {
		if (p->right->data == q->left->data) {
			treverse_child(p);
			return judge_te(p->left, q->left);
		}
		return false;
	}
	if (p->right == NULL && q->left == NULL) {
		if (p->left->data == q->right->data) {
			treverse_child(p);
			return judge_te(p->right, q->right);
		}
		return false;
	}


	int lval1 = p->left->data, rval1 = p->right->data, lval2 = q->left->data, rval2 = q->right->data;
	bool need_treverse_flag = false;
	while ((lval1 == lval2 && rval1 == rval2) || (need_treverse_flag = (lval1 == rval2 && rval1 == lval2))) {
		if (need_treverse_flag) {
			treverse_child(p);
		}
		bool lflag = judge_te(p->left, q->left);
		bool rflag = judge_te(p->right, q->right);
		return lflag && rflag;
	}
	return false;
}

void solution_2() {
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> nodes1[i];
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> nodes2[i];
	}
	TreeNode* root1 = setupTree(0, nodes1, n1);
	TreeNode* root2 = setupTree(0, nodes2, n2);

	if (judge_te(root1, root2)) {
		cout << "True" << endl;
	}
	else cout << "False" << endl;
	return;
}

int main() {
	solution_2();
	return 0;
}

*/