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