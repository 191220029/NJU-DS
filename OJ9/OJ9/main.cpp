#include<iostream>
#include<string>
using namespace std;

const int MAX_EDGE = 1000;
const int MAX_WEIGHT = 0x7fffffff;


int road[MAX_EDGE][MAX_EDGE], path[MAX_EDGE][MAX_EDGE], dis[MAX_EDGE], bike[MAX_EDGE];
//road**
//road[i][0]: num of shortest paths from node(i) to sp(or from sp to the start)
//road[i][j](j>0):the j path's next node to sp
//path** weight of edge
//dis[i]: min distance from sp to node(i)
//bike[i]: number of bikes should take back at node(i) (if it is negative, it means need to bring bikes to this node)
int n, sp;

int m, cmax;

int min_out = MAX_WEIGHT, min_in = MAX_WEIGHT;
//min number of bikes should bring out or take back of all possible paths

string res = "";
//the answer

void init_dis(bool* visited) {
    for (int i = 0; i <= n; i++) {
        dis[i] = path[sp][i];
        if (dis[i] != MAX_WEIGHT) {
            road[i][0] = 1;
            road[i][1] = sp;
        }
        visited[i] = false;
    }
    return;
}

void init_path() {
    for (int i = 0; i < MAX_EDGE; i++) {
        for (int j = 0; j < MAX_EDGE; j++) {
            path[i][j] = (i == j) ? 0 : MAX_WEIGHT;
        }
    }
    return;
}

void Dijkstra() {
    dis[sp] = 0; //start from node(sp)
    bool visited[MAX_EDGE];
    init_dis(visited);

    visited[sp] = true;
    for (int i = 0; i <= n; i++) {
        int u = 0;
        int min_w = MAX_WEIGHT;
        for (int j = 0; j <= n; j++) { //find shortest path from i to any node(u);
            if (!visited[j] && dis[j] < min_w) {
                u = j;
                min_w = dis[j];
            }
        }
        visited[u] = true;
        for (int j = 0; j <= n; j++) { //refresh shortest path from node(i) to any node(j) via node(u)
            int w = path[u][j];
            if (u == j || w == MAX_WEIGHT) continue;
            if (dis[u] + w < dis[j]) {
                dis[j] = dis[u] + w;
                road[j][0] = 1;
                road[j][1] = u;
            }
            else if (dis[j] == dis[u] + w) { //if there is path of same worth from node(i) to node(j), store it
                road[j][0]++;
                road[j][road[j][0]] = u;
            }
        }
    }
    return;
}

void dfs(int index, int in, int out, string s) {
    if (out + bike[index] < 0) { //if number of bikes should take back is negative, then need to bring in bikes
        in -= out + bike[index];
        out = 0;
    }
    else out += bike[index]; //else take back more bikes
    if (index == sp) { //reach destination
        //refresh final anwser (string)res if current path is better
        if (in < min_in || (in == min_in && out < min_out) || (in == min_in && out == min_out)) {
            min_in = in;
            min_out = out;
            res = s;
        }
        return;
    }
    //dfs all possible same worth paths
    for (int i = 1; i <= road[index][0]; i++) {
        dfs(road[index][i], in, out, s + "->" + to_string(road[index][i]));
    }
}

void solution_3() {
    cin >> cmax >> n >> sp >> m;
    init_path();
    //cin bike numbers
    for (int i = 1; i <= n; i++) {
        cin >> bike[i];
        bike[i] -= cmax / 2;
    }
    //cin edge
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        path[a][b] = path[b][a] = w;
    }
    Dijkstra(); //find all possible shortest paths to sp
    dfs(0, 0, 0, "0");
    cout << min_in << " " << res << " " << min_out << endl;
    return;
}

int main() {
    solution_3();
    return 0;
}
