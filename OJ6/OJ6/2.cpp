/*
小蓝鲸的试卷掌握度

为了应对期中考试，大蓝鲸决定帮助小蓝鲸复习。大蓝鲸通过反复地出试卷来让小蓝鲸进行练习的方法，来了解小蓝鲸的知识掌握情况，让小蓝鲸针对薄弱知识点巩固学习。

首先，大蓝鲸让小蓝鲸练习去年的试卷 a 。接着，大蓝鲸以试卷 a 为模板，修改若干题目，生成若干张试卷（0 ≤ 试卷数量 ≤ 2），再让小蓝鲸做试卷练习。每次小蓝鲸做完一张试卷，大蓝鲸都会以该试卷为模板，出若干张新卷子来让小蓝鲸练习（0 ≤ 试卷数量 ≤ 2）。

对于每一张试卷，将这张试卷以及以该试卷为模板的所有试卷的平均分，作为小蓝鲸对这张试卷的掌握度。比如，试卷 a 为所有试卷的模板，因此，试卷 a 的掌握度，即所有试卷的分数总和，除以试卷总数。

已知所有试卷的得分，试求在所有试卷中，小蓝鲸掌握度的最大值多少？

输入格式

试卷间生成关系可以看成一棵二叉树。其中试卷 a 为根节点。层次遍历输入每张试卷的得分。（-1 表示无节点）

输出格式

输出最大掌握度，保留五位小数。

示例

输入
9 5 4 -1 -1 -1 -1

输出
6.00000

图解

试卷间生成关系如下：（节点中的数字为试卷得分）

第一张试卷分数为 9；以第一张试卷为模板，生成第二张试卷和第三张试卷，分数分别为 5 和 4。

tree.png

第一张试卷的掌握度：(9 + 5 + 4) / 3 =6；

第二张试卷的掌握度：5 / 1 = 5；

第三张试卷的掌握度：4 / 1 = 4；

第一张试卷，即根节点试卷的掌握度最大，为 6，即为答案。

提示
•试卷总数范围 (0, 5000]
•试卷分数范围 (0, 100000]

*/

/*
#include<iostream>
using namespace std;

int paper[5000000];
double max_avg;

struct sn{
	int sum;
	long long num;
	sn(int s, long long n) { sum = s; num = n; }
};//-> pair<int, int>

struct TreeNode {
	int data;
	TreeNode *left, *right;
	TreeNode() {
		left = NULL; right = NULL;
	}
};


sn dfsTree(TreeNode* head) {
	long long sum = head->data; //结点值的和
	int num = 1;			//结点数量
	if (head->left != NULL) {
		sn tmp = dfsTree(head->left);
		sum += tmp.sum;
		num += tmp.num;
	}
	if (head->right != NULL) {
		sn tmp = dfsTree(head->right);
		sum += tmp.sum;
		num += tmp.num;
	}
	double avg = (double)sum / (double)num;
	max_avg = (max_avg < avg) ? avg : max_avg;
	sn ret(sum, num);
	return ret;
}

//根据层次遍历序列建立二叉树

TreeNode* setupTree(int index, const int& rear) {
	TreeNode* root = NULL;
	if (index >= rear)return root;
	if (paper[index] != -1) {
		root = new TreeNode; root->data = paper[index];


		int cnt = 0;
		for (int i = 0; i < index; i++) {
			if (paper[i] == -1) cnt++;
		}

		root->left = setupTree((index - cnt)* 2 + 1, rear);
		root->right = setupTree((index - cnt)* 2 + 2, rear);
	}
	return root;
}

void solution_1() {
	int temp = 0, k = 0;
	//while (scanf("%d", &temp) != EOF) {
	while(cin >> temp){
		paper[k] = temp; k++;
		char c = getchar();// cout << "getch:" <<c << endl;
		if (c == '\n')break;
	}

	TreeNode* root = setupTree(0, k);
	if(root)
		dfsTree(root);
	printf("%.5lf\n", max_avg);
	return;
}

int main() {
	solution_1();
	return 0;
}

*/