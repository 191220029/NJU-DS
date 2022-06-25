/*
小蓝鲸站位

现在有 N 个小蓝鲸需要在蓝鲸大学的操场上站位。蓝鲸大学的操场是一个 NxN 的方阵，方阵中的每一个格子最多只能容纳一个小蓝鲸。并且，由于最近的雨雪天气，有的格子是不能站人的（因为积水）。

此外，蓝鲸大学学风彪悍，小蓝鲸们也都非常 aggressive。如果有两个小蓝鲸位于同一横行、纵行、或者斜线，他们将会打起来。这好吗？这不好。

作为校领导的你，肯定希望年轻的小蓝鲸们要以和为贵，要讲武德，不要搞窝里斗。请你编程求出有多少种站位方法，确保每个小蓝鲸都有位置，并且他们不会打起来。

输入格式

输入的第一行包括整数 N 和 M。其中，N 不仅表示操场的大小（NxN），也表示小蓝鲸的数量。M 表示操场上有多少个格子因为积水原因无法站人。

接下来的M行，每行包括两个正整数 X Y，分别表示积水格子的横纵坐标（坐标从 1 开始：左上角是 1 1，右下角是 N N）。

数据范围：N 不超过 12，M 不超过 $N^2$。

输出格式

一个自然数，表示有多少种站位方法。

样例输入 1
10 3
4 7
2 6
8 1

样例输出 1
532

样例输入 2
6 6
1 6
2 6
3 6
4 6
5 6
6 6

样例输出 2
0

样例 2 解释：在 6x6 的操场中，第 6 列的格子全部都因为积水无法站人。根据抽屉原理，如果将 6 个小蓝鲸放置在仅有 5 列的操场中，那么必有两个小蓝鲸位于同一列，从而打起来。因此无解，输出 0。

*/

/*
#include<iostream>

using namespace std;

int m, n;

const int N = 13;

int water[N][N];
int queen[N][N];
int isSafe(int row, int col, int n) { // if [row][col] is in water or in confict with others
	if (water[row][col]) return 0;
	int i, j;
	for (i = 0; i < n; i++) { //judge same column
		if (queen[i][col] == 1)
			return 0;
	}
	for (j = 0; j < n; j++) { //judge same row
		if (queen[row][i] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) { //judge left up
		if (queen[i][j] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j < n; i--, j++) {//judge right up
		if (queen[i][j] == 1)
			return 0;
	}
	return 1;
}
void eightqueen(int row, int& count, int n) {
	if (row >= n) { //one valid anwser
		count++;
		return;
	}
	for (int j = 0; j < n; j++) {
		if (isSafe(row, j, n)) {
			queen[row][j] = 1;
			//goto next row to see if there is valid position to stand
			eightqueen(row + 1, count, n);

			//reset cur position to see if there are other valid answers
			queen[row][j] = 0;
		}
	}
}

void solution_3() {
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		water[x - 1][y - 1] = 1;
	}
	eightqueen(0, cnt, n);
	cout << cnt;
	return;
}

int main() {
	solution_3();
	return 0;
}
*/