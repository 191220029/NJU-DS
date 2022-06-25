/*
最大平衡因子

A：构建由该序列生成的二叉搜索树T，求解所有节点的平衡因子绝对值中的最大值；

平衡因子： 某个结点的左子树的高度减去右子树的高度得到的差值。给定一个二叉树，求改树的最大的平衡因子绝对值。

输入

两行输入，第一行为数组元素个数，N<100005

第二行二叉树节点，举例：给定下图中二叉树的表示：5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1
17
					5
			4				8
	11		-1			13		4
7		2	-1	-1    -1  -1  -1  1


输出

一行输出，直接输出结果

样例
input:
4
3 1 2 5


output:
1
*/

/*
17
5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1

9
3 1 -1 -1 2 1 -1 -1 -1
*/

/*
#include<iostream>

using namespace std;

//const int MAX_N = 100005;
int n;
//int nodes[MAX_N];
int max_be = 0;

int my_abs(int x) { return (x < 0) ? -x : x; }

int depth;

int find_max_be() {
	depth++;
	if (depth > n) return 0;
	int input; cin >> input;
	if (input == -1)return 0;

	int left_depth = find_max_be();
	int right_depth = find_max_be();

	int temp = my_abs(left_depth - right_depth);
	max_be = temp > max_be ? temp : max_be;
	return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

void solution_1() {
	cin >> n;

	find_max_be();
	cout << max_be << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}
*/