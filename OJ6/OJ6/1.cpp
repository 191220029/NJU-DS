/*
小蓝鲸的家谱

问题描述

家谱：又称族谱、宗谱等。是一种以表谱形式，记载一个家族的世系繁衍及重要人物事迹的书。家谱是一种特殊的文献，就其内容而言，是中华文明史中具有平民特色的文献，记载的是同宗共祖血缘集团世系人物和事迹等方面情况的历史图籍。小蓝某天找到了自己家的家谱，小鲸于是决定和他玩一个游戏来考察小蓝对自己家族的了解程度。

小鲸将随机说出小蓝家谱上任意两个人，小蓝则需要马上回答出，这两个人最近的共同先祖，需要注意的是，某些情况下，小鲸说出的两个人中某一个可能正好就是另一个人的先祖。现在，请你编程模拟回答小鲸提出的问题。已知：
•小蓝的先祖规定，他们家族内每一对夫妻最多只能生两个孩子。
•为了简化问题，家谱上只写出了本家人，即他们的丈夫/妻子均未列出，回答时也只需要回答出小蓝的本家人即可。
•小鲸不是喜欢恶作剧的人，所以保证他每次问出两个人一定不相同、且一定在小蓝的家谱上。
•小鲸已经帮你把小蓝家谱上所有人的人名存入到了数据库中，所以你只需要处理一份简化后家谱，其中每个人都是用一个唯一的数字在家谱中标识的。

输入格式

第一行和第二行依次输入家谱上两个不相同的人 p,q, (0 < p,q < 10^5) 。

第三行输入简化后的家谱的节点个数 n 。

接下来一行，按照简化家谱的层序遍历的方式输入 n 个各不相同的数字 t_i, ( -2 < t_i < 10^5; i=1,2,…,n )，其中 -1 代表该节点为空。

输出格式

输出代表 p 和 q 最近的共同先祖的那个数字。

输入样例

样例1

输入：
5
3
9
1 2 -1 3 4 -1 -1 5 -1

输出：
2

解释：上述输入对应的简化家谱如下

example1

样例2

输入：
6
2
11
1 2 8 3 4 9 -1 5 -1 6 7

输出：
2

解释：上述输入对应的简化家谱如下


*/
/*
#include<iostream>
using namespace std;

#define MAX_NUM 1000
int family[100000];
int a, b;


struct TreeNode {
	int data;
	TreeNode* left, * right;
	TreeNode() {
		left = NULL; right = NULL;
	}
};


TreeNode *Na, *Nb;
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
	int getHead() {
		return head;
	}
	int getRear() {
		return rear;
	}
	Queue() {
		rear = 0; head = 0;
	}
	T operator[](int x) {
		return q[x];
	}

	T q[MAX_NUM];
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




//根据层次遍历序列建立二叉树
TreeNode* setupTree(int index, const int& rear) {
	TreeNode* root = NULL;
	if (index >= rear)return root;
	if (family[index] != -1) {
		root = new TreeNode; root->data = family[index];

		if (root->data == a) Na = root;
		if (root->data == b) Nb = root;

		int cnt = 0;
		for (int i = 0; i < index; i++) {
			if (family[i] == -1) cnt++;
		}

		root->left = setupTree((index - cnt)* 2 + 1, rear);
		root->right = setupTree((index - cnt)* 2 + 2, rear);
	}
	return root;
}

bool getAncestor(TreeNode* root, TreeNode* p, Queue<TreeNode*>& vec) {
	if (root == NULL) return false;
	if (root == p) {
		vec.enQueue(root);
		return true;
	}
	if (getAncestor(root->left, p, vec) || getAncestor(root->right, p, vec)) {
		vec.enQueue(root);
		return true;
	}
	return false;

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	Queue<TreeNode*> vp, vq;
	getAncestor(root, p, vp);
	getAncestor(root, q, vq);
	int n = vp.size(), m = vq.size();
	while (n > 0 && m > 0 && vp[n - 1] == vq[m - 1]) {
		n--;
		m--;
	}
	return vp[n];
}

void solution_1() {
	cin >> a >> b;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> family[i];
	}

	TreeNode* root = setupTree(0, N - 1);

	TreeNode* r = lowestCommonAncestor(root, Na, Nb);

	cout << r->data << endl;

	return;
}

int main() {
	solution_1();
	return 0;
}
*/