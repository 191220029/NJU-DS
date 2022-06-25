/*
反转链表
请编写程序将一个单链表反转。例如：给定的单链表为 1→2→3→4→5→6，则输出应该为 6→5→4→3→2→1。

输入格式
输入的第一行给出了链表的首结点的地址，和结点总个数 N (N ≤ 1e5)。

接下来的 N 行， 每行格式为：

Address Data Next
其中，Address 是当前节点的地址，Data 是该结点保存的数据（整数，且在 32 位 int 表示范围之内），Next 是下一结点的地址。（结点的地址是 5 位非负整数，NULL 地址用 −1 表示）

输出格式
对每个测试用例，顺序输出反转后的链表。每个结点占一行，格式与输入相同。

输入样例
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

输出样例
68237 6 99999
99999 5 00000
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 -1
*/

#include<iostream>
using namespace std;

const int MAX_SIZE = 1e5 + 1;
int q[MAX_SIZE][2] = { 0 };

void rprint(int tail, int head_add) {
	while (q[tail][1] != head_add) {
		printf("%05d %d %05d\n", q[tail][1], q[tail][0], q[q[tail][1]][1]);
		tail = q[tail][1];
	}
	printf("%05d %d %d\n", q[tail][1], q[tail][0], -1);
	return;
}

void solution_1() {
	int head_add, N; cin >> head_add >> N;
	//存放各个结点
	for (int i = 0; i < N; i++) {
		int add, data, nxt; cin >> add >> data >> nxt;
		//尾结点nxt=-1，放在数组最后一个位置
		if (nxt == -1) { q[MAX_SIZE - 1][0] = data; q[MAX_SIZE - 1][1] = add; }
		else q[nxt][0] = data; q[nxt][1] = add;
	}
	//倒序输出
	rprint(MAX_SIZE - 1, head_add);
	/*
	string head_add; int N; cin >> head_add >> N;
	Node* list = new Node[N];
	Node* rlist = new Node[N];//反转后的链表
	int head_idx = 0;
	//读入各节点数据
	for (int i = 0; i < N; i++) {
		string cur; int data; string next; cin >> cur >> data >> next;
		list[i] = Node(cur, data, next);
		//找到头结点的下标
		if (cur == head_add) head_idx = i;
	}
	//排出倒序链表
	adjust(list, rlist, head_idx, N);
	//倒序输出
	print(rlist, N);
	*/
	return;
}