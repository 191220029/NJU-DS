/*
题目描述

你和n个小蓝鲸们在一起玩游戏，每个小蓝鲸身上都有一块号码牌，小蓝鲸们想要考考你，
于是他们按照号码牌为a1, a2, ..., an的顺序站成了一列。
然后问你，这一列小蓝鲸中，是否存在三个小蓝鲸，他们是按照这样的相对顺序排列的：
这三个小蓝鲸的号码牌依次为：ax, ay, az ，其中x<y<z，但号码牌的值要满足ax<az<ay。
你能回答这个问题吗？

C++这三个人的号码牌依次为：ax, ay, az ，其中x<y<z，但号码牌的值满足ax<az<ay。

考察数据结构：栈。

输入格式

第一行输入小蓝鲸的数量n，
接下来n行依次输入每个小蓝鲸的号码牌ai（i=1,2,3,…,n）的值。

输出格式
若存在上述排列的三个小蓝鲸，则输出True；否则，输出False。

样例数据

样例1
输入
1 2 3 4
输出
False
解释：不存在这样排列的三个小蓝鲸。
样例2
输入
3 1 4 2
输出
True
解释：有一组这样排列的三个小蓝鲸，他们的号码牌为[1, 4, 2]。
样例3

输入
-1 3 2 0

输出
True
/*
#include<iostream>
using namespace std;

int a[10000];

void solution_2() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {//寻找第三个合适的数
				for (int k = j + 1; k < n; k++) {
					if (a[i] < a[k] && a[j] > a[k]) {
						cout << "True" << endl;
						return;
					}
				}
			}
		}
	}
	cout << "False" << endl;
}

int main() {
	solution_2();
	return 0;
}
*/