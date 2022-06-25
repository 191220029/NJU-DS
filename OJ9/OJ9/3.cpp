/*
���޵����Ĺ���

��������

ÿ��Ժ¥¥�׵���󵥳�����Ϊһ��ż�� cmax
cmax
 �����һ����վ�������г�������ǡ��Ϊ cmax2
cmax2
����ô�ƴ�������״̬�����һ��¥�׵������������ģ��� cmax
cmax
 �������߿յģ�û�г������������������ڽ��0�����ͻ�Я�����ߴ�·���ռ�һ�������ĵ���ǰ����Ժ¥����;�������е�Ժ¥¥�׵ĵ��������ﵽ������

���ڸ��� cmax
cmax
��Ժ¥������ n
n
������Ժ¥��� sp
sp
��m
m
 ��Ժ¥֮���Ժ¥�͵�������֮���·��·���������·����

Ժ¥�±��Ǵ�1��ʼ�ģ����0�ǵ��������� 1������ж�����·�������ܴ������ٵ����г���Ŀ����������0����������ҪЯ�������ٵģ�ʹ����;���г�վ�������� 2������кܶ಻ͬ·����һ����վ���ص����г���Ŀ���ٵģ���;����վ��������״̬����Ҫ�� sp
sp
 ��վ������Ŀ���ٵģ�

�����ʽ

��һ�У������������ cmax(<=100)
cmax(<=100)
��Ժ¥������ n(<=500)
n(<=500)
������Ժ¥��� sp
sp
��Ժ¥��·������ m
m


�ڶ��У�n
n
 ����վ�����е�����

������ m
m
 �У�����Ժ¥���·����

�����ʽ

���Я���ĵ������������·�������صĵ�������

��������

����1

���룺
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

9-3.jpg

�����
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