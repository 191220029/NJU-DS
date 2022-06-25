/*
围棋比赛

问题描述

围棋，一种策略型两人棋类游戏，中国古时称“弈”，西方名称“Go”。流行于东亚国家（中、日、韩、朝），属琴棋书画四艺之一。围棋起源于中国，传为帝尧所作，春秋战国时期即有记载。隋唐时经朝鲜传入日本，流传到欧美各国。围棋蕴含着中华文化的丰富内涵，它是中国文化与文明的体现。

为了弘扬中国传统文化、丰富居民们的业余生活，某小区决定举办一场围棋比赛。这个小区的居民很多都很喜欢下围棋，所以平时也会相约下棋，经常一起下棋的人对对方的围棋功底都有了解。为了增加趣味性，居民们反映：能否尽量不要让平时经常一起下棋的人在第一轮比赛时就遇到？

看着调查出来的复杂的棋友关系，活动主办方头疼了，于是找到了你，想让你帮忙解决这个问题。活动主办方准备将报名的人分为两组（两组人数可以不同），第一轮比赛时将在组内进行对弈，主办方首先想知道，能否将参赛人员分为符合他们所说要求的两组（即将平时经常一起下棋的人分在不同组）？

输入格式

第一行输入两个数，分别是参赛选手数量 N、以及一个数字 M。（ 0 < N ，M < INT_MAX ）

接下来 M 行，每行均输入两个数 x、y，它们代表对应编号 x、y 的两个参赛者是棋友（即平时经常一起下棋的人）。( N 个参赛者的编号对应为 0 ~ N-1，故而有0 <= x，y <= N-1 )

输出格式

如果可以按要求分组，输出 Yes，否则输出 No。

输入样例

样例1

输入：
6 4
3 2
4 0
2 0
0 1

输出：
Yes

解释：

可分组为：{ 0, 3 }和{ 1, 2, 4, 5 }

样例2

输入：
5 5
0 1
3 0
2 1
0 2
1 4

输出：
No

*/

/*
#include<iostream>

using namespace std;

int N, M;

const int MAX_NUM = 10000;
int group[MAX_NUM]; //[i]'s group is 1 or -1;  0: undefined
int friends[MAX_NUM][MAX_NUM];

int Find_friends(int x, int start) {
	for (int i = start; i < N; i++) {
		if (friends[x][i] == 1) return i;
	}
	return -1;
}

void check_group() {
	//check group[]
	for (int i = 0; i < N; i++) {
		cout << i << ", ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << group[i] << ", ";
	}
	cout << endl;
	return;
}

bool set_group(int k, int group_num) {
	if (group[k] == 0) {//undefined
		group[k] = group_num;
		for (int i = 0; i < N; i++) {
			if (friends[k][i]) { //k and i are friends
				if (group[i] == group_num) return false; //i and k in same group
				if (group[i] == 0)  //i's group is undefined
					//set i's group and check
					if (!set_group(i, -group_num)) return false;;
			}
		}
	}
	//check_group();
	return true;
}

void solution_1() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		friends[a][b] = friends[b][a] = 1;
	}

	//set_group();
	bool flag = true;

	for (int i = 0; i < N; i++) {
		flag &= set_group(i, 1);
	}

	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}
*/