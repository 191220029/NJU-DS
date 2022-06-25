/*
地势研究

问题描述

小蓝鲸准备去远足，但是远足的地方地势高低不平，所以他决定顺势研究一下地势。给你一个二维 rows∗cols
rows∗cols
 的地图 heights
heights
 ，其中 heights[row][col]
heights[row][col]
 表示地点(row,col)
(row,col)
 的高度。小蓝鲸从最左上角即西北角的地点 (0,0)
(0,0)
 出发，去最右下角即东南角的地点 (rows−1,cols−1)
(rows−1,cols−1)
 。小蓝鲸每次可以往东，南，西，北四个方向之一移动，现在请你帮小蓝鲸找到__地势落差最小__的一条路径。

一条路径的__地势落差__的定义是，路径上相邻地点之间__高度差绝对值__的最大值。

请你返回从西北角走到东南角的最小地势落差 。

输入格式

第一行，给出地图南北方向距离 rows
rows
 和东西方向距离 cols
cols


接下来 rows
rows
 行，每行 cols
cols
 个整数，给出地势高度

其中，1≤rows,clos≤100
1≤rows,clos≤100
 ， 1≤heigths[raw][col]≤10 6
1≤heigths[raw][col]≤106


输出格式

最小体力消耗值

输入样例

样例1

输入：
3 3
1 2 2
3 8 2
5 3 5

输出：
2

解释：
路径 [1,3,5,3,5] 连续地点的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。

*/
/*
#include<iostream>
//#include<string>

using namespace std;

const int MAX_NUM = 102;
int heights[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];
int rows, cols;

int ans = 0;
//int mem[MAX_NUM][MAX_NUM];

void init_vst() {
	for (int i = 0; i < MAX_NUM; i++) {
		for (int j = 0; j < MAX_NUM; j++) {
			visited[i][j] = 0;
		}
	}
}

int my_abs(int a) {
	return (a < 0) ? -a : a;
}

bool find_path(int x, int y, int cur_max) {//if there is path with gap < cur_max, return true;

	if (x == rows - 1 && y == cols - 1) {
		return true;
	}
	bool flag = false;
	visited[x][y] = true;
	if (x + 1 < rows && !visited[x + 1][y]) {
		int temp = my_abs(heights[x + 1][y] - heights[x][y]);
		if (temp <= cur_max)
			flag |= find_path(x + 1, y, cur_max);
	}
	if (x - 1 >= 0 && !visited[x - 1][y]) {
		int temp = my_abs(heights[x - 1][y] - heights[x][y]);
		if (temp <= cur_max)
			flag |= find_path(x - 1, y, cur_max);
	}
	if (y + 1 < cols && !visited[x][y + 1]) {
		int temp = my_abs(heights[x][y + 1] - heights[x][y]);
		if (temp <= cur_max)
			flag |= find_path(x, y + 1, cur_max);
	}
	if (y - 1 >= 0 && !visited[x][y - 1]) {
		int temp = my_abs(heights[x][y - 1] - heights[x][y]);
		if (temp <= cur_max)
			flag |= find_path(x, y - 1, cur_max);
	}
	return flag;
}

void solution_1() {
	cin >> rows >> cols;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> heights[i][j];
	//endfor

	int left = 0, right = 1000000;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;

		init_vst();

		if (find_path(0, 0, mid)) { //find if path with max_gap <= mid
			right = mid - 1;
			ans = mid; //possible biggest ans is mid, maybe there is smaller one, so decrease 'right' and search again until 'left > right'
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << endl;
}

int main() {
	solution_1();
	return 0;
}
*/