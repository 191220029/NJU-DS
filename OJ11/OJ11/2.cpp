/*
散财消灾

哄抬食材价格的奸商夜里做了一个噩梦，在梦中他掉进了一个由魔鬼把守的迷宫。起始奸商所处的位置是A地，迷宫的出口在B地。已知地区之间以路相连，假设一个地区有K
K
条路可以选择前进，那么其中必定有K−1
K−1
条路对应的路口有魔鬼把守，若想从有魔鬼把守的路口进入，必须支付给魔鬼一枚金币。请问奸商想要到达B地至少需要支付几个硬币。

注意，进入有魔鬼把守的路口需要支付金币，从有魔鬼把守的路口走出则不需要。 注意，地区与通路组成的图是无向的，恶魔守在路的两端（即路口处），但一条路两端不一定都有恶魔把守。

输入格式

第一行输入包括整数N A B, 2≤N≤200, 1≤A,B≤N
N A B, 2≤N≤200, 1≤A,B≤N
，N
N
代表地区数量，地区编号为[1,N]
[1,N]
，A
A
代表奸商当前所在地区，B
B
代表迷宫出口所在地区。

接下来N
N
行输入中，第i
i
行的第一个数字i 1
i1
代表i
i
地与i 1
i1
个地区相邻，该行接下来i 1
i1
个输入分别代表与i
i
地相邻的地区。这i 1
i1
个输入中的第一个对应没有魔鬼把守的路口。

输出格式

直接输出至少要支付的金币数，若无法到达则输出-1

输入样例
3 2 1
2 2 3
2 3 1
2 1 2

解释：如第二行输入“2 2 3”代表1与两个地区有通路相连，分别是2和3；其中1通向2的路口没有魔鬼把守，其余路口均有魔鬼把守。

输出样例
0

样例

2到3的路口没有魔鬼把守，3到1的路口没有魔鬼把守;因此2到1无需支付任何金币。

*/
/*
#include<iostream>
//#include<string>

using namespace std;

int N, A, B;
const int MAX_NUM = 300;
const int MAX_INT = 1000;
int path[MAX_NUM][MAX_NUM];

void init_path() {
	for (int i = 0; i < MAX_NUM; i++)
		for (int j = 0; j < MAX_NUM; j++)
			path[i][j] = (i == j) ? 0 : MAX_INT;
}

void solution_2() {
	init_path();
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		int n, b;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> b;
			path[i][b] = (j == 0) ? 0 : 1;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (path[i][j] > path[i][k] + path[k][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}

	if (path[A][B] > N)
		cout << "-1" << endl;
	else cout << path[A][B] << endl;
	return;
}

int main() {
	solution_2();
	return 0;
}
*/