/*
哈罗单车的管理

问题描述

每个院楼楼底的最大单车容量为一个偶数 cmax
cmax
 ，如果一个车站里面自行车的数量恰好为 cmax2
cmax2
，那么称处于完美状态。如果一个楼底单车容量是满的（有 cmax
cmax
 辆）或者空的（没有车），单车管理处（处于结点0处）就会携带或者从路上收集一定数量的单车前往该院楼，沿途会让所有的院楼楼底的单车量都达到完美。

现在给出 cmax
cmax
，院楼的数量 n
n
，问题院楼编号 sp
sp
，m
m
 条院楼之间和院楼和单车管理处之间的路和路长，求最短路径。

院楼下标是从1开始的，结点0是单车管理处。 1）如果有多个最短路径，求能带的最少的自行车数目的那条（从0结点出发，需要携带的最少的，使得沿途所有车站都完美） 2）如果有很多不同路，找一个车站带回的自行车数目最少的（沿途各车站处于完美状态后，需要从 sp
sp
 车站带回数目最少的）

输入格式

第一行，给出最大容量 cmax(<=100)
cmax(<=100)
，院楼的数量 n(<=500)
n(<=500)
，问题院楼编号 sp
sp
，院楼间路的数量 m
m


第二行，n
n
 个车站的现有单车数

接下来 m
m
 行，给出院楼间的路径长

输出格式

最初携带的单车数量，最短路径，带回的单车数量

输入样例

样例1

输入：
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

9-3.jpg

输出：
3 0->2->3 0

*/
/*
#include<iostream>
#include <assert.h>
using namespace std;
typedef long long ll;
struct e {
	ll x;
	ll y;
}edge[1000];
int path[1000][1000];
int road[1000], back[1000], out[1000], dis[1000], bike[1000];
int n, sp;

void dijkstra() {
	dis[sp] = 0;
	bool visit[1000];
	for (int i = 0; i <= n; i++) {
		if (i == sp) continue;
		dis[i] = path[sp][i];
		road[i] = sp;
		visit[i] = false;
		out[i] = out[sp] - bike[i];
		back[i] = back[sp] + bike[i];
	}
	visit[sp] = true;
	for (int i = 0; i <= n; i++) {
		int minv = 2147483647, minb = 2147483647, mino = 2147483647;
		int u = 0;
		for (int j = 0; j <= n; j++)
			if (!visit[j] && ((dis[j] < minv) || (dis[j] == minv && out[j] < mino) || (dis[j] == minv && out[j] == mino && back[j] < minb))) {
				u = j;
				minv = dis[j];
				mino = out[j];
				minb = back[j];
			}
		visit[u] = true;
		for (int k = 0; k <= n; k++) {
			int w = path[u][k];
			if (!visit[k] && w < 2147483647 && dis[u] + w < dis[k]) {
				dis[k] = dis[u] + w;
				road[k] = u;
				out[k] = out[u] - bike[k];
				back[k] = back[u] + bike[k];
			}
			else if (!visit[k] && w<2147483647 && dis[u] + w == dis[k] && out[k]>out[u] - bike[k]) {
				dis[k] = dis[u] + w;
				road[k] = u;
				out[k] = out[u] - bike[k];
				back[k] = back[u] + bike[k];
			}
			else if (!visit[k] && w<2147483647 && dis[u] + w == dis[k] && out[k] == out[u] - bike[k] && back[k]>back[u] + bike[k]) {
				dis[k] = dis[u] + w;
				road[k] = u;
				out[k] = out[u] - bike[k];
				back[k] = back[u] + bike[k];
			}
			if (out[k] < 0) out[k] = 0;
			if (back[k] < 0) back[k] = 0;
		}
	}

}

void dfs(int now) {
	if (now == sp) {
		return;
	}
	cout << now << "->";
	dfs(road[now]);
}
int main() {
	int cmax, m;
	cin >> cmax >> n >> sp >> m;
	bike[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> bike[i];
		bike[i] -= cmax / 2;
	}
	//assert(bike[sp] == cmax/2);
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			if (i == j) path[i][j] = 0;
			else path[i][j] = 2147483647;

	for (int i = 0; i < m; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		path[x][y] = t;
		path[y][x] = t;
	}

	if (cmax / 2 == bike[sp]) {
		out[sp] = -cmax / 2;
		back[sp] = cmax / 2;
	}
	else {
		out[sp] = cmax / 2;
		back[sp] = -cmax / 2;
	}
	dijkstra();
	//cout<<dis[0];
	//assert(!(bike[sp] == cmax/2 && out[0] < 0)); 
	if (out[0] < 0) out[0] = 0;
	printf("%d ", out[0]);
	dfs(0);
	if (back[0] < 0) back[0] = 0;
	printf("%d %d", sp, back[0]);
	return 0;
}
*/

/*

#include<iostream>
#include<string>
using namespace std;

const int MAX_EDGE = 1000;
const int MAX_WEIGHT = 0x7fffffff;

struct Edge {
    long long x;
    long long y;
}edge[MAX_EDGE];

int path[MAX_EDGE][MAX_EDGE]; //weight of edge
int road[MAX_EDGE], num_back[MAX_EDGE], num_out[MAX_EDGE], dis[MAX_EDGE], bike[MAX_EDGE];
//road[i]: path from 0 to node(i)
//num_back: num of bikes should take back
//num_out: num of bikes should bring out
//dis[i]: min distance from 0 to node(i)
//bike[i]: number of bikes should take from or bring to node(i)
int n, sp;

void Dijkstra() {
    bool visited[MAX_EDGE];
    dis[sp] = 0;
    for (int i = 0; i <= n; i++) {
        if (i == sp)continue;
        dis[i] = path[sp][i];
        road[i] = sp;
        visited[i] = false;
        num_out[i] = num_out[sp] - bike[i];
        num_back[i] = num_back[sp] + bike[i];
    }
    visited[sp] = true;
    for (int i = 0; i <= n; i++) {
        int minv = MAX_WEIGHT, minb = MAX_WEIGHT, mino = MAX_WEIGHT;
        int u = 0;
        for (int j = 0; j <= n; j++) {
            if (!visited[j] && ((dis[j] < minv) || (dis[j] == minv && num_out[j] < mino) || (dis[j] == minv && num_out[j] == mino && num_back[j] < minb))) {
                u = j;
                minv = dis[j];
                mino = dis[j];
                minb = num_back[j];
            }
        }
        visited[u] = true;
        for (int k = 0; k <= n; k++) {
            int w = path[u][k];
            if (!visited[k] && w < MAX_WEIGHT && dis[u] + w < dis[k]) { //shorter path
                dis[k] = dis[u] + w;
                road[k] = u;
                num_out[k] = num_out[u] - bike[k];
                num_back[k] = num_back[u] + bike[k];
            }
            else if (!visited[k] && w < MAX_WEIGHT && dis[u] + w == dis[k] && num_out[k] > num_out[u] - bike[k]) { //fewer bikes bring out
                dis[k] = dis[u] + w;
                road[k] = u;
                num_out[k] = num_out[u] - bike[k];
                num_back[k] = num_back[u] + bike[k];
            }
            else if (!visited[k] && w < MAX_WEIGHT && dis[u] + w == dis[k] && num_out[k] == num_out[u] - bike[k] && num_back[k] > num_back[u] + bike[k]) { // fewer bikes take back
                dis[k] = dis[u] + w;
                road[k] = u;
                num_out[k] = num_out[u] - bike[k];
                num_back[k] = num_back[u] + bike[k];
            }
            if (num_out[k] < 0)num_out[k] = 0;
            if (num_back[k] < 0)num_back[k] = 0;
        }
    }
}

void dfs(int curIndex) {
    if (curIndex == sp) {
        return;
    }
    cout << curIndex << "->";
    dfs(road[curIndex]);
}

void init_path() {
    for (int i = 0; i < MAX_EDGE; i++) {
        for (int j = 0; j < MAX_EDGE; j++) {
            path[i][j] = (i == j) ? 0 : MAX_WEIGHT;
        }
    }
    return;
}

void solution_3() {
    int cmax, m;
    cin >> cmax >> n >> sp >> m;
    bike[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> bike[i];
        bike[i] -= cmax / 2;
    }
    init_path();
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        path[x][y] = path[y][x] = w;
    }

    if (bike[sp] == cmax / 2) {
        num_out[sp] = -cmax / 2;
        num_back[sp] = cmax / 2;
    }
    else {
        num_out[sp] = cmax / 2;
        num_back[sp] = -cmax / 2;
    }
    Dijkstra();
    if (num_out[0] < 0) num_out[0] = 0;
    cout << num_out[0] << ' ';
    dfs(0);
    if (num_back[0] < 0)num_back[0] = 0;
    cout << sp << ' ' << num_back[0];
    cout << endl;
    return;
}

int main() {
    solution_3();
    return 0;
}

*/