/*
收集雨水
给定 *N* 个非负整数，表示每个宽度为 1 的柱子的高度图。计算按此排列的柱子，下雨之后能接多少雨水。

例如，下图是由输入样例表示的高度图。在这种情况下，最多可以接 6 个单位的雨水（在图中用蓝色表示）。

输入格式
输入的第一行给出了柱子总个数 *N* (1 ≤ *N* ≤ 1e6)。

输入的第二行给出了这 *N* 个非负整数（均不超过 1e8），中间用空格隔开。

输出格式
输出一个非负整数，表示能收集到的雨水的单位数量。

输入样例
12
0 1 0 2 1 0 1 3 2 1 2 1
输出样例
6
*/

#include<iostream>
using namespace std;

long long max(long a, long b) {
	if (a > b) return a;
	return b;
}

long long min(long a, long b) {
	if (a < b)return a;
	return b;
}

void solution_2() {
	//读入数据;
	int N; cin >> N;
	long long* height = new long long[N];//高度
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	long long* maxl = new long long[N];	//记录位置i左侧的最大值
	long long* maxr = new long long[N];	//记录位置i右侧的最大值
	long long maxh = 0;
	for (int i = 0; i < N; i++) {
		maxl[i] = maxh;
		maxh = max(maxh, height[i]);
	}
	maxh = 0;
	for (int i = N - 1; i >= 0; i--) {
		maxr[i] = maxh;
		maxh = max(maxh, height[i]);
	}

	long long res = 0;
	//统计积水
	for (int i = 1; i < N - 1; i++) {
		long long lowermax = min(maxl[i], maxr[i]);//找出左右两端最高高度的较小者
		if (height[i] < lowermax)
			res += lowermax - height[i];
	}
	cout << res << endl;
	return;
}