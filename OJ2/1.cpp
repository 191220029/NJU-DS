#include<iostream>
#include<string>
using namespace std;

const int MAX_SIZE = 1e5+1;
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

	return;
}

int main() {
	int nxt; cin >> nxt;
	q[nxt][0] = 0;
	solution_1();
	return 0;
}
