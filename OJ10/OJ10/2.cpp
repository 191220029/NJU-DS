/*
矩阵公园

小蓝鲸在二叉树公园隔壁，发现了一个新开园的矩阵公园。

矩阵公园形似矩阵，有 $i$ 行，$j$列小景点，即共 $i*j$ 个小景点。每个小景点中有若干只猫咪（整数只）。对于每个小景点，小蓝鲸只能往东、西、南、北移动。

小蓝鲸希望从某一个小景点开始喂猫，假设当前小景点有 $n$ 只猫咪，那么小蓝鲸只会移动到猫咪数量 $> n$ 的小景点。若可达的小景点的猫咪数量均不大于当前小景点，小蓝鲸就会收拾东西快乐地回家了。

请问，小蓝鲸最多能在多少个小景点喂猫？

注意：只能往东、西、南、北这四个方向移动，不可以向对角线移动，比如，不能向东南方向移动。

注意：由于矩阵公园周围有围墙，所以不能移动到矩阵公园之外。

提示：$0 < i < 500$，$0 < j < 500$，$0 <= n < 200$（即任意小景点的猫咪数量小于 200）

输入：
第一行：矩阵公园小景点 行 i，列 j
之后 i 行：1~i行小景点对应的 j 个景点的猫咪数量

输出：
喂猫景点数量的最大值

示例：

输入：
3 3
1 4 2
5 1 5
5 4 4

输出：
3

提示：

矩阵公园如下：（有 3 * 3 个小景点，矩阵中的数据表示每个景点的猫咪数量）

1 4 2

5 1 5

5 4 4

粗体表示最多小景点的路径，即，1->4->5（猫咪数量递增），共 3 个小景点。

*/

/*
#include<iostream>

using namespace std;

const int MAX_NUM = 501;

int cats[MAX_NUM][MAX_NUM];

int max_mm[MAX_NUM][MAX_NUM]; //memorize the maximum number of spaces can reach when starting from max_mm[i][j]

int I, J;

int dfs(int i, int j) {
	int cur = cats[i][j];
	int left = 0, right = 0, up = 0, down = 0;

	if (max_mm[i][j])
		return max_mm[i][j];
	else {
		if (cats[i][j - 1] > cur) left = dfs(i, j - 1);
		if (cats[i][j + 1] > cur) right = dfs(i, j + 1);
		if (cats[i + 1][j] > cur) up = dfs(i + 1, j);
		if (cats[i - 1][j] > cur) down = dfs(i - 1, j);
		int max;
		max = (left > right) ? left : right;
		max = (max > up) ? max : up;
		max = (max > down) ? max : down;

		max_mm[i][j] = max + 1;

		return max + 1;
	}

}

void solution_2() {
	cin >> I >> J;
	for (int i = 1; i <= I; i++) {
		for (int j = 1; j <= J; j++) {
			cin >> cats[i][j];
		}
	}

	int max = 0;
	for (int i = 1; i <= I; i++) {
		for (int j = 1; j <= J; j++) {
			int temp = dfs(i, j);
			max = max < temp ? temp : max;
		}
	}

	cout << max << endl;

	return;
}

int main() {
	solution_2();
	return 0;
}
*/