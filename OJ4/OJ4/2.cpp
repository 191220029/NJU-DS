/*
小蓝鲸们可以得到多少双十一购物津贴？
现在有三组小蓝鲸，每组小蓝鲸分别整整齐齐排队，形成矩阵 A（n 行 t 列）、
矩阵 B（t 行 m 列）、矩阵 C（n 行 m 列）。依次对每个小蓝鲸发双十一购物津贴。

矩阵 A 中，第 i 行、第 j 列的小蓝鲸获得的购物津贴数目用Ai，j表示，其他矩阵同理。
很巧合的是，我们发现了这样一个规律：
如果已知矩阵 A、B 中小蓝鲸们获得的津贴数，
聪明的你能计算出矩阵 C 中每个小蓝鲸所获得的双十一购物津贴吗？
提示：由于津贴总数有限，所以很遗憾的是，可能大部分的小蓝鲸的购物津贴都为零呢。

输入格式
输入的第一行给出了 A 的行数 n、A 的列数（即 B 的行数）t、B的列数 m，
其中 n,t,m∈(0, 1000]。
接下来依次输出矩阵 A 和矩阵 B 中每个小蓝鲸获得的购物津贴
（每个小蓝鲸获得的购物津贴数目范围在[0, 100]）

输出格式
输出矩阵 C 中每个小蓝鲸获得的购物津贴

输入样例
4 2 2
​
0 0
0 0
52 0
0 0
​
0 77
0 0
输出样例
0 0
0 0
0 4004
0 0
*/

/*
#include<iostream>
using namespace std;

const int N = 1000;
int A[N][N], B[N][N], C[N][N];

void read_in(int M[N][N], int row, int col) {
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j++) {
			int x; cin >> x;
			M[i][j] = x;
		}
	}
	return;
}

void set_zero(int M[N][N], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	return;
}

void solution_2() {
	int n, t, m; cin >> n >> t >> m;
	//将数据读入矩阵
	read_in(A, n, t);
	read_in(B, t, m);

	//初始化矩阵C
	set_zero(C, n, m);

	//做矩阵乘法
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < t; i++) {
				C[k][j] += A[k][i] * B[i][j];
			}
		}
	}


	//打印答案
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << C[i][j] << ' ';
		}
		cout << endl;
	}
}
*/