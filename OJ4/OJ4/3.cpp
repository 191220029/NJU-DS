/*
小蓝鲸再次聚会
题目描述
系里即将举办一次晚会，邀请小蓝鲸们参加，晚会前每个小蓝鲸入场时都将获得一个小记分牌，
进场时每个人的记分牌上的分数均为0。晚会上将进行多个小游戏，
参与游戏的小蓝鲸若赢得游戏则持有的记分牌上将增加相应的分数，
未赢得游戏也能获得一个基础加分，最后晚会结束时，
老师们将根据每个小蓝鲸的分数给他分发对应的奖品。

为了增加大家的团队合作精神，以及活跃晚会气氛、鼓励大家积极参与游戏，
负责统筹晚会的老师规定：如果晚会结束时，某个小蓝鲸完全没有参与游戏（即分数为0），
则该小蓝鲸所在座位的对应那一行以及那一列小蓝鲸们的分数都将清零，
即这些小蓝鲸们也都无法获得奖品。

已知举办晚会的报告厅内的座位按照 m 行 n 列整齐排列，
每个小蓝鲸入座后则不能再改变自己的座位，且由于晚会奖品诱人、节目新颖，
所以晚会开始后报告厅内一定会是满座。

最后晚会结束后、分发奖品前，统筹老师需要先记录所有人记分牌上的分数，
按照规则对某些小蓝鲸的分数进行清零处理后，再对大家进行奖品分发。
现在老师安排你来进行最后的分数统计工作，为了减少时间，
你决定编写一个程序来完成这个分数处理。

输入格式
输入的第一行给出了报告厅内座位的行数 row（ 1 ≤ row ≤ 2048）

输入的第二行给出了报告厅内座位的列数 col（ 1 ≤ col ≤ 2048）

接下来的 row 行， 则将依次输入 col 个数据，为每个同学当前的分数 score
（ 1 ≤ score ≤ 1e9）

输出格式
输出处理后的数组，一共 row 行，每行 col 个数字，每行内的数字用空格分隔开

输入样例1
3
3
1 1 1
1 0 1
1 1 1
输出样例1
1 0 1
0 0 0
1 0 1
输入样例2
3
4
0 1 2 0
3 4 5 2
1 3 1 5
输出样例2
0 0 0 0
0 4 5 0
0 3 1 0
*/

/*

#include<iostream>
using namespace std;

const int N = 2048;
int matrix[N][N];
int* row_zero;
int* col_zero;

void init(int row, int col) {
	for (int i = 0; i < row; i++) {
		row_zero[i] = 1;
	}
	for (int i = 0; i < col; i++) {
		col_zero[i] = 1;
	}
	return;
}

void solution_3() {
	int row; cin >> row;
	int col; cin >> col;
	row_zero = new int[row];
	col_zero = new int[col];
	init(row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//读入数据
			int x; cin >> x;
			matrix[i][j] = x;

			//判断0并记录其位置
			if (!x) {
				row_zero[i] = 0;
				col_zero[j] = 0;
			}
		}
	}

	//输出答案
	for (int i = 0; i < row; i++) {
		if(row_zero[i]) //如果当前行有效
			for (int j = 0; j < col; j++) {
				//当前列有效则输出
				if (col_zero[j]) printf("%d ", matrix[i][j]);
				else printf("0 ");
			}
		else 
			for (int j = 0; j < col; j++) {
				printf("0 ");
			}
		printf("\n");
	}

}*/