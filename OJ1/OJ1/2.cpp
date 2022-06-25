/*
题目描述
每年都会有很多新生小蓝鲸加入南京大学，小蓝鲸在报到的时候会排起很长的队伍，每个同学只能看到自己前面一位同学的id，请你帮忙复原这个队列。

输入格式
第一行一个整数n（n<=100000），表示有n个整数。Id从（1-n）表示

接下来n行，每行两个数i，j，表示排在整数i前面的那个数是j。

输出格式
1行，n整数，表示完整的队列。
*/

#include <iostream>
using namespace std;
#define MAX_NUMBER 100000
int queue[MAX_NUMBER] = { -1 };
//数组模拟链表
void setupQueue(int curId, int nxtId) {
	queue[nxtId] = curId;
	return;
}

void printQueue(int n) {
	int i = 0;
	for (int cnt = 0; cnt < n; cnt++) {
		cout << queue[i] << ' ';
		i = queue[i];
	}
	cout << endl;
	return;
}

int solution_2() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int curId, nxtId;
		cin >> curId >> nxtId;
		setupQueue(curId, nxtId);
	}
	printQueue(n);
	return 0;
}