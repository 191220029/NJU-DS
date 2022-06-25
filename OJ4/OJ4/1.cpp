/*
小蓝鲸做作业
小蓝鲸的老师最近在课上讲了对角矩阵、上下三角矩阵，但是小蓝鲸没有认真听讲，
以至于布置的作业都不会做，你能帮帮他吗？作业是这样的：
给定一个 NxN 的非零方阵，判断其类型。输入的第一行是整数 N（N < 100），
表示方阵的维度。接下来给出一个 NxN 的方阵，方阵中的每个元素都是自然数，
且不超过 100。
如果它是对角矩阵（主对角线以外的元素全都为 0），请输出 "diagonal"
如果它是上三角矩阵（主对角线以下的元素全都为 0），请输出 "upper"
如果它是下三角矩阵（主对角线以上的元素全都为 0），请输出 "lower"
如果上面三种都不是，请输出 "none"

输入输出样例

3
23 0 10
0 7 9
0 0 0


3
3 0 0
0 7 0
0 0 0


3
1 0 1
0 1 0
1 0 1
upper
diagonal
none
*/

/*
#include<iostream>
using namespace std;

void solution_1() {
	bool diagonal = true, upper = true, lower = true;

	int n; cin >> n; //输入维度
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			if (x != 0) {
				if (i != j) diagonal = false;
				if (i < j) lower = false;
				else if (i > j) upper = false;
			}
		}
	}

	//输出结果
	if (diagonal) printf("diagonal\n");
	else if (upper) printf("upper\n");
	else if (lower) printf("lower\n");
	else printf("none\n");
}
*/