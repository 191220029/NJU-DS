/*
狡兔三窟

狡猾的野兔通常有几个兔窝，而这些兔窝在地下可能是相通的，并且每个兔窝有且仅有一个洞口，这给猎户带来了很大的麻烦，所以猎人有时会把发现的洞口封死。

为了限制野兔的活动范围，猎人决定今天再去封死一个洞口。现给出兔窝之间的地下相连通情况与尚未封死的洞口，请你帮猎人找出封死哪个洞口才能最大程度上限制野兔的活动范围。假如多个洞口满足条件，就返回序号最小的洞口。

可以把野兔的活动范围定义为：从尚未封死的洞口可以到达的兔窝数量；并且一个兔窝在洞口被封死后并不影响该兔窝在地下的连通性。

输入格式

第一行输入为3个整数M,N,K
M,N,K
。M
M
为兔窝数量，兔窝编号为0∼M−1, M<3000
0∼M−1, M<3000


之后K
K
行输每行两个整数a,b∈[0,M−1]
a,b∈[0,M−1]
，代表兔窝a,b
a,b
在地下连通

最后一行输入为N
N
个整数，代表N
N
个尚未封死的洞口，洞口编号∈[0,M−1]
∈[0,M−1]


输出格式

一行输出，直接输出封死的洞口序号

输入样例
3 2 1
0 1
0 2

输出样例
0

说明

9-1.png

假设兔窝1洞口被封死，兔窝0洞口未封死，则野兔仍可通过兔窝0的洞口到达兔窝1,2,3，即兔窝0,1,2,3仍然连通

*/

/*

#include<iostream>
using namespace std;

const int MAX_NUM = 3000;
int parent[MAX_NUM];
bool flag[MAX_NUM]; //unblocked -> 1

int Find(int x) {
    //函数搜索并返回包含元素x的树的根
    while (x != parent[x]) {
        parent[x] = Find(parent[x]);
        x = parent[x];
    }
    return x;
};

void Union(int Root1, int Root2) {
    parent[Find(Root2)] = Find(Root1);
};

void init_parent() {
    for (int i = 0; i < MAX_NUM; i++) {
        parent[i] = i;
    }
}

int blockable(int index, int num) {
    int root = Find(index);
    int all_num = 0;    //numbers of holes in the group
    int blocked_num = 0;    //numbers of blocked holes in the group
    for (int i = 0; i < num; i++) {
        if (Find(i) == root) {
            all_num++;
            if (!flag[i]) blocked_num++;
        }
    }
    if (blocked_num == all_num - 1) {
        if (!flag[index]) return 0;
        else return all_num;
    }
    return 0;
}

void solution_1() {
    init_parent();
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) { //linked holes
        int a, b; cin >> a >> b;
        Union(a, b);
    }
    for (int i = 0; i < N; i++) { //unblocked holes
        int a; cin >> a;
        flag[a] = 1;
    }

    int index = 0;
    int max = 0;
    for (int i = 0; i < M; i++) {//find the biggest possible blocked holes
        int temp = blockable(i, M);
        if (temp > max) {
            max = temp;
            index = i;
        }
        if (!flag[index]) index = i;
    }
    cout << index << endl;
    return;
}

int main() {
    solution_1();
    return 0;
}

*/