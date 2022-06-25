/*
小蓝鲸打游戏

小蓝鲸在“破坏精英”手游里面看到一件非常好看的衣服，但是“麻花藤”（手游内置NPC）要他支付10000个金币才能获得。小蓝鲸的因为刚刚氪金了"元神"，没有这么多金币，便试图寻找优惠活动。“麻花藤”说："嗯，如果你能够替我弄到“马勇”（手游内置NPC）的二级甲碎片，我可以只要8000金币。。如果你能够弄来他的三级甲碎片，那么只要5000金币就行了。小蓝鲸便去寻找二级甲/三级甲碎片，“马勇”要他用金币来换，或者替他弄来其他的东西，他可以降低价格。小蓝鲸于是又跑到其他地方，其他人也提出了类似的要求，或者直接用金币换，或者找到其他东西就可以降低价格。小蓝鲸现在很需要你的帮忙，让他用最少的金币买到喜欢的衣服。另外他要告诉你的是，在这个游戏体系，等级观念十分森严。地位差距超过一定限制的两个人之间不会进行任何形式的直接接触，包括交易。因为他是氪金大佬，所以可以不受这些限制。但是如果他和某个地位较低的人进行了交易，地位较高的的人不会再和他交易，他们认为这样等于是间接接触，反过来也一样。因此你需要在考虑所有的情况以后给他提供一个最好的方案。 为了方便起见，我们把所有的物品从1开始进行编号，食堂阿姨的菜也看作一个物品，并且编号总是1。每个物品都有对应的价格P，主人的地位等级L，以及一系列的替代品Ti和该替代品所对应的"优惠"Vi。如果两人地位等级差距超过了M，就不能"间接交易"。你必须根据这些数据来计算出小蓝鲸现最少需要多少金币才能买到衣服。

输入格式

输入第一行是两个整数M，N（1 <= N <= 100），依次表示地位等级差距限制和物品的总数。接下来按照编号从小到大依次给出了N个物品的描述。每个物品的描述开头是三个非负整数P、L、X（X < N），依次表示该物品的价格、主人的地位等级和替代品总数。接下来X行每行包括两个整数T和V，分别表示替代品的编号和"优惠价格"。

输出格式

输出最少需要的金币数。

输入样例1
1 4
10000 3 2
2 8000
3 5000
1000 2 1
4 200
3000 2 1
4 200
50 2 0

输出样例1
5250

限制
•时间限制：1s
•内存限制：64MB

样例解释

圆圈内为物体编号， 边上的为“优惠后的价格”，黄色数字为“主人的地位等级”， 样例最优解为：买一个4花费50，然后用4花费200买3，然后用3花费5000买1，(1)为所要的物品，答案就是50+200+5000=5250

*/
/*
#include<iostream>
//#include<string>

using namespace std;

const int MAX_N = 101;

int M, N;

struct Goods {
	int p, l, x;
	Goods() { p = l = x = 0; }
	Goods(int a, int b, int c) {
		p = a, l = b, x = c;
	}
}goods[MAX_N];

struct Edge {
	int u, v;
	int w;
	int nxt;
}path[MAX_N * MAX_N];

int ans;

int cnt = 1;

int pre[MAX_N];

bool visited[MAX_N];

int my_abs(int x) {
	return (x < 0) ? -x : x;
}

void dfs(int index, int max_lv_last, int min_lv_last, int cur_ans) {
	if (goods[index].p + cur_ans < ans)
		ans = goods[index].p + cur_ans;
	if (pre[index] == 0) //get to the target then return
		return;
	for (int i = pre[index]; i != 0; i = path[i].nxt) { //search from the last goods to the first one
		int v = path[i].v;
		int w = path[i].w;
		if (visited[v] || my_abs(goods[v].l - max_lv_last) > M || my_abs(goods[v].l - min_lv_last) > M)
			continue; //v is visited or level of v is too low or too high

		int max_lv, min_lv;
		if (index != 1)
			w += cur_ans;
		if (max_lv_last < goods[v].l)
			max_lv = goods[v].l;
		else max_lv = max_lv_last;
		if (min_lv_last > goods[v].l)
			min_lv = goods[v].l;
		else min_lv = min_lv_last;

		visited[v] = 1;

		dfs(v, max_lv, min_lv, w);
		visited[v] = 0; //find other possible answers(huisu)
	}
}

void solution_3() {
	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		int p, l, x; cin >> p >> l >> x;
		goods[i] = Goods(p, l, x);

		for (int j = 0; j < goods[i].x; j++) {
			int next, price;
			cin >> next >> price;
			path[cnt].u = i;
			path[cnt].v = next;
			path[cnt].w = price;
			path[cnt].nxt = pre[i];
			pre[i] = cnt;
			cnt++;
		}
	}

	ans = goods[1].p;
	visited[1] = true;

	dfs(1, goods[1].l, goods[1].l, ans);

	cout << ans << endl;
	return;
}

int main() {
	solution_3();
	return 0;
}
*/