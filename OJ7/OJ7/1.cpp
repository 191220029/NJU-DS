/*
小蓝鲸的城镇

小蓝鲸所在的学校开始修建校园道路。学校希望学校内任意两个建筑都能相互到达（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？

输入格式

第1行给出两个正整数，分别是建筑数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 注意:两个建筑之间可以有多条道路相通,也就是说

3 3

1 2

1 2

2 1

的输入也是可以合法的

输出格式

对每个测试用例，在1行里输出最少还需要建设的道路数目。

输入样例1
4 2
1 3
4 3

输出样例1
1

输入样例2
3 3
1 2
1 3
2 3

输出样例2
0

输入样例3
999 0

输出样例3
998

*/

/*
#include<iostream>
#include<string>
using namespace std;

#define N 1000
int Tree[N];
//查找某个结点所在树的根结点(！固定写法，牢记！！！)
int findRoot(int x) {
    if (Tree[x] == -1) return x;
    else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;//路径压缩优化
        return tmp;
    }
}

void solution_1() {
    int n, m;
    cin >> n >> m;
    //初始化Tree数组中每个元素为-1
    for (int i = 1; i <= n; i++) {
        Tree[i] = -1;
    }
    //读入边信息
    while (m > 0) {
        int a, b; cin >> a >> b;
        a = findRoot(a);
        b = findRoot(b); //查找边的两个顶点所在集合信息
        if (a != b) Tree[a] = b; //若两个顶点不在同一个集合则合并这两个集合
        m--;
    }
    int ans = 0;
    //统计所有结点中根结点的个数
    for (int i = 1; i <= n; i++) {
        if (Tree[i] == -1) ans++;
    }
    cout << ans - 1; //在ans个集合间再修建ans-1条道路即可使所有结点连通
}

int main() {
    solution_1();
    return 0;
}
*/