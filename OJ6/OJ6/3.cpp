/*
题目描述

虽然 5G 在中国大陆已经普及，但是蓝鲸大学才刚刚通网。现在需要将 n 台计算机连接起来，一台计算机可以间接地通过其他计算机来和另一台计算机连接。由于网线的价格取决于长度，不同的两台计算机之间的连接费用可能是不同的。

由于蓝鲸大学非常穷，小蓝鲸们不得不靠嚼菜根过日子（有时候还会吃出虫子），而昂贵的布线费用无疑会成为压垮蓝鲸大学财务处的最后一根稻草。因此，校领导希望总的连接费用最省，并且任意两台计算机之间都是连通的（不管是直接还是间接的）。请你编程计算这个最小的费用。

输入描述

输入第一行为两个整数 n, m（2 <= n <= 1e5，2 <= m <= 3e5）。其中，n 表示计算机总数，m 表示可以建立的连接数。

接下来 m 行，每行三个整数 a, b, c，表示在机器 a 和机器 b 之间建立连接的费用是 c。

题目保证：
•一定存在可行的连通方案
•不存在自环（即 a=b 的情况）

友情提示：
•可能存在重边（即 a 和 b 之间可能可以建立多个连接，你应该只关注费用最小的连接）
•long long 你懂的

样例输入
3 3
1 2 1
1 3 2
2 3 1

样例输出
2

*/
/*
#include <iostream>
#include<string>
using namespace std;

int cnt[26];


//快速排序
void quick_sort(int* a, int left, int right) {
	if (left >= right) return;
	int i = left - 1, j = right + 1, x = a[left + right >> 1];
	while (i < j) {
		do j--; while (a[j] > x);
		do i++; while (a[i] < x);
		if (i < j) swap(a[i], a[j]);
		else quick_sort(a, left, j), quick_sort(a, j + 1, right);
	}
}

int setup(int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int first = cnt[0], second = cnt[1];

		//cout << cnt[0] << ' ' << cnt[1] << endl;

		cnt[0] = first + second;
		cnt[1] = 0x0fffffff;
		sum += cnt[0];
		quick_sort(cnt, 0, 25);

	}
	return sum;
}

int main() {
	string s; cin >> s;
	int n = 0;
	for (auto c : s) {
		cnt[c - 'A']++;
	}
	for (auto x : cnt) {//统计字母个数
		if (x != 0) n++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) cnt[i] = 0x0fffffff;
	}
	//快速排序

	quick_sort(cnt, 0, 25);


	cout << setup(n) << endl;




	return 0;
}
*/
